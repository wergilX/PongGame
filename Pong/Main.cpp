#include <cstdlib>
#include <exception>

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

#include "Game.hpp"

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Failed to init SDL: %s\n",SDL_GetError());
		exit;
	}

	const int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	if ((IMG_Init(flags) & flags) != flags) {
		printf("Failed to init SDL-Image: %s\n", IMG_GetError());
		exit;
	}

	if (TTF_Init() == -1)
	{
		printf("Failed to init SDL-TTF: %s\n", TTF_GetError());
		exit;
	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		printf("Failed to init SDL-Mixer: %s\n", Mix_GetError());
		exit;
	}

	try
	{
		Game game;
		game.Run();
	}

	catch (std::exception& ex)
	{
		printf("Error: %s\n", ex.what());
	}

	return 0;
}