#pragma once

#include "GameObject.hpp"
#include "Player.hpp"

class GameObjectFactory
{
	public:
		GameObject* createGameObject(enum class TYPES, std::string, const char *, SDL_Renderer *);
};