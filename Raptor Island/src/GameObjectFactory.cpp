#include "GameObjectFactory.hpp"
 
GameObject* GameObjectFactory::createGameObject(enum class TYPES type, std::string textureName, Vector spawnPosition, const char *imgPath, SDL_Renderer *renderer)
{
	TextureManager::getInstance()->loadImage(imgPath, textureName, renderer);
	if (type == TYPES::PLAYER)
	{
		return (new Player(textureName, spawnPosition));
	}
	if (type == TYPES::RAPTOR)
		return (new Enemy(textureName, spawnPosition));
	return (nullptr);
}