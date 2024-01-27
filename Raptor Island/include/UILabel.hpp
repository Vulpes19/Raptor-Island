#pragma once

#include "FontManager.hpp"

enum BUTTON_STATE {
	FOCUS_ON,
	FOCUS_OFF
};

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
		void	render(int x, int y, 
			std::string ID, std::string content, 
			std::string font, SDL_Renderer* renderer, BUTTON_STATE);
	private:
		std::map<std::string, Button *> labels;
};