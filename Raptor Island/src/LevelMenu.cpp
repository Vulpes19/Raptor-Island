#include "LevelMenu.hpp"

LevelMenu::LevelMenu(void)
{
	stateName = LevelMenuState;
	label.addButtonType("LevelMenu", 100, 100, { 136, 8, 8, 255 });
	buttonsState["Level1"] = FOCUS_ON;
	buttonsState["Level2"] = FOCUS_OFF;
}

LevelMenu::~LevelMenu(void)
{}

void	LevelMenu::keyDown(SDL_Scancode key, double deltaTime)
{
	if (InputDetector::getInstance()->isKeyPressed(key))
	{
		if (key == SDL_SCANCODE_RIGHT)
		{
			buttonsState["Play"] = FOCUS_OFF;
			buttonsState["Quit"] = FOCUS_ON;
		}
		if (key == SDL_SCANCODE_LEFT)
		{
			buttonsState["Play"] = FOCUS_ON;
			buttonsState["Quit"] = FOCUS_OFF;
		}
	}
}

void	LevelMenu::mouseMove()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x >= 10 && x <= 120 && y >= 10 && y <= 310)
	{
		buttonsState["Level1"] = FOCUS_ON;
		buttonsState["Level2"] = FOCUS_OFF;
	}
	if (x >= 540 && x <= 640 && y >= 400 && y <= 500)
	{
		buttonsState["Level1"] = FOCUS_OFF;
		buttonsState["Level2"] = FOCUS_ON;
	}
}

void	LevelMenu::handleInput(void)
{

}

void	LevelMenu::update(void)
{

}

void	LevelMenu::render(SDL_Renderer* renderer)
{
	label.render(10, 10, "LevelMenu", "Level 1", "Bangers", renderer, buttonsState["Level1"]);
	label.render(540, 400, "LevelMenu", "Level 2", "Bangers", renderer, buttonsState["Level2"]);
}

