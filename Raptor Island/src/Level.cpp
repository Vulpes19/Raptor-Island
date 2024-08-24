#include "Level.hpp"

Level::Level(SDL_Renderer *renderer)
{
	TextureManager::getInstance()->loadImage("C:/Users/asus/source/repos/Raptor Island/assets/textures/dirt.png", "dirt", renderer);
	TextureManager::getInstance()->loadImage("C:/Users/asus/source/repos/Raptor Island/assets/textures/brick.png", "brick", renderer);
	//levelPaths["test"] = "C:/Users/asus/source/repos/Raptor Island/assets/levels/level_test.txt";
	//builder.loadLevel(levelPaths["test"].c_str());
}

Level::~Level(void)
{}

levelPosData	Level::generateLevel(std::string level, std::string path)
{
	levelPosData	positions;

	levelPaths[level] = path;
	levelStr.clear();
	levelStr = builder.loadLevel(levelPaths[level].c_str());

	for (unsigned int row = 0; row < levelStr.size(); row++)
	{
		std::vector<char> line = levelStr[row];
		for (unsigned int col = 0; col < line.size(); col++)
		{
			if (line[col] == '0')
			{
				positions.patrolWayPoints.push_back(WayPoint(Vector(col * 64, row * 64)));
			}
			if (line[col] == 'P')
			{
				levelStr[row][col] = '0';
				positions.playerPosition = Vector(col * 64, row * 64);
			}
			if (line[col] == 'R')
			{
				levelStr[row][col] = '0';
				positions.raptorSpawnPoints.push_back(Vector(col, row));
			}
		}
	}
	return positions;
}

void	Level::render(SDL_Renderer *renderer)
{
	SDL_Texture* ground = TextureManager::getInstance()->getTexture("dirt");
	SDL_Texture* wall = TextureManager::getInstance()->getTexture("brick");
	if (!ground)
	{
		throw(ErrorHandler("Error loading texture: " + std::string(SDL_GetError()), __FILE__, __LINE__));
	}
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
			if (line[col] == '0')
			{
				SDL_RenderCopyEx(renderer, ground, &src, &dest, 0, 0, SDL_FLIP_NONE);
			}
			if (line[col] == '1')
			{
				SDL_RenderCopyEx(renderer, wall, &src, &dest, 0, 0, SDL_FLIP_NONE);
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
	int col2 = static_cast<int>((position.getX() + 64) / 64);
	int row2 = static_cast<int>((position.getY() + 64) / 64);

	if (row >= 0 && row2 >= 0 && col >= 0 && col2 >= 0 && row < levelStr.size() && col < levelStr[row].size() && row2 < levelStr.size() && col2 < levelStr[row2].size()
		&& (levelStr[row][col] == '1' || levelStr[row2][col2] == '1' || levelStr[row][col2] == '1' || levelStr[row2][col] == '1'))
	{
		return COLLISION::WALL;
	}
	return COLLISION::NO_COLLISION;
}