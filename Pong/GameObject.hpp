#pragma once

#include "AssetManager.hpp"
#include "Control.hpp"
#include "SDL.h"


class GameObject
{
public:

	virtual void Draw(SDL_Renderer* renderer, const AssetManager& assets) const = 0;
	virtual void Update() = 0;
	virtual SDL_FRect Collider() const = 0;
};