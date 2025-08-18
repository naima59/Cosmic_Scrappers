#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "game.h"

/**
 * @class GameState
 * @brief Manages the game state and transitions between scenes.
 *
 * This class is responsible for tracking bool states, 
 * such as whether the game is initialized or if the game is over.
 */

class GameState
{
public:
    /**
     * @brief Manages the current scene of the game.
     */
    void SceneManager();
private:
    Game game;
};

#endif