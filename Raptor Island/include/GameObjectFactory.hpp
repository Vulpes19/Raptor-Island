#pragma once

#include "GameObject.hpp"

class GameObjectFactory
{
	public:
		GameObject* createGameObject(enum TYPES, std::string, const char *);
};