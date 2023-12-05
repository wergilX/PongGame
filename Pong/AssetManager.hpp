#pragma once
#include <unordered_map>
#include <exception>
#include <memory>

#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL.h"

using ID = size_t;

class AssetManager
{
public:
	void LoadTexture(ID id, const char* path, SDL_Renderer* renderer);
	void LoadFont(ID id, const char* path, int size);
	void LoadAudio(ID id, const char* path);

	SDL_Texture* GetTexture(ID id) const;
	Mix_Music* GetAudio(ID id) const;
	TTF_Font* GetFont(ID id) const;

	~AssetManager();

private:
	std::unordered_map<ID, SDL_Texture*> textures;
	std::unordered_map<ID, Mix_Music*> audio;
	std::unordered_map<ID, TTF_Font*> fonts;
};