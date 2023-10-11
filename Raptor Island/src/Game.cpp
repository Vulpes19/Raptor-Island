#include "Game.hpp"

Game::Game(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		throw(ErrorHandler("SDL failed to initialise: " + std::string(SDL_GetError()), __FILE__, __LINE__));

	window = SDL_CreateWindow("Raptor Island",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIDTH,
		HEIGHT,
		0);
	if (window == NULL)
		throw(ErrorHandler("SDL window failed to initialise: " + std::string(SDL_GetError()), __FILE__, __LINE__));

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL)
		throw(ErrorHandler("SDL renderer failed to initialise: " + std::string(SDL_GetError()), __FILE__, __LINE__));
	running = true;
	input = new InputManager();
	player = factory.createGameObject(TYPES::PLAYER, "player", "C:/Users/asus/source/repos/Raptor Island/assets/textures/test_player.png", renderer);
	InputObserver* playerObserver = dynamic_cast<InputObserver*>(player);
	if (playerObserver)
		input->addObserver(playerObserver);
	else
		throw(ErrorHandler("Can't cast player to an observer, causes the input to not work: ", __FILE__, __LINE__));
	prevTime = Clock::now();
}

Game::~Game(void)
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void	Game::handleInput(void)
{
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			running = false;
		if (event.type == SDL_KEYDOWN)
			input->notifyOnKeyDown(event.key.keysym.scancode, deltaTime);
	}
}

void	Game::render(void)
{
	SDL_RenderClear(renderer);
	player->render(renderer);
	SDL_RenderPresent(renderer);
}

void	Game::update(void)
{
	player->update(deltaTime);
}

bool	Game::isRunning(void) const
{
	return (running);
}

void	Game::updateDeltaTime(void)
{
	currTime = Clock::now();
	std::chrono::duration<double> duration = currTime - prevTime;
	deltaTime = duration.count();
	prevTime = Clock::now();
}