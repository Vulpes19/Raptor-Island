#include "Level.hpp"

Level::Level(SDL_Renderer *renderer)
{
	TextureManager::getInstance()->loadImage("C:/Users/asus/source/repos/Raptor Island/assets/textures/green.png", "green", renderer);
	//levelPaths["test"] = "C:/Users/asus/source/repos/Raptor Island/assets/levels/level_test.txt";
	//builder.loadLevel(levelPaths["test"].c_str());
}

Level::~Level(void)
{}

void	Level::generateLevel(std::string level, std::string path)
{
	levelPaths[level] = path;
	levelStr.clear();
	levelStr = builder.loadLevel(levelPaths[level].c_str());
}

void	Level::render(SDL_Renderer *renderer)
{
	SDL_Texture* ground = TextureManager::getInstance()->getTexture("green");
	/*if (!ground)
	{
	}*/
	SDL_Rect	src, dest;

	//std::cout << "new map\n";
	for (unsigned int row = 0; row < levelStr.size(); row++)
	{
		std::vector<char> line = levelStr[row];
		for (unsigned int col = 0; col < line.size(); col++)
		{
			//std::cout << line[col];
			src.x = 0;
			src.y = 0;
			src.w = dest.w = 64;
			src.h = dest.h = 64;
			dest.x = col * 64;
			dest.y = row * 64;
			if (line[col] == '1')
			{
				SDL_RenderCopyEx(renderer, ground, &src, &dest, 0, 0, SDL_FLIP_NONE);
			}
		}
		//std::cout << std::endl;
	}
}

void	Level::update(void)
{}

GameResult	Level::getResult(void) const
{
	return (result);
}

COLLISION	Level::checkCollision(Vector position)
{
	int col = static_cast<int>(position.getX() / 64);
	int row = static_cast<int>(position.getY() / 64);
	if (row >= 0 && col >= 0 && row < levelStr.size() && col < levelStr[row].size() && levelStr[row][col] == '1')
	{
		std::cout << "size " << levelStr.size() << std::endl;
		std::cout << "wall: " << levelStr[row][col] << " row: " << row << " col: " << col << std::endl;
		return COLLISION::WALL;
	}
	return COLLISION::NO_COLLISION;
}