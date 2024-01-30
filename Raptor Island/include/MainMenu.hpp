#pragma once

#include "GameState.hpp"
#include "InputObserver.hpp"
#include "InputDetector.hpp"
#include "StatesManager.hpp"
#include "LevelMenu.hpp"

class MainMenu : public GameState, public InputObserver
{
	public:
		MainMenu(void);
		~MainMenu(void);
		void handleInput(void) override;
		void keyDown(SDL_Scancode, double) override;
		void mouseMove(void) override;
		void update(void) override;
		void render(SDL_Renderer *) override;
	private:
		std::map<std::string, BUTTON_STATE> buttonsState;
};