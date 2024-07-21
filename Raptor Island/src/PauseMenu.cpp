#include "PauseMenu.hpp"

PauseMenu::PauseMenu(void)
{
	stateName = PauseMenuState;
	label.addButtonType("PauseMenu", 80, 200, { 136, 8, 8, 255 });
	buttonsState["Resume"] = FOCUS_ON;
	buttonsState["Quit"] = FOCUS_OFF;
}

PauseMenu::~PauseMenu(void)
{}

void	PauseMenu::keyDown(SDL_Scancode key, double deltaTime, InputManager* input, SDL_Renderer*)
{
	if (InputDetector::getInstance()->isKeyPressed(key))
	{
		if (key == SDL_SCANCODE_DOWN)
		{
			buttonsState["Resume"] = FOCUS_OFF;
			buttonsState["Quit"] = FOCUS_ON;
		}
		if (key == SDL_SCANCODE_UP)
		{
			buttonsState["Resume"] = FOCUS_ON;
			buttonsState["Quit"] = FOCUS_OFF;
		}
		if (key == SDL_SCANCODE_RETURN && buttonsState["Resume"] == FOCUS_ON)
		{
			StatesManager::getInstance()->removeState();
		}
		if (key == SDL_SCANCODE_RETURN && buttonsState["Quit"] == FOCUS_ON)
			StatesManager::getInstance()->removeState(2);
	}
}

void	PauseMenu::mouseMove(Uint8 mouseButton, InputManager* input, SDL_Renderer*)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x >= 540 && x <= 740 && y >= 300 && y <= 380)
	{
		buttonsState["Resume"] = FOCUS_ON;
		buttonsState["Quit"] = FOCUS_OFF;
		if (mouseButton == SDL_BUTTON_LEFT)
		{
			StatesManager::getInstance()->removeState();
		}
	}
	if (x >= 540 && x <= 740 && y >= 400 && y <= 480)
	{
		buttonsState["Resume"] = FOCUS_OFF;
		buttonsState["Quit"] = FOCUS_ON;
		if (mouseButton == SDL_BUTTON_LEFT)
			StatesManager::getInstance()->removeState(2);
	}
}

void	PauseMenu::handleInput(void)
{

}

void	PauseMenu::update(void)
{

}

void	PauseMenu::render(SDL_Renderer* renderer)
{
	label.render(540, 300, "PauseMenu", "Resume", "Bangers", renderer, buttonsState["Resume"]);
	label.render(540, 400, "PauseMenu", "Quit", "Bangers", renderer, buttonsState["Quit"]);
}

