#include <exception>

#include "Constants.hpp"
#include "Game.hpp"

	Game::Game()
		: window(nullptr, SDL_DestroyWindow)
		, renderer(nullptr, SDL_DestroyRenderer)
	{
		auto windowPtr = SDL_CreateWindow(
			"Pong!", 100, 100, WINDOW_WIDTH, WINDOW_HIGHT, 0
		);

		if (windowPtr == nullptr)
		{
			//throw std::exception{ SDL_GetError() };
			printf("Window Error");
			exit;
		}

		auto rendererPtr = SDL_CreateRenderer(windowPtr, -1, SDL_RENDERER_ACCELERATED);
		if (rendererPtr == nullptr)
		{
			//throw std::exception{ SDL_GetError() };
			printf("Render Error");
			exit;
		}

			window.reset(windowPtr);
			renderer.reset(rendererPtr);
	}

	void Game::Draw()
	{
		SDL_RenderClear(renderer.get());

		for (auto& gameObj : gameObjects)
		{
			gameObj->Draw(renderer.get(), assets);
		}

		SDL_RenderPresent(renderer.get());
	}

	void Game::Run()
	{
		running = true;
		SDL_Event event;

		assets.LoadTexture(ID_BLUE_PLAYER,	"../assets/player_blue.png", renderer.get());
		assets.LoadTexture(ID_RED_PLAYER,	"../assets/player_red.png", renderer.get());
		assets.LoadTexture(ID_BACKGROUND,	"../assets/field.png", renderer.get());
		assets.LoadTexture(ID_BALL,			"../assets/ball.png", renderer.get());
		assets.LoadFont   (ID_TTF,			"../assets/square.ttf", 10);
		assets.LoadAudio  (ID_SOUND_BOUNCE,	"../assets/bounce.ogg");
		assets.LoadAudio  (ID_SOUND_SCORE,	"../assets/score.ogg");

		auto playerObj = PlayerFactory::New(PlayerKind::Person, SDL_FRect{ PLAYER_LEFT_POSX,( WINDOW_HIGHT / 2 - PLAYER_HIGHT / 2), PLAYER_WIDTH, PLAYER_HIGHT }, ID_BLUE_PLAYER);
		//auto playerObj = PlayerFactory::New(PlayerKind::Bot, SDL_FRect{ 10, (480 / 2 - 80), 26, 80 }, 40);
		auto botObj = PlayerFactory::New(PlayerKind::Bot, SDL_FRect{ PLAYER_RIGHT_POSX,( WINDOW_HIGHT / 2 - PLAYER_HIGHT / 2), PLAYER_WIDTH, PLAYER_HIGHT }, ID_RED_PLAYER);
		auto ball = std::make_unique<Ball>(SDL_FRect{ WINDOW_WIDTH/2, WINDOW_HIGHT/2, SIZE_BALL, SIZE_BALL }, ID_BALL);
		auto score = std::make_unique<Score>();

		ball->SetPlayer(playerObj.get());
		ball->SetScore(score.get());
		ball->SetBot(botObj.get());
		ball->SetAssets(&assets);

		dynamic_cast<Bot*>(botObj.get())->SetBall(ball.get());
		//dynamic_cast<Bot*>(playerObj.get())->SetBall(ball.get());
		dynamic_cast<Player*>(playerObj.get())->SetController(&control);
		
		gameObjects.push_back(std::make_unique<Background>(SDL_Rect{ 0, 0, WINDOW_WIDTH, WINDOW_HIGHT }, ID_BACKGROUND));
		gameObjects.push_back(std::move(playerObj));
		gameObjects.push_back(std::move(botObj));
		gameObjects.push_back(std::move(ball));
		gameObjects.push_back(std::move(score));
		
		
		Uint32 frameStart;
		int frameTime;
		const int frameDelay = 1000 / 60;

		while (running)
		{
			frameStart = SDL_GetTicks();
			running = control.Update();

			for (auto& gameObj : gameObjects) gameObj->Update();
			
			Draw();

			frameTime = SDL_GetTicks() - frameStart;
			if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
		}
	}
