#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "LevelBuilder.hpp"

class Level
{
	public:
		Level(void);
		~Level(void);
		void	render(SDL_Renderer *);
		void	update(void);
	private:
		std::vector<std::vector<char>> levelStr;
		LevelBuilder builder;
		std::vector<std::string> levelPaths;
};