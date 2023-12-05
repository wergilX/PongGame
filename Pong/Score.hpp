#pragma once
#include "GameObject.hpp" 

#include <string>

enum class Paddle
{
	Left, Right
};

class Score : public GameObject
{
public:
	virtual void Draw(SDL_Renderer* renderer, const AssetManager& assets) const override;
	virtual SDL_FRect Collider() const override;
	virtual void Update() override{ }
	void HandleHit(Paddle paddle);

private:
	unsigned rightCount = 0;
	unsigned leftCount = 0;

	SDL_Color color{ 255, 255, 255 };
};