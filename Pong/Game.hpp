#pragma once

#include <memory>
#include <vector>

#include "SDL.h"

#include "Control.hpp"
#include "AssetManager.hpp"
#include "PlayerFactory.hpp"

class Game
{
public:
	Game();
	void Draw();
	void Run();
private:
	std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer;
	std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window;
	std::vector<std::unique_ptr<GameObject>> gameObjects;

	Control control;
	AssetManager assets;

	bool running = false;	
};