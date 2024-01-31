#pragma once

#include "GameState.hpp"
#include "InputObserver.hpp"
#include "InputDetector.hpp"
#include "StatesManager.hpp"

class LevelMenu : public GameState, public InputObserver
{
public:
	LevelMenu(void);
	~LevelMenu(void);
	void handleInput(void) override;
	void keyDown(SDL_Scancode, double) override;
	void mouseMove(Uint8) override;
	void update(void) override;
	void render(SDL_Renderer*) override;
private:
	std::map<std::string, BUTTON_STATE> buttonsState;
};