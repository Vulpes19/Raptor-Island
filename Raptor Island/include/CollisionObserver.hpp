#pragma once

#include "Vector.hpp"

class CollisionObserver {
	public:
		virtual bool checkCollision(Vector) = 0;
};