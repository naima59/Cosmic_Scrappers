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
}

void Player::ProcessInput()
{
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
    }


    playerShipPosition.x += playerShipVelocity.x * deltaTime;
    playerShipPosition.y += playerShipVelocity.y * deltaTime;
    
    playerAngularVelocity *= playerAngularDampeningFactor;
    playerShipVelocity.x *= dampeningFactor;
    playerShipVelocity.y *= dampeningFactor;
    playerShipRotation += playerAngularVelocity * deltaTime;

    playerShipSource = { 0, 0, (float)playerShipTexture.width, (float)playerShipTexture.height };
    playerShipDest = { playerShipPosition.x, playerShipPosition.y, playerShipSource.width, playerShipSource.height };
    playerShipOrigin = { playerShipSource.width / 2.0f, playerShipSource.height / 2.0f };

    DrawTexturePro(playerShipTexture, playerShipSource, playerShipDest, playerShipOrigin, playerShipRotation + 90.f, WHITE);
}