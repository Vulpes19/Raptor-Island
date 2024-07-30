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
	std::cout << "adding state " << state->getStateName() << " " << states.size() << std::endl;
	states.push_back(state);
	std::cout << "after adding " << states.size() << std::endl;
}

void	StatesManager::removeState(InputManager *input)
{
	if (!states.empty())
	{
		std::cout << "states number " << states.size() << std::endl;
		InputObserver* observer = dynamic_cast<InputObserver*>(states.back());
		if (observer) {
			input->eraseObserver(observer);
		}
		delete states.back();
		states.pop_back();
		std::cout << "states number " << states.size() << std::endl;

		std::cout << states.back()->getStateName() << std::endl;
	}
}

void	StatesManager::removeState(int n, InputManager *input)
{
	for (int i = 0; i < n; i++)
		removeState(input);
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