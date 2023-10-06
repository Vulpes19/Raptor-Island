#pragma once

#include <iostream>
#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include "ErrorHandler.hpp"

class TextureManager
{
	public:
		~TextureManager(void);
		static TextureManager* getInstance(void);
		void	loadImage(const char*, std::string, SDL_Renderer *);
		SDL_Texture* getTexture(std::string);
		void	removeTexture(std::string);
		void	test(void) { std::cout << "test: " << textures.count("player") << std::endl; };
	private:
		TextureManager(void);
		std::map<std::string, SDL_Texture*> textures;
		static TextureManager* instance;
};