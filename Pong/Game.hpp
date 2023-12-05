#pragma once

#include <memory>
#include <vector>

#include "SDL.h"

#include "PlayerFactory.hpp"
#include "AssetManager.hpp"
#include "Background.hpp"
#include "Control.hpp"
#include "Player.hpp"
#include "Score.hpp"
#include "Ball.hpp"
#include "Bot.hpp"

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