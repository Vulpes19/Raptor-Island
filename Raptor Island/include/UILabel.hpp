#pragma once

#include "FontManager.hpp"

struct Button {
	Button(int h, int w, SDL_Color color) : height(h), width(w), color(color) {};
	int height;
	int width;
	SDL_Color color;
};

class UILabel
{
	public:
		UILabel(void);
		~UILabel(void);
		void	addButtonType(std::string, int, int, SDL_Color);
		void	deleteButtonType(std::string);
		void	render(int, int, std::string, std::string, std::string, SDL_Renderer*);
	private:
		std::map<std::string, Button> labels;
};