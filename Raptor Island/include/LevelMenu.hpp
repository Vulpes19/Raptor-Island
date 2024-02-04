#pragma once

#include "GameState.hpp"
#include "InputObserver.hpp"
#include "InputDetector.hpp"
#include "InputManager.hpp"
#include "StatesManager.hpp"
#include "GamePlay.hpp"

class LevelMenu : public GameState, public InputObserver
{
public:
	LevelMenu(void);
	~LevelMenu(void);
	void handleInput(void) override;
	void keyDown(SDL_Scancode, double, InputManager *, SDL_Renderer*) override;
	void mouseMove(Uint8, InputManager*, SDL_Renderer*) override;
	void update(void) override;
	void render(SDL_Renderer*) override;
private:
	std::map<std::string, BUTTON_STATE> buttonsState;
};