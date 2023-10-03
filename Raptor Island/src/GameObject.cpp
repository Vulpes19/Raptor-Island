#include "GameObject.hpp"

GameObject::GameObject(std::string textureName) : textureName(textureName)
{}

GameObject::~GameObject(void)
{}

void	GameObject::handleInput(void)
{}

void	GameObject::update(void)
{}

void	GameObject::render(SDL_Renderer* renderer)
{
	SDL_Texture* texture = TextureManager::getInstance()->getTexture(textureName);
    SDL_Rect    src;
    SDL_Rect    dest;

    if (texture == nullptr)
        throw(ErrorHandler("Failed to load texture: " + std::string(IMG_GetError()), __FILE__, __LINE__));
    src.x = 0;
    src.y = 0;
    src.w = dest.w = 60;
    src.h = dest.h = 60;
    dest.x = (int)position.getX();
    dest.y = (int)position.getY();
    SDL_RenderCopyEx(renderer, texture, &src, &dest, 0, 0, SDL_FLIP_NONE);
}