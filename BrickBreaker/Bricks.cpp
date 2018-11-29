#include "pch.h"
#include "Bricks.h"


Bricks::Bricks()
{
	vBricks.reserve(140);
	vBricksActive.reserve(140);
	vBricksActive.resize(140, true);

}

void Bricks::load()
{
	int bricksColNum = 1;

	for (size_t i = 0; i < 800; i+=80)
	{
		for (size_t j = 0; j < 280; j+=20)
		{
			vBricks.push_back(i + bricksColNum * j);
			bricksColNum++;
		}
		
		bricksColNum = 0;
	}
}

void Bricks::render(SDL_Renderer * gRenderer)
{
	int bricksNum = 0;
	int bricksColNum = 1;
	int uniCoordinate = 0;

	for (size_t i = 0; i < 800; i += 80)
	{
		for (size_t j = 0; j < 280; j += 20)
		{

			if (vBricksActive[bricksNum] == true) {

				SDL_Rect racket;

				racket.x = i;
				racket.y = j;
				racket.w = c.getBrickWidth() - 2 ;
				racket.h = c.getBrickHeight()- 2;

				//Render racket
				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
				SDL_RenderDrawRect(gRenderer, &racket);
				SDL_RenderFillRect(gRenderer, &racket);

				//Show the Racket
				gBrickTexture.render(i, j, gRenderer);
			}

			uniCoordinate = i + bricksColNum * j;

			bricksColNum++;
			bricksNum++;
		}

		bricksColNum = 0;
	}
}

void Bricks::activeBrick()
{
}

void Bricks::desactiveBrick()
{
}
