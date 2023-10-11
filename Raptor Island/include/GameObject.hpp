#pragma once

#include "TextureManager.hpp"
#include "Vector.hpp"

enum class TYPES
{
	PLAYER,
	RAPTOR
};

class GameObject
{
	public:
		GameObject(std::string);
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