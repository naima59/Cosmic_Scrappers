#ifndef GAME_H
#define GAME_H
#include "player.h"

/**
 * @class Game
 * @brief Manages the game logic, including initialization, input processing, and resource management.
 *
 * This class is responsible for initializing the game, processing player input, and managing game resources such as textures.
 * 
 */
class Game
{
public:
    /**
     * @brief Initializes the game settings, including window configuration and player ship.
     */
    void Initialize();
    /**
     * @brief Processes player input and updates the game state.
     */
    void ProcessInput();
    /**
     * @brief Unloads game resources and closes the window.
     */
    void UnloadGame();
    bool isInitialized = false;
    bool isGameOver = false;
    
private:
    std::vector<Texture2D> textures;
    Player player;

};


#endif