#include "game.h"

void Game::Initialize()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    SetTargetFPS(60);
	SearchAndSetResourceDir("resources");
    player.PlayerInitialize();
    textures.push_back(player.playerShipTexture);
    isInitialized = true;
}

void Game::ProcessInput()
{
    BeginDrawing();
    ClearBackground(BLACK);
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