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

void	LevelMenu::keyDown(SDL_Scancode key, double deltaTime, InputManager *input, SDL_Renderer* renderer)
{
	if (InputDetector::getInstance()->isKeyPressed(key))
	{
		if (key == SDL_SCANCODE_RIGHT)
		{
			buttonsState["Level1"] = FOCUS_OFF;
			buttonsState["Level2"] = FOCUS_ON;
		}
		if (key == SDL_SCANCODE_LEFT)
		{
			buttonsState["Level1"] = FOCUS_ON;
			buttonsState["Level2"] = FOCUS_OFF;
		}
		if (key == SDL_SCANCODE_RETURN && buttonsState["Level1"] == FOCUS_ON)
		{
			std::cout << "gameplay menu is pushed" << std::endl;
			StatesManager::getInstance()->addState(new GamePlay(input, renderer));
			InputObserver* gamePlayObserver = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
			if (gamePlayObserver)
				input->addObserver(gamePlayObserver);
			else
				throw(ErrorHandler("Can't cast state to an observer, causes the input to not work: ", __FILE__, __LINE__));
		}
	}
}

void	LevelMenu::mouseMove(Uint8 mouseButton, InputManager* input, SDL_Renderer* renderer)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x >= 10 && x <= 120 && y >= 10 && y <= 310)
	{
		buttonsState["Level1"] = FOCUS_ON;
		buttonsState["Level2"] = FOCUS_OFF;
		if (mouseButton == SDL_BUTTON_LEFT)
		{
			std::cout << "gameplay menu is pushed" << std::endl;
			StatesManager::getInstance()->addState(new GamePlay(input, renderer));
			InputObserver* gamePlayObserver = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
			if (gamePlayObserver)
				input->addObserver(gamePlayObserver);
			else
				throw(ErrorHandler("Can't cast state to an observer, causes the input to not work: ", __FILE__, __LINE__));
		}
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

