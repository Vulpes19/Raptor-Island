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

	//init game stuff
	running = true;
	FontManager::getInstance()->loadFonts();
	input = new InputManager();
	StatesManager::getInstance()->addState(new MainMenu());
	InputObserver* stateObserver = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
	if (stateObserver)
		input->addObserver(stateObserver);
	else
		throw(ErrorHandler("Can't cast state to an observer, causes the input to not work: ", __FILE__, __LINE__));
	/*player = factory.createGameObject(TYPES::PLAYER, "player", "C:/Users/asus/source/repos/Raptor Island/assets/textures/test_player.png", renderer);

	//add player as an observer to input
	InputObserver* playerObserver = dynamic_cast<InputObserver*>(player);
	if (playerObserver)
		input->addObserver(playerObserver);
	else
		throw(ErrorHandler("Can't cast player to an observer, causes the input to not work: ", __FILE__, __LINE__));
	prevTime = Clock::now();

	//creating level
	level = new Level(renderer);
	level->generateLevel("test", "C:/Users/asus/source/repos/Raptor Island/assets/levels/level_test.txt");

	//adding level as an observer to collision
	Player *testPlayer = dynamic_cast<Player*>(player);
	if (testPlayer)
		testPlayer->addCollisionObserver(level);
	else
		throw(ErrorHandler("casting error, causes the collision to not work: ", __FILE__, __LINE__));
	*/
}

Game::~Game(void)
{
	delete input;
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void	Game::handleInput(void)
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				input->notifyOnKeyDown(event.key.keysym.scancode, deltaTime, renderer);
				break;
			case SDL_MOUSEMOTION:
				input->notifyOnMouseMove(0, renderer);
			case SDL_MOUSEBUTTONDOWN:
				input->notifyOnMouseMove(event.button.button, renderer);
		}
	}
}

void	Game::render(void)
{
	SDL_RenderClear(renderer);
	STATES currentState = StatesManager::getInstance()->getCurrentState();
	StatesManager::getInstance()->render(renderer);
	SDL_RenderPresent(renderer);
}

void	Game::update(void)
{
	if (StatesManager::getInstance()->getCurrentState() == NoState)
	{
		TextureManager::clean();
		FontManager::clean();
		running = false;
	}
	StatesManager::getInstance()->update(deltaTime);
	//player->update(deltaTime);
}

bool	Game::isRunning(void) const
{
	return (running);
}

void	Game::updateDeltaTime(void)
{
	currTime = SDL_GetTicks();
	deltaTime = (currTime - prevTime) / 1000.0;
	prevTime = currTime;
}