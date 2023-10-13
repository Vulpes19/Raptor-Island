#include "LevelBuilder.hpp"

LevelBuilder::LevelBuilder(void)
{}

LevelBuilder::~LevelBuilder(void)
{}

std::vector<std::vector<char>>	&LevelBuilder::loadLevel(const char *filePath)
{
	std::ifstream file(filePath);

	if (!file.is_open())
		throw(ErrorHandler("Failed to load level file: " + filePath, __FILE__, __LINE__));
	std::string temp;
	std::vector<std::vector<char>> ret;

	while (std::getline(file, temp))
	{
		ret.push_back(temp.c_str());
	}
	for (auto s : ret)
	{
		for (auto i : s)
			std::cout << i;
		std::cout << std::endl;
	}
	return (ret);
}