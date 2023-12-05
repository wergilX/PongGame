#pragma once

#include "GameObject.hpp"

class Background : public GameObject
{
public:
	Background(SDL_Rect rect, size_t texture)
		: transform{ rect }, textureID{ texture }
	{ }

	virtual void Draw(SDL_Renderer* renderer, const AssetManager& assets) const override
	{
		SDL_RenderCopy(renderer, assets.GetTexture(textureID), nullptr, &transform);
	}

	virtual void Update() override {}
	virtual SDL_FRect Collider() const override { return SDL_FRect{ 0, 0, 0, 0 }; }

private:
	SDL_Rect transform;
	size_t textureID;
};
