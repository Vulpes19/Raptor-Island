#include "MainMenu.hpp"

MainMenu::MainMenu(void)
{
	stateName = MainMenuState;
	label.addButtonType("MainMenu", 80, 200, { 136, 8, 8, 255 });
	buttonsState["Play"] = FOCUS_ON;
	buttonsState["Quit"] = FOCUS_OFF;
}

MainMenu::~MainMenu(void)
{}

void	MainMenu::keyDown(SDL_Scancode key, double deltaTime)
{
	if (InputDetector::getInstance()->isKeyPressed(key))
	{
		if (key == SDL_SCANCODE_DOWN)
		{
			buttonsState["Play"] = FOCUS_OFF;
			buttonsState["Quit"] = FOCUS_ON;
		}
		if (key == SDL_SCANCODE_UP)
		{
			buttonsState["Play"] = FOCUS_ON;
			buttonsState["Quit"] = FOCUS_OFF;
		}
		if (key == SDL_SCANCODE_RETURN && buttonsState["Play"] == FOCUS_ON)
			StatesManager::getInstance()->addState(new LevelMenu());
	}
}

void	MainMenu::mouseMove(Uint8 mouseButton)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x >= 540 && x <= 740 && y >= 300 && y <= 380)
	{
		buttonsState["Play"] = FOCUS_ON;
		buttonsState["Quit"] = FOCUS_OFF;
		if (mouseButton == SDL_BUTTON_LEFT)
			StatesManager::getInstance()->addState(new LevelMenu());
	}
	if (x >= 540 && x <= 740 && y >= 400 && y <= 480)
	{
		buttonsState["Play"] = FOCUS_OFF;
		buttonsState["Quit"] = FOCUS_ON;
	}
}

void	MainMenu::handleInput(void)
{

}

void	MainMenu::update(void)
{

}

void	MainMenu::render(SDL_Renderer *renderer)
{
	label.render(540, 300, "MainMenu", "Play", "Bangers", renderer, buttonsState["Play"]);
	label.render(540, 400, "MainMenu", "Quit", "Bangers", renderer, buttonsState["Quit"]);
}

