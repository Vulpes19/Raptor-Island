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
	auto it = std::find(observers.begin(), observers.end(), observer);
	observers.erase(it);
}

void	InputManager::notifyOnKeyDown(SDL_Scancode key, double deltaTime, SDL_Renderer *renderer)
{
	for (auto observer : observers)
		observer->keyDown(key, deltaTime, this, renderer);
}

void	InputManager::notifyOnMouseMove(Uint8 mouseButton, SDL_Renderer* renderer)
{
	for (auto observer : observers)
		observer->mouseMove(mouseButton, this, renderer);
}
