#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "ErrorHandler.hpp"
#include <string>
#include <algorithm>

class LevelBuilder
{
	public:
		LevelBuilder(void);
		~LevelBuilder(void);
		std::vector<std::vector<char>>	loadLevel(const char *);
};