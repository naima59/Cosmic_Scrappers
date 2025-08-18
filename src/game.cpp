#include "game.h"

void Game::Initialize()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    SetTargetFPS(60);
	SearchAndSetResourceDir("resources");
    backgroundTexture = ImageToTexture("background_space.png", screenWidth, screenHeight);
    textures.push_back(backgroundTexture);
    player.PlayerInitialize();
    textures.push_back(player.playerShipTexture);
    isInitialized = true;
}

void Game::ProcessInput()
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    player.ProcessInput();

    EndDrawing();
}

void Game::UnloadGame()
{
    for(int i = 0; i < textures.size(); i++)
    {
        UnloadTexture(textures[i]);
    }    
    CloseWindow();
}