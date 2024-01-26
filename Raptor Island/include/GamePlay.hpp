#pragma once

#include "GameState.hpp"

class GamePlay : public GameState
{
	public:
		GamePlay(void);
		~GamePlay(void);
		void handleInput(void) override;
		void update(void) override;
		void render(SDL_Renderer *) override;
};