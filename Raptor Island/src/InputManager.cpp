#include "InputManager.hpp"

InputManager::InputManager(void)
{}

InputManager::~InputManager(void)
{}

void	InputManager::addObserver(InputObserver* newObserver)
{
	observers.push_back(newObserver);
}

void	InputManager::eraseObserver(InputObserver* observer)
{
	std::cout << "before : observers nbr " << observers.size() << std::endl;
	auto it = std::find(observers.begin(), observers.end(), observer);
	observers.erase(it);
	std::cout << "after : observers nbr " << observers.size() << std::endl;
}

void	InputManager::notifyOnKeyDown(SDL_Scancode key, double deltaTime, SDL_Renderer *renderer)
{
	for (auto observer : observers)
	{
		if (observer)
			observer->keyDown(key, deltaTime, this, renderer);
	}
}

void	InputManager::notifyOnMouseMove(Uint8 mouseButton, SDL_Renderer* renderer)
{
	for (auto observer : observers)
	{
		GameState* state = dynamic_cast<GameState*>(observer);
		if (!state)
			continue;
		observer->mouseMove(mouseButton, this, renderer);
	}
}
