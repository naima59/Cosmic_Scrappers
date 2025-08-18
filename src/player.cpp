#include "player.h"

void Player::PlayerInitialize()
{
    playerShipPosition = { screenWidth / 2.0f, screenHeight / 2.0f };
    playerShipVelocity = { 0.0f, 0.0f };
    playerShipRotation = 0.0f;
    playerShipRotationSpeed = 180.0f;
    playerShipThrust = 200.f;
    playerAngularVelocity = 0.0f;
    playerShipTexture = ImageToTexture("player_ship.png", 64, 64);

    thrusterTexture = ImageToTexture("thruster_spritesheet.png", 64, 32);
    thrusterFrameCount = 4;
    thrusterFrameWidth = thrusterTexture.width / thrusterFrameCount;
    thrusterFrameHeight = thrusterTexture.height;
    thrusterOrigin = { thrusterFrameWidth / 2.0f, thrusterFrameHeight / 2.0f };
    thrusterOffset = { -45, 0.f }; // tweak this to position flame behind ship

}

void Player::UpdatePhysics(float deltaTime)
{
    playerShipPosition.x += playerShipVelocity.x * deltaTime;
    playerShipPosition.y += playerShipVelocity.y * deltaTime;
    
    playerAngularVelocity *= playerAngularDampeningFactor;
    playerShipVelocity.x *= dampeningFactor;
    playerShipVelocity.y *= dampeningFactor;
    playerShipRotation += playerAngularVelocity * deltaTime;

    playerShipSource = { 0, 0, (float)playerShipTexture.width, (float)playerShipTexture.height };
    playerShipDest = { playerShipPosition.x, playerShipPosition.y, playerShipSource.width, playerShipSource.height};
    playerShipOrigin = { playerShipSource.width / 2.0f, playerShipSource.height / 2.0f };

    if (isThrusting)
    {
        thrusterAnimTimer += GetFrameTime();
        if (thrusterAnimTimer >= thrusterAnimSpeed)
        {
            thrusterAnimTimer = 0.0f;
            currentThrusterFrame = (currentThrusterFrame + 1) % thrusterFrameCount;
        }

        thrusterSource = {currentThrusterFrame * thrusterFrameWidth,0,thrusterFrameWidth,thrusterFrameHeight
        };

        // Position thruster behind ship using offset and rotation
        float radians = playerShipRotation * DEG2RAD;
        Vector2 rotatedOffset = {thrusterOffset.x * cosf(radians) - thrusterOffset.y * sinf(radians),thrusterOffset.x * sinf(radians) + thrusterOffset.y * cosf(radians)};
        thrusterDest = {playerShipPosition.x + rotatedOffset.x,playerShipPosition.y + rotatedOffset.y,thrusterFrameWidth * thrusterScale,thrusterFrameHeight * thrusterScale};
    }
}

void Player::ProcessInput()
{
    isThrusting = false;
    float deltaTime = GetFrameTime();
    if (IsKeyDown(KEY_A)) 
    {
        playerShipRotation -= playerShipRotationSpeed * deltaTime;

    }
    if (IsKeyDown(KEY_D)) 
    {
        playerShipRotation += playerShipRotationSpeed * deltaTime;

    }
    if (IsKeyDown(KEY_W)) 
    {
        playerShipRadians = playerShipRotation * DEG2RAD;
        playerShipVelocity.x += cosf(playerShipRadians) * playerShipThrust * deltaTime;
        playerShipVelocity.y += sinf(playerShipRadians) * playerShipThrust * deltaTime;
        isThrusting = true;
    }
    if (IsKeyDown(KEY_SPACE)) 
    {
        playerShipVelocity.x *= 0.97f;
        playerShipVelocity.y *= 0.97f;
    }

    UpdatePhysics(deltaTime);

    DrawTexturePro(playerShipTexture, playerShipSource, playerShipDest, playerShipOrigin, playerShipRotation - 90.f, WHITE);
    if (isThrusting)
    {
        DrawTexturePro(thrusterTexture,thrusterSource,thrusterDest,thrusterOrigin, playerShipRotation - 90.f, WHITE);
    }

}