#include "Bot.hpp"
#include "Constants.hpp"


	Bot::Bot(SDL_FRect rect, size_t texture)
		: textureID{ texture }, transform{ rect }
	{
		collider = SDL_FRect
		{
			transform.x + 8, transform.y + 6,
			12, 70
		};
	}

	void Bot::Draw(SDL_Renderer* renderer, const AssetManager& assets) const 
	{
		SDL_RenderCopyF(renderer, assets.GetTexture(textureID), nullptr, &transform);
	}

	 void Bot::Update()
	{
		if (ball->GetDirectiotX())
		{

			if (ball->Collider().y > (collider.y + (collider.h / 2))&&
				((collider.y + collider.h) < (WINDOW_HIGHT - 15)))
			{
				transform.y += SPEED;
				collider.y += SPEED;
			}

			if (ball->Collider().y < collider.y + (collider.h / 2 && collider.y > 20))
			{
				transform.y -= SPEED;
				collider.y -= SPEED;
			}


		}

	}

	SDL_FRect Bot::Collider() const 
	{
		return collider;
	}

	void Bot::SetBall(Ball* ball)
	{
		this->ball = ball;
	}