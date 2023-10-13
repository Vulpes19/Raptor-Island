#pragma once

#include <iostream>
#include <vector>
#include "ErrorHandler.hpp"

class LevelBuilder
{
	public:
		LevelBuilder(void);
		~LevelBuilder(void);
		std::vector<std::vector<char>>	&loadLevel(const char *);
};