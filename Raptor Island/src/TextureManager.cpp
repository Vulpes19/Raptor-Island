#include "TextureManager.hpp"

TextureManager *TextureManager::instance = nullptr;

TextureManager::TextureManager(void)
{
	if (IMG_Init(IMG_INIT_PNG) < 0)
		throw(ErrorHandler("SDL_image failed to initialize: " + std::string(IMG_GetError()), __FILE__, __LINE__));
}

TextureManager::~TextureManager(void)
{
	for (auto it = textures.begin(); it != textures.end(); ++it)
	{
		SDL_DestroyTexture(it->second);
	}
	textures.clear();
	IMG_Quit();
}

TextureManager* TextureManager::getInstance(void)
{
	if (instance == nullptr)
		instance = new TextureManager();
	return (instance);
}

void	TextureManager::loadImage(const char* imgPath, std::string name, SDL_Renderer *renderer)
{
	if (textures.find(name) != textures.end())
		return;
	SDL_Surface* surface;
	surface = IMG_Load(imgPath);
	if (!surface)
		throw(ErrorHandler("Unable to load image from file: " + std::string(IMG_GetError()), __FILE__, __LINE__));
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (!texture)
		throw(ErrorHandler("Unable to create texture from surface: " + std::string(IMG_GetError()), __FILE__, __LINE__));
	textures[name] = texture;
	/*
	std::cout << name << std::endl;
	std::cout << textures.count(name) << std::endl;*/
}

SDL_Texture* TextureManager::getTexture(std::string name)
{
	auto it = textures.find(name);
	if (it != textures.end())
		return textures[name];
	return (nullptr);
}

void	TextureManager::removeTexture(std::string name)
{
	auto it = textures.find(name);
	if (it != textures.end())
	{
		SDL_DestroyTexture(it->second);
		textures.erase(name);
	}
}