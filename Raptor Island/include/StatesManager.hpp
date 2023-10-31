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
		void	handleInput(void);
		void	update(void);
		void	render(void);
		enum STATES	getCurrentState(void) const;
	private:
		std::vector<GameState*> states;
};