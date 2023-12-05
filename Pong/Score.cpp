#include "Score.hpp"
#include "Constants.hpp"

	void Score::Draw(SDL_Renderer* renderer, const AssetManager& assets) const
	{
		SDL_Surface* leftMessageSurface = TTF_RenderText_Solid(assets.GetFont(ID_TTF), std::to_string(leftCount).c_str(), color);
		SDL_Surface* rightMessageSurface = TTF_RenderText_Solid(assets.GetFont(ID_TTF), std::to_string(rightCount).c_str(), color);

		SDL_Texture* leftMessage = SDL_CreateTextureFromSurface(renderer, leftMessageSurface);
		SDL_Texture* rightMessage = SDL_CreateTextureFromSurface(renderer, rightMessageSurface);

		SDL_Rect rect{
			55, 25,
			50, 50
		};

		SDL_RenderCopy(renderer, leftMessage, nullptr, &rect);

		rect.x = 500;
		SDL_RenderCopy(renderer, rightMessage, nullptr, &rect);

		SDL_FreeSurface(rightMessageSurface);
		SDL_FreeSurface(leftMessageSurface);
		SDL_DestroyTexture(rightMessage);
		SDL_DestroyTexture(leftMessage);
	}

	SDL_FRect Score::Collider() const
	{
		return SDL_FRect{ 0, 0, 0, 0 };
	}

	void Score::HandleHit(Paddle paddle)
	{
		switch (paddle)
		{
		case Paddle::Left:
			leftCount++;
			break;
		case Paddle::Right:
			rightCount++;
			break;
		}
	}
