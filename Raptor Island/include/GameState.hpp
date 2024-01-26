#pragma once

#include "UILabel.hpp"

enum STATES {
	MainMenuState,
	LevelMenuState,
	GamePlayState,
	PauseMenuState,
	GameOverState
};

class GameState
{
	public:
		virtual ~GameState() {};
		virtual void	handleInput(void) = 0;
		virtual void	update(void) = 0;
		virtual void	render(SDL_Renderer *) = 0;
		enum STATES		getStateName(void) const { return (stateName); }
	protected:
		UILabel		label;
		enum STATES stateName;
};