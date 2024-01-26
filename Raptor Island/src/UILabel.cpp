#include "UILabel.hpp"

UILabel::UILabel(void)
{}

UILabel::~UILabel(void)
{}

void	UILabel::addButtonType(std::string ID, int h, int w, SDL_Color color)
{
	Button *button = new Button(h, w, color);
	labels[ID] = button;
}

void	UILabel::deleteButtonType(std::string ID)
{
	auto it = labels.find(ID);
	if (it != labels.end())
	{
		delete it->second;
		labels.erase(ID);
	}
}

void	UILabel::render(int x, int y, std::string ID, std::string content, std::string font, SDL_Renderer* renderer)
{
	auto label = labels.find(ID);
	if (label == labels.end())
		throw(ErrorHandler("Can't find label with ID: " + ID, __FILE__, __LINE__));
	SDL_Rect rect = { x, y, label->second->width, label->second->height };
	SDL_SetRenderDrawColor(renderer,
		label->second->color.r,
		label->second->color.g,
		label->second->color.b,
		label->second->color.a);
	//drawing the button rect
	SDL_RenderFillRect(renderer, &rect);
	TTF_Font* fontPtr = FontManager::getInstance()->getFont(font);
	if (fontPtr == NULL)
		throw(ErrorHandler("Can't find font with ID: " + font, __FILE__, __LINE__));
	SDL_Surface* textSurface = TTF_RenderText_Solid(fontPtr, content.c_str(), { 0, 0, 0, 255 });
	if (textSurface == NULL)
		throw(ErrorHandler("Error rendering text: " + std::string(TTF_GetError()), __FILE__, __LINE__));
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	if (textTexture == NULL)
		throw(ErrorHandler("Error creating text texture from surface: " + std::string(TTF_GetError()), __FILE__, __LINE__));
	SDL_FreeSurface(textSurface);
	int midX = rect.x + (rect.w - 160) / 2;
	int midY = rect.y + (rect.h - 60) / 2;
	SDL_Rect textRect = { midX, midY, 160, 60 };
	SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
	SDL_DestroyTexture(textTexture);
}