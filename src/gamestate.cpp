#include "gamestate.h"

void GameState::SceneManager()
{
    if(!game.isInitialized)
    {
        game.Initialize();
    }
    else if (!game.isGameOver) 
    {
        game.ProcessInput();
    }
    else
    {
        game.UnloadGame();
    }
}
