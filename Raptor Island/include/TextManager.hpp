#pragma once

#include <ft2build.h>
#include <Vector.hpp>
#include <map>
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "ErrorHandler.hpp"

class TextManager
{
	public:
		TextManager(void);
		~TextManager(void);
		void	loadFonts(void);
		void	render(SDL_Renderer*, std::string, std::string);
	private:
		std::map<std::string, TTF_Font *> fonts;
};