#include "GameObjectFactory.hpp"
 
GameObject* GameObjectFactory::createGameObject(enum TYPES type, std::string textureName, const char *imgPath)
{
	/*
	TextureManager::getInstance()->loadImage(imgPath, textureName);
	if (type == PLAYER)
	{
		return (new Player());
	}
	if (type == RAPTOR)
		return (new Raptor());*/
	return (nullptr);
}