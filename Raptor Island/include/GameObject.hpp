#pragma once

#include "TextureManager.hpp"
#include "Vector.hpp"

enum type
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
		virtual void	update(void);
		void	render(SDL_Renderer *);
	private:
		Vector	position;
		Vector	velocity;
		double	acceleration;
		std::string	textureName;
};