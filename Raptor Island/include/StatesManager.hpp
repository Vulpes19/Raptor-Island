#pragma once

#include "GameState.hpp"
#include <vector>

class StatesManager
{
	public:
		StatesManager(void);
		~StatesManager(void);
		void	addState(GameState*);
		void	removeState(void);
		enum STATES	getCurrentState(void) const;
		void	handleInput(void);
		void	update(void);
		void	render(void);
	private:
		std::vector<GameState*> states;
};