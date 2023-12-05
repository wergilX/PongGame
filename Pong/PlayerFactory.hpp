#pragma once

#include "GameObject.hpp"
#include "Player.hpp"
#include "Bot.hpp"

#include <memory>

enum class PlayerKind
{
	Person, Bot
};

class PlayerFactory
{
public:
	static std::unique_ptr<GameObject> New(
		PlayerKind kind,
		SDL_FRect transform,
		size_t textureID
	) {
		switch (kind)
		{
		case PlayerKind::Person:
			return std::make_unique<Player>(transform, textureID);
		case PlayerKind::Bot:
			return std::make_unique<Bot>(transform, textureID);
		default:
			return nullptr;
		}
	}
};