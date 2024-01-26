#pragma once

#include "GameState.hpp"

class MainMenu : public GameState
{
	public:
		MainMenu(void);
		~MainMenu(void);
		void handleInput(void) override;
		void update(void) override;
		void render(SDL_Renderer *) override;
};