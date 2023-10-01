#pragma once

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
		virtual void	handleInput(void) = 0;
		virtual void	update(void) = 0;
		virtual void	render(void) = 0;
		enum STATES		getStateName(void) const { return (stateName); }
	private:
		enum STATES stateName;
};