#pragma once

#include <ft2build.h>
#include <Vector.hpp>
#include <map>
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "ErrorHandler.hpp"

class FontManager
{
	public:
		~FontManager(void);
		static FontManager	*getInstance(void);
		void	loadFonts(void);
		TTF_Font* getFont(std::string) const;
	private:
		FontManager(void);
		std::map<std::string, TTF_Font *> fonts;
		static FontManager* instance;
};
