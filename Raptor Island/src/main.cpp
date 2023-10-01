
#include "Game.hpp"

int main(int ac, char **av)
{
	SDL_SetMainReady();

	Game* game = new Game();

	while (game->isRunning())
	{
		game->handleInput();
		game->update();
		game->render();
	}
	return 0;
}
