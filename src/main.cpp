#include "gamestate.h"

int main ()
{	
	GameState gameState;
	Game game;
	InitWindow(1920	, 1080, "Cosmic Scrappers");

	while (!WindowShouldClose())
	{
		gameState.SceneManager();
	}

	return 0;
}
