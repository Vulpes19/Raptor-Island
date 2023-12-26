#pragma once

#include "Vector.hpp"

enum class COLLISION {
	ENEMY,
	WALL,
	NO_COLLISION
};

class CollisionObserver {
	public:
		virtual COLLISION checkCollision(Vector) = 0;
};