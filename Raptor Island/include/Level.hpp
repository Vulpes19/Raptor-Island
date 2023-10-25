#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "LevelBuilder.hpp"
#include "TextureManager.hpp"
#include <map>

enum GameResult
{
	WIN,
	LOSS,
	NONE
};

class Level
{
	public:
		Level(SDL_Renderer *);
		~Level(void);
		void	generateLevel(std::string, std::string);
		void	render(SDL_Renderer *);
		void	update(void);
		GameResult	getResult(void) const;
	private:
		std::vector<std::vector<char>> levelStr;
		LevelBuilder builder;
		std::map<std::string, std::string>	levelPaths;
		GameResult	result;
};