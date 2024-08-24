#pragma once

#include "GameObject.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

class GameObjectFactory
{
	public:
		GameObject* createGameObject(
			enum class TYPES, 
			std::string, 
			Vector &, 
			std::vector<WayPoint>&, 
			const char *, 
			SDL_Renderer *);
};