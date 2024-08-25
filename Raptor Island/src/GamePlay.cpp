#include "GamePlay.hpp"

GamePlay::GamePlay(InputManager *input, SDL_Renderer *renderer)
{
	stateName = GamePlayState;

	std::cout << "im in constructor gameplay" << std::endl;
	//creating level
	level = new Level(renderer);
	levelPosData positions = level->generateLevel(
		"test", 
		"C:/Users/asus/source/repos/Raptor Island/assets/levels/level_test.txt");

	//creating player
	player = factory.createGameObject(
		TYPES::PLAYER, 
		"player", 
		positions.playerPosition,
		"C:/Users/asus/source/repos/Raptor Island/assets/textures/player.png", 
		renderer);
	//add player as an observer to input
	InputObserver* playerObserver = dynamic_cast<InputObserver*>(player);
	if (playerObserver)
		input->addObserver(playerObserver);
	else
		throw(ErrorHandler("Can't cast player to an observer, causes the input to not work: ", __FILE__, __LINE__));
	
	//spawning enemies
	for (unsigned int nbr = 0; nbr < 3; nbr++)
	{
		if (!positions.raptorSpawnPoints.empty())
		{
			unsigned int randomIndex = rand() % positions.raptorSpawnPoints.size();

			Vector spawnPosition = positions.raptorSpawnPoints[randomIndex];
			spawnPosition.setX(spawnPosition.getX() * 64);
			spawnPosition.setY(spawnPosition.getY() * 64);
			GameObject* enemy = factory.createGameObject(
				TYPES::RAPTOR,
				"Raptor " + std::to_string(nbr),
				spawnPosition,
				"C:/Users/asus/source/repos/Raptor Island/assets/textures/brown.png",
				renderer,
				positions.patrolWayPoints);
			Enemy* enemyCollider = dynamic_cast<Enemy*>(enemy);
			if (enemyCollider)
				enemyCollider->addCollisionObserver(level);
			else
				throw(ErrorHandler("casting error, causes the collision to not work: ", __FILE__, __LINE__));
			raptors.push_back(enemy);
			positions.raptorSpawnPoints.erase(positions.raptorSpawnPoints.begin() + randomIndex);
		}
	}
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

	//to add pause mouse click
	
}

void	GamePlay::handleInput(void)
{

}

void	GamePlay::update(void)
{
	level->update();
	player->update(0);
	//enemies
	for (auto enemy : raptors)
		enemy->update(0);
}

void	GamePlay::render(SDL_Renderer *renderer)
{
	level->render(renderer);
	player->render(renderer);
	//enemies
	for (auto enemy : raptors)
		enemy->render(renderer);
}

