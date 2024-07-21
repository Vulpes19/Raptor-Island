#pragma once

#include "GameState.hpp"
#include <vector>

class StatesManager
{
	public:
		~StatesManager(void);
		static StatesManager* getInstance(void);
		void	addState(GameState*);
		void	removeState(void);
		void	removeState(int);
		void	handleInput(void);
		void	update(void);
		void	render(SDL_Renderer *);
		enum STATES	getCurrentState(void) const;
		GameState* StatesManager::getCurrentStateInstance(void) const;
	private:
		StatesManager(void);
		static StatesManager *instance;
		std::vector<GameState*> states;
};