#include "Player.hpp"

#include "Constants.hpp"

Player::Player(SDL_FRect rect, size_t texture)
		: transform(rect), textureID(texture)
	{
		collider = SDL_FRect
		{
			transform.x + 8, transform.y + 6,
			12, 70
		};
	}

	void Player::Draw(SDL_Renderer* renderer, const AssetManager& assets) const
	{
		SDL_RenderCopyF(renderer, assets.GetTexture(textureID), nullptr, &transform);
	}


	void Player::Update()
	{
		if (control->IsPressed(SDL_SCANCODE_S) && (transform.y + transform.h) < WINDOW_HIGHT-10)
		{
			transform.y += SPEED;
			collider.y += SPEED;
		}

		if (control->IsPressed(SDL_SCANCODE_W) && transform.y > 10)
		{
			transform.y -= SPEED;
			collider.y -= SPEED;
		}
	}

	SDL_FRect Player::Collider() const 
	{
		return collider;
	}

	void Player::SetController(Control* control)
	{
		this->control = control;
	}
