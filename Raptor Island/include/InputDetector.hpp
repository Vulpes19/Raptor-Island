#pragma once

#include <SDL.h>

class InputDetector
{
	public:
		~InputHandler(void);
		static InputDetector* getInstance(void);
		bool	isKeyPressed(SDL_Scancode) const;
	private:
		InputHandler(void);
		static InputDetector* instance;
		const Uint8* keyboardState = SDL_GetKeyboardState(0);
};

InputDetector* InputDetector::instance = nullptr;