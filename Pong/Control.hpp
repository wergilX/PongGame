#pragma once

#include <vector>

#include "SDL.h"

class Control {
public:

	bool Update()
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				return false;
			}
		}
		return true;
	}

	bool IsPressed(SDL_Scancode code)
	{
		const Uint8* keystates = SDL_GetKeyboardState(nullptr);
		return keystates[code];
	}
};