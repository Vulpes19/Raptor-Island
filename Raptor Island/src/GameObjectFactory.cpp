#include "GameObjectFactory.hpp"
 
GameObject* GameObjectFactory::createGameObject(enum class TYPES type, std::string textureName, const char *imgPath, SDL_Renderer *renderer)
{
	TextureManager::getInstance()->loadImage(imgPath, textureName, renderer);
	if (type == TYPES::PLAYER)
	{
		return (new Player(textureName));
	}/*
	if (type == RAPTOR)
		return (new Raptor());*/
	return (nullptr);
}