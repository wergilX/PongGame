#include "AssetManager.hpp"
#include <stdexcept>


#include <filesystem>
	void AssetManager::LoadTexture(ID id, const char* path, SDL_Renderer* renderer)
	{
		auto texturePtr = IMG_LoadTexture(renderer, path);
		if (texturePtr == nullptr)
		{
			//throw std::exception{ IMG_GetError() };
			printf("sdl2_image err: %s\n", IMG_GetError());
			
			std::filesystem::path currentPath = std::filesystem::current_path();
			printf("Текущая директория: %s  ", currentPath.c_str());
			exit;
		}

		textures[id] = texturePtr;
	}

	SDL_Texture* AssetManager::GetTexture(ID id) const
	{
		if (auto it = textures.find(id); it != textures.end())
		{
			return it->second;
		}

		return nullptr;
	}

	void AssetManager::LoadFont(ID id, const char* path, int size)
	{
		auto fontPtr = TTF_OpenFont(path, size);
		if (fontPtr == nullptr)
		{
			//throw std::exception{ TTF_GetError() };
			printf("sdl2_ttf err: %s\n", TTF_GetError());
			exit;
		}

		fonts[id] = fontPtr;
	}

	TTF_Font* AssetManager::GetFont(ID id) const
	{
		if (auto it = fonts.find(id); it != fonts.end())
		{
			return it->second;
		}

		return nullptr;
	}

	void AssetManager::LoadAudio(ID id, const char* path)
	{
		auto audioPtr = Mix_LoadMUS(path);
		if (audioPtr == nullptr)
		{
			//throw std::exception{ Mix_GetError() };
			printf("main: sdl2_mix err: %s\n", Mix_GetError());
			exit;
		}

		audio[id] = audioPtr;
	}

	Mix_Music* AssetManager::GetAudio(ID id) const
	{
		if (auto it = audio.find(id); it != audio.end())
		{
			return it->second;
		}
		return nullptr;
	}

	AssetManager::~AssetManager()
	{
		for (auto it = textures.begin(); it != textures.end(); it++)
		{
			SDL_DestroyTexture(it->second);
		}

		for (auto it = fonts.begin(); it != fonts.end(); it++)
		{
			TTF_CloseFont(it->second);
		}

		for (auto it = audio.begin(); it != audio.end(); it++)
		{
			Mix_FreeMusic(it->second);
		}
	}