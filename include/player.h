#ifndef PLAYER_H
#define PLAYER_H

#include "imagetotexture.h"

/**
 * @class Player
 * @brief Manages the player's ship state, including position, velocity, rotation, and input processing.
 *
 * This class is responsible for initializing the player's ship, processing input for movement and rotation, and rendering the ship on the screen.
 * 
 */
class Player
{
    public:
        /**
        * @brief Initializes the player's ship state, including position, velocity, rotation, and loading the ship texture.
        */
        void PlayerInitialize();
        /**
        * @brief Processes player input for movement and rotation, updates the ship's position and velocity, and renders the ship on the screen.
        */
        void ProcessInput();
        Texture2D playerShipTexture;
    private:
        const float dampeningFactor = 0.99f;
        const float playerAngularDampeningFactor = 0.98f;
        
        float playerAngularVelocity;
        float playerShipRotation;
        float playerShipRotationSpeed;
        float playerShipRadians;
        float playerShipThrust;

        Vector2 playerShipPosition;
        Vector2 playerShipVelocity;
        Vector2 playerShipdirection;
        Vector2 playerShipOrigin;

        Rectangle playerShipSource;
        Rectangle playerShipDest;
};

#endif