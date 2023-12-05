#pragma once

#include "GameObject.hpp"
#include "Ball.hpp"

class Bot : public GameObject
{
public:

	virtual void Draw(SDL_Renderer* renderer, const AssetManager& assets) const override;
	virtual SDL_FRect Collider() const override;
	Bot(SDL_FRect rect, size_t texture);
	virtual void Update() override;
	void SetBall(Ball* ball);

private:
	SDL_FRect transform;
	SDL_FRect collider;
	size_t textureID;

	Ball* ball = nullptr;
	static const int SPEED = 2;
	
};

