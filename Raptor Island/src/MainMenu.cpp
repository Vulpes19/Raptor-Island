#include "MainMenu.hpp"

MainMenu::MainMenu(void)
{
	stateName = MainMenuState;
	label.addButtonType("Start", 100, 200, { 136, 8, 8, 255 });
}

MainMenu::~MainMenu(void)
{}

void	MainMenu::handleInput(void)
{

}

void	MainMenu::update(void)
{

}

void	MainMenu::render(SDL_Renderer *renderer)
{
	std::cout << "Im in main menu" << std::endl;
	label.render(300, 300, "Start", "Play", "Bangers", renderer);
}

