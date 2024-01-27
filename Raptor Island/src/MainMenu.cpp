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

