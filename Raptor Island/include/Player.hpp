#pragma once

#include "GameObject.hpp"
#include "InputObserver.hpp"
#include "InputDetector.hpp"
#include "Level.hpp"

class Player : public InputObserver, public GameObject
{
	public:
		Player(std::string, Vector&);
		virtual ~Player(void);
		void	handleInput(void) override {};
		void	keyDown(SDL_Scancode, double, InputManager* = nullptr, SDL_Renderer* = nullptr) override;
		//void	keyUp(SDL_Scancode, double, InputManager* = nullptr, SDL_Renderer* = nullptr);
		void	mouseMove(Uint8, InputManager* = nullptr, SDL_Renderer* = nullptr) override {};
		void	update(double) override;
		void	addCollisionObserver(CollisionObserver*);
		void	eraseCollisionObserver(CollisionObserver*);
		void	playerWasted(void);
	private:
		std::vector<CollisionObserver*> observers; //walls, enemies etc
};