#pragma once
#include "SDL.h"
#include "AssetManager.hpp"
#include "Control.hpp"
#include "GameObject.hpp"


class Player : public GameObject
{
public:
	Player(SDL_FRect rect, size_t texture);

	virtual void Draw(SDL_Renderer* renderer, const AssetManager& assets) const override;
	virtual SDL_FRect Collider() const override;
	void SetController(Control* control);
	virtual void Update() override;

private:

	Control* control = nullptr;
	SDL_FRect transform;
	SDL_FRect collider;
	size_t textureID;

	static const int SPEED = 5;
};