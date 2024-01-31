#include "StatesManager.hpp"

StatesManager* StatesManager::instance = nullptr;

StatesManager* StatesManager::getInstance(void)
{
	if (instance == nullptr)
		instance = new StatesManager();
	return (instance);
}

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
	if (states.empty())
		return (NoState);
	else
		return (states.back()->getStateName());
}

GameState	*StatesManager::getCurrentStateInstance(void) const
{
	return (states.back());
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