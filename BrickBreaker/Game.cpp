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

	racket = Racket();

	racket.load(gRenderer);

	//Calculate time step
	timeStep = stepTimer.getTicks() / 1000.f;

	//dl = DashedLine();
	//dl.load(gRenderer);

	dot = Dot(gRenderer);
	dot.loadMediaDot(gRenderer);


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
			racket.handleEvent(e, timeStep);

		}
	}
	return quit;
}

void Game::update()
{
	//Set the wall
	SDL_Rect wall;
	wall.x = racket.getRPosX();;
	wall.y = racket.getRPosY();;
	wall.w = c.getRacketWidth();
	wall.h = c.getRacketHeight();

	//Calculate time step
	timeStep = stepTimer.getTicks() / 1000.f;

	//Move for time step
	dot.move(timeStep, wall);

	//Restart step timer
	stepTimer.start();
}

void Game::draw(SDL_Renderer* gRenderer)
{
	//Render racket
	racket.render(gRenderer);
	dot.render(gRenderer);
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
	racket.free();
}

void Game::displayWinner(int p1, int p2, SDL_Color textColor, SDL_Renderer* gRenderer)
{
	std::string winnerText = "";
}
