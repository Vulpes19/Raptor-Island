#include "Level.hpp"

Level::Level(void)
{
	levelPaths.push_back("C:/Users/asus/source/repos/Raptor Island/assets/levels/level_test.txt");
	builder.loadLevel(levelPaths[0].c_str());
}

Level::~Level(void)
{}

void	Level::render(SDL_Renderer *renderer)
{}

void	Level::update(void)
{}