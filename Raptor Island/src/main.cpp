#include "Game.hpp"

int main(int ac, char **av)
{
	SDL_SetMainReady();
	srand(time(0));
	try
	{
		Game* game = new Game();

		while (game->isRunning())
		{
			game->updateDeltaTime();
			game->handleInput();
			game->update();
			game->render();
		}
	}
	catch (const ErrorHandler &e)
	{
		std::cerr << e.what() << " - " << "in file: " << e.getFile() << " line: " << e.getLine() << std::endl;
	}
	return 0;
}
