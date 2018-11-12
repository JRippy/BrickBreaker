#include "pch.h"
#include "Game.h"
#include "config.h"


Game::Game()
{
}


Game::~Game()
{
}

bool Game::load(SDL_Renderer* gRenderer)
{
	textColor = { 255, 255, 255, 255 };

	newGame = true;

	//r1 = Racket();

	//r2 = Racket((float)c.getScreenWidth() - c.getRacketWidth(), (float)c.getScreenWidth() / 2 - c.getRacketHeight() / 2);

	//r1.load(gRenderer);
	//r2.load(gRenderer);

	////Calculate time step
	//timeStep = stepTimer.getTicks() / 1000.f;

	//dl = DashedLine();
	//dl.load(gRenderer);

	//dot = Dot(gRenderer);
	//dot.loadMediaDot(gRenderer);


	//return dot.isLoaded(); //loadMediaDot(gRenderer);
	return true;
}

bool Game::input(SDL_Renderer* gRenderer, bool quit)
{
	if (!newGame)
	{
		while (SDL_PollEvent(&e) != 0)
		{

			if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
			{
				initGame();
			}
		}
	}
	else
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			//Handle input for the racket
			//r1.handleEvent(e, timeStep);
		}
	}

	return quit;
}

void Game::update()
{

}

void Game::draw(SDL_Renderer* gRenderer)
{

}

void Game::initGame()
{
	newGame = true;
}

bool Game::endGame(int p1, int p2)
{
	bool end = false;

	return end;
}

void Game::free()
{
	//Free loaded images

}

void Game::displayWinner(int p1, int p2, SDL_Color textColor, SDL_Renderer* gRenderer)
{
	std::string winnerText = "";

}
