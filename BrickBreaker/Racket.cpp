#include "pch.h"
#include "Config.h"
#include "Racket.h"


Racket::Racket() :
	rPosX((float)(c.getScreenWidth() / 2) - (c.getRacketWidth() / 2)),
	rPosY((float)(c.getScreenHeight() - (c.getRacketHeight())*2)),
	rVelY((float)c.getRacketVel())
{
}

Racket::Racket(float x, float y) :
	rVelY((float)c.getRacketVel())
{
	//Initialize the position
	rPosX = x;
	rPosY = y;
}

float Racket::getRPosX()
{
	return rPosX;
}

float Racket::getRPosY()
{
	return rPosY;
}

void Racket::handleEvent(SDL_Event& e, float timeStep)
{
	//If a key was pressed
	if (e.type == SDL_MOUSEMOTION && e.key.repeat == 0)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);

		if (x <= c.getRacketWidth() / 2)
		{
			rPosX = 0;
		}
		else if (rPosX > c.getScreenWidth() - (c.getRacketWidth() / 2) || x > c.getScreenWidth() - (c.getRacketWidth() / 2))
		{
			rPosX = (float)c.getScreenWidth() - (float)c.getRacketWidth();
		}
		else if (x < c.getScreenWidth() && x > 0)
		{
			//Adjust position
			rPosX = (float)x - c.getRacketWidth() / 2;
			//move(timeStep);
		}		
	}


}

void Racket::load()
{
	racket.w = c.getRacketWidth();
	racket.h = c.getRacketHeight();

}

void Racket::move(float timeStep)
{

	//If the racket went too far up or down
	if (rPosX < 0)
	{
		rPosX = 0;
	}
	else if (rPosX > c.getScreenWidth() - c.getScreenWidth())
	{
		rPosX = (float)c.getScreenWidth() - (float)c.getScreenWidth();
	}
	else 
	{

		//Move the racket left or right
		rPosX += rVelX * timeStep;

	}

}

void Racket::render(SDL_Renderer* gRenderer)
{
	racket.x = (int)rPosX;
	racket.y = (int)rPosY;

	//Render racket
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(gRenderer, &racket);
	SDL_RenderFillRect(gRenderer, &racket);

	//Show the Racket
	gRacketTexture.render((int)rPosX, (int)rPosY, gRenderer);
}

void Racket::free()
{
	gRacketTexture.free();
}