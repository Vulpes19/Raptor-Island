#pragma once

#include "FontManager.hpp"

class UILabel
{
	public:
		UILabel(int, int, SDL_Color, std::string);
		~UILable(void);
		void	render(int, int, std::string, SDL_Renderer *);
	private:

};