#include "SDL_mixer.h"
#include "Constants.hpp"
#include "Player.hpp"
#include "Ball.hpp"
#include "Bot.hpp"

bool Overlapsed(SDL_FRect r1, SDL_FRect r2)
{	
	if ((r1.x + r1.w) >= r2.x && (
		r1.y <= (r2.y + r2.h) &&
		(r1.y + r1.h) >= r2.y))
	{ return true;}

	return false;
}

Ball::Ball(SDL_FRect rect, size_t texture)
	: transform{ rect }, textureID{ texture }
{
	Reset();

	collider = SDL_FRect
	{
		transform.x + 10,
		transform.y + 10,
		10, 10
	};
}

void Ball::Draw(SDL_Renderer* renderer, const AssetManager& assets) const
{
	SDL_RenderCopyF(renderer, assets.GetTexture(textureID), nullptr, &transform);
}

void Ball::Update()
{
	transform.x += velocityX;
	transform.y += velocityY;

	collider.x += velocityX;
	collider.y += velocityY;

	// Left side hit:
	if (collider.x < 0)
	{
		Reset();
		NotifyScore(Paddle::Right);
		Mix_PlayMusic(assets->GetAudio(ID_SOUND_SCORE), 0);
	}

	// Right side hit:
	if (collider.x + collider.w > WINDOW_WIDTH)
	{
		Reset();
		NotifyScore(Paddle::Left);
		Mix_PlayMusic(assets->GetAudio(ID_SOUND_SCORE), 0);
	}

	// Top & bottom hit:
	if (collider.y < 15 || collider.y + collider.h > WINDOW_HIGHT - 10)
	{
		velocityY *= -1;
		Mix_PlayMusic(assets->GetAudio(ID_SOUND_SCORE), 0);
	}

	// Player hit:
	if (Overlapsed(leftPlayer->Collider(), collider))
	{
		velocityX = 3;
		Mix_PlayMusic(assets->GetAudio(ID_SOUND_BOUNCE), 0);
	}
	if (Overlapsed(collider, rightPlayer->Collider()))
	{
		velocityX = -3;
		Mix_PlayMusic(assets->GetAudio(ID_SOUND_BOUNCE), 0);
	}
}

SDL_FRect Ball::Collider() const
{
	return collider;
}

void Ball::SetPlayer(GameObject* player)
{
	leftPlayer = player;
}

void Ball::SetBot(GameObject* bot)
{
	rightPlayer = bot;
}

void Ball::SetScore(Score* score)
{
	this->score = score;
}

void Ball::SetAssets(AssetManager* assets)
{
	this->assets = assets;
}

void Ball::Reset()
{
	transform.x = WINDOW_WIDTH / 2;
	transform.y = WINDOW_HIGHT / 2;

	collider.x = (WINDOW_WIDTH / 2) + 10;
	collider.y = (WINDOW_HIGHT / 2) + 10;

	velocityX *= -1;
}


bool Ball::GetDirectiotX()
{
	if (velocityX > 0)
		return true;
	else
		return false;
}

void Ball::NotifyScore(Paddle paddle)
{
	score->HandleHit(paddle);
}