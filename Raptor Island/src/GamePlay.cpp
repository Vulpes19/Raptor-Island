#include "GamePlay.hpp"

GamePlay::GamePlay(InputManager *input, SDL_Renderer *renderer)
{
	stateName = GamePlayState;
	player = factory.createGameObject(TYPES::PLAYER, "player", "C:/Users/asus/source/repos/Raptor Island/assets/textures/player.png", renderer);

	std::cout << "im in constructor gameplay" << std::endl;
	//add player as an observer to input
	InputObserver* playerObserver = dynamic_cast<InputObserver*>(player);
	if (playerObserver)
		input->addObserver(playerObserver);
	else
		throw(ErrorHandler("Can't cast player to an observer, causes the input to not work: ", __FILE__, __LINE__));
	//creating level
	level = new Level(renderer);
	level->generateLevel("test", "C:/Users/asus/source/repos/Raptor Island/assets/levels/level_test.txt");

	//adding level as an observer to collision
	Player *playerCollider = dynamic_cast<Player*>(player);
	if (playerCollider)
		playerCollider->addCollisionObserver(level);
	else
		throw(ErrorHandler("casting error, causes the collision to not work: ", __FILE__, __LINE__));
}

GamePlay::~GamePlay(void)
{}

void	GamePlay::keyDown(SDL_Scancode key, double deltaTime, InputManager* input, SDL_Renderer* renderer)
{
	if (InputDetector::getInstance()->isKeyPressed(key) && StatesManager::getInstance()->getCurrentState() == GamePlayState)
	{
		if (key == SDL_SCANCODE_ESCAPE && StatesManager::getInstance()->getCurrentState() != PauseMenuState)
		{
			StatesManager::getInstance()->addState(new PauseMenu());
			InputObserver* pauseObserver = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
			if (pauseObserver)
				input->addObserver(pauseObserver);
			else
				throw(ErrorHandler("Can't cast state to an observer, causes the input to not work: ", __FILE__, __LINE__));
		}
	}
}

void	GamePlay::mouseMove(Uint8 mouseButton, InputManager* input, SDL_Renderer* renderer)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	
}

void	GamePlay::handleInput(void)
{

}

void	GamePlay::update(void)
{
	level->update();
	player->update(0);
}

void	GamePlay::render(SDL_Renderer *renderer)
{
	level->render(renderer);
	player->render(renderer);
}

