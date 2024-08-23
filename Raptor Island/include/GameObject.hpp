#pragma once

#include "TextureManager.hpp"
#include "Vector.hpp"

#define MIN_X 0
#define MAX_X 1280
#define MIN_Y 0
#define MAX_Y 720

enum class TYPES
{
	PLAYER,
	RAPTOR
};

class GameObject
{
	public:
		GameObject(std::string, Vector);
		~GameObject(void);
		virtual void	handleInput(void);
		virtual void	update(double);
		void	render(SDL_Renderer *);
	protected:
		Vector	position;
		Vector	velocity;
		Vector	acceleration;
		std::string	textureName;
};