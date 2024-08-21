#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "LevelBuilder.hpp"
#include "TextureManager.hpp"
#include "CollisionObserver.hpp"
#include <map>

enum GameResult
{
	WIN,
	LOSS,
	NONE
};

class Level : public CollisionObserver
{
	public:
		Level(SDL_Renderer *);
		~Level(void);
		std::vector<Vector>	generateLevel(std::string, std::string);
		void				render(SDL_Renderer *);
		void				update(void);
		GameResult			getResult(void) const;
		COLLISION			checkCollision(Vector) override;
	private:
		std::vector<std::vector<char>> levelStr;
		LevelBuilder builder;
		std::map<std::string, std::string>	levelPaths;
		GameResult	result;
};