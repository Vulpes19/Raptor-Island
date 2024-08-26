#pragma once

#include "GameState.hpp"
#include "InputObserver.hpp"
#include "Player.hpp"
#include "GameObjectFactory.hpp"
#include "Level.hpp"
#include "InputManager.hpp"
#include "StatesManager.hpp"
#include "PauseMenu.hpp"
#include "Enemy.hpp"

class GamePlay : public GameState, public InputObserver
{
	public:
		GamePlay(InputManager *, SDL_Renderer*);
		~GamePlay(void);
		void handleInput(void) override;
		void keyDown(SDL_Scancode, double, InputManager*, SDL_Renderer *) override;
		void mouseMove(Uint8, InputManager*, SDL_Renderer*) override;
		void update(double = 0) override;
		void render(SDL_Renderer *) override;
	private:
		Level* level = nullptr;
		GameObjectFactory factory;
		GameObject* player = nullptr;
		std::vector<GameObject*> raptors;
};