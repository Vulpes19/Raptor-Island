#include "LevelBuilder.hpp"

LevelBuilder::LevelBuilder(void)
{}

LevelBuilder::~LevelBuilder(void)
{}

std::vector<std::vector<char>>	LevelBuilder::loadLevel(const char *filePath)
{
	std::ifstream file(filePath);

	if (!file.is_open())
		throw(ErrorHandler("Failed to load level file: " + std::string(filePath), __FILE__, __LINE__));
	std::string temp;
	std::vector<std::vector<char>> ret;

	while (std::getline(file, temp))
	{
		std::vector<char> line;
		std::copy(temp.begin(), temp.end(), std::back_inserter(line));
		ret.push_back(line);
	}
	return (ret);
}