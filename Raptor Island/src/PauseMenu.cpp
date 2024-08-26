#include "PauseMenu.hpp"

PauseMenu::PauseMenu(void)
{
	std::cout << "pause menu is pushed" << std::endl;
	stateName = PauseMenuState;
	label.addButtonType("PauseMenu", 80, 200, { 136, 8, 8, 255 });
	buttonsState["Resume"] = FOCUS_ON;
	buttonsState["Quit"] = FOCUS_OFF;
}

PauseMenu::~PauseMenu(void)
{}

void	PauseMenu::keyDown(SDL_Scancode key, double deltaTime, InputManager* input, SDL_Renderer*)
{
	if (InputDetector::getInstance()->isKeyPressed(key) && StatesManager::getInstance()->getCurrentState() == PauseMenuState)
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
			StatesManager::getInstance()->removeState(input);
		}
		if (key == SDL_SCANCODE_RETURN && buttonsState["Quit"] == FOCUS_ON)
			StatesManager::getInstance()->removeState(2, input);
	}
}

void	PauseMenu::mouseMove(Uint8 mouseButton, InputManager* input, SDL_Renderer*)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x >= 540 && x <= 740 && y >= 300 && y <= 380 && StatesManager::getInstance()->getCurrentState() == PauseMenuState)
	{
		buttonsState["Resume"] = FOCUS_ON;
		buttonsState["Quit"] = FOCUS_OFF;
		if (mouseButton == SDL_BUTTON_LEFT)
		{
			StatesManager::getInstance()->removeState(input);
			//std::cout << "replacing observer " << StatesManager::getInstance()->getCurrentState() << std::endl;
			//InputObserver* observer = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
			//if (observer)
				//input->addObserver(observer);
		}
	}
	if (x >= 540 && x <= 740 && y >= 400 && y <= 480 && StatesManager::getInstance()->getCurrentState() == PauseMenuState)
	{
		buttonsState["Resume"] = FOCUS_OFF;
		buttonsState["Quit"] = FOCUS_ON;
		if (mouseButton == SDL_BUTTON_LEFT)
		{
			StatesManager::getInstance()->removeState(2, input);
			//InputObserver* observer = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
			//if (observer)
				//input->addObserver(observer);
		}
	}
}

void	PauseMenu::handleInput(void)
{

}

void	PauseMenu::update(double)
{

}

void	PauseMenu::render(SDL_Renderer* renderer)
{
	label.render(540, 300, "PauseMenu", "Resume", "Bangers", renderer, buttonsState["Resume"]);
	label.render(540, 400, "PauseMenu", "Quit", "Bangers", renderer, buttonsState["Quit"]);
}

