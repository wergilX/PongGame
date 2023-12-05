#pragma once
#include "GameObject.hpp"
#include "Score.hpp"

bool Overlapsed(SDL_FRect r1, SDL_FRect r2);

class Player;
class Bot;

class Ball : public GameObject 
{
public:
	Ball(SDL_FRect rect, size_t texture);

	virtual void Draw(SDL_Renderer* renderer, const AssetManager& assets) const override;
	virtual SDL_FRect Collider() const override;
	virtual void Update() override;

	void SetAssets(AssetManager* assets);
	void SetPlayer(GameObject* player);
	void SetBot(GameObject* bot);
	void SetScore(Score* score);
	bool GetDirectiotX();

private:

	void NotifyScore(Paddle paddle);
	void Reset();

	float velocityX = 3;
	float velocityY = 3;

	SDL_FRect transform;
	SDL_FRect collider;
	size_t textureID;

	GameObject* rightPlayer = nullptr;
	GameObject* leftPlayer = nullptr;
	Score* score = nullptr;

	AssetManager* assets;
};