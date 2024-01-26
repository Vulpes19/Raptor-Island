#include "StatesManager.hpp"

StatesManager::StatesManager(void)
{}

StatesManager::~StatesManager(void)
{}

void	StatesManager::addState(GameState* state)
{
	states.push_back(state);
}

void	StatesManager::removeState(void)
{
	if (!states.empty())
	{
		delete states.back();
		states.pop_back();
	}
}

enum STATES	StatesManager::getCurrentState(void) const
{
	return (states.back()->getStateName());
}

void	StatesManager::handleInput(void)
{
	if (!states.empty())
	{
		states.back()->handleInput();
	}
}

void	StatesManager::update(void)
{
	if (!states.empty())
	{
		states.back()->update();
	}
}

void	StatesManager::render(SDL_Renderer *renderer)
{
	if (!states.empty())
	{
		states.back()->render(renderer);
	}
}