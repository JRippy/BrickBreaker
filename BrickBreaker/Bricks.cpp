#include "pch.h"
#include "Bricks.h"


Bricks::Bricks()
{
	vBricks.reserve(140);
	
	for (size_t i = 0; i < c.getBrickNum(); i++)
	{
		vBricksActive[i] = true;
	}
	
	previewColumn = -1;
	previewRow = -1;
	changeX = false;
	changeY = false;
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

bool Bricks::isCollide(float dotX, float dotY, float dotVelX, float dotVelY)
{
	if (dotY < (c.getScreenHeight() / 2 - 20))
	{

		int dotBrickx = (int)(dotX) / c.getBrickWidth();
		int dotBricky = (int)(dotY) / c.getBrickHeight();

		int numB = dotBrickx * 14 + dotBricky;

		if (numB < c.getBrickNum() && isActiv(numB))
		{
			desactiveBrick(numB);

			if (previewColumn == dotBrickx)
			{
				if (previewRow == dotBricky)
				{
					printf("Impossible");
				}
				else
				{
					changeX = true;
				}
			}
			else
			{
				if (previewColumn == dotBrickx)
				{
					changeY = true;
				}
				else
				{
					changeY = true;
					changeX = true;
				}
			}


			previewColumn = dotBrickx;
			previewRow = dotBricky;

			return true;
		}

		previewColumn = dotBrickx;
		previewRow = dotBricky;

		return false;
	}

	return false;
}

bool Bricks::isCollideBrick(float timeStep, SDL_Rect & square)
{
	return false;
}

void Bricks::activeBrick(int i)
{
	vBricksActive[i] = true;
}

void Bricks::desactiveBrick(int i)
{
	vBricksActive[i] = false;
}

bool Bricks::isActiv(int k)
{
	return vBricksActive[k];
}

bool Bricks::changeVelX()
{
	return changeX;
}

bool Bricks::changeVelY()
{
	return changeY;
}

void Bricks::reInitBoolVel()
{
	changeX = false;
	changeY = false;
}
