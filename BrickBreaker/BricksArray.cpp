#include "pch.h"
#include "BricksArray.h"


Bricks::Bricks()
{
	vBricks.reserve(140);
	initBricks();
}

void Bricks::load()
{
	int bricksColNum = 1;

	for (size_t i = 0; i < 800; i+=80)
	{
		for (size_t j = 0; j < 280; j+=20)
		{
			Brick b = Brick(i + bricksColNum * j, (i / 80) + bricksColNum * (j / 20));

			vBricks.push_back(b);
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

bool Bricks::isCollide(Circle& circle)
{
	if (circle.y < (c.getScreenHeight() / 2 - 20))
	{

		int dotBrickx = circle.x / c.getBrickWidth();
		int dotBricky = circle.y / c.getBrickHeight();

		int numB = dotBrickx * 14 + dotBricky;


		//Test Collide with refact----------------------------------
		SDL_Rect test;

		test.x = dotBrickx * 80;
		test.y = dotBricky * 20;
		test.w = c.getBrickWidth() - 2;
		test.h = c.getBrickHeight() - 2;

		//printf("Bool collide %d/n", isCollideBrick(circle, test));
		//-------------------------------------------------------------


		if (numB < c.getBrickNum())
		{
			if (isActiv(numB) && isCollideBrick(circle, test))
			{

				if (previewColumn == dotBrickx)
				{
					if (previewRow != dotBricky)
					{
						changeY = true;
					}
				}
				else
				{
					if (previewRow == dotBricky)
					{
						changeX = true;
					}
					else
					{
						changeY = true;
						changeX = true;
					}
				}

				desactiveBrick(numB);
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

bool Bricks::isCollideBrick(Circle& a, SDL_Rect& b)
{
	//Closest point on collision box
	int cX, cY;

	//Find closest x offset
	if (a.x < b.x)
	{
		cX = b.x;
	}
	else if (a.x > b.x + b.w)
	{
		cX = b.x + b.w;
	}
	else
	{
		cX = a.x;
	}

	//Find closest y offset
	if (a.y < b.y)
	{
		cY = b.y;
	}
	else if (a.y > b.y + b.h)
	{
		cY = b.y + b.h;
	}
	else
	{
		cY = a.y;
	}

	//If the closest point is inside the circle
	if (distanceSquared(a.x, a.y, cX, cY) <= a.r * a.r)
	{
		//This box and the circle have collided
		return true;
	}

	//If the shapes have not collided
	return false;
}

double Bricks::distanceSquared(int x1, int y1, int x2, int y2)
{
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;
	return deltaX * deltaX + deltaY * deltaY;
}

void Bricks::activateBrick(int i)
{
	activeBrick++;
	vBricksActive[i] = true;
}

void Bricks::desactiveBrick(int i)
{
	vBricksActive[i] = false;
	activeBrick--;

	if (activeBrick == 0)
	{
		initBricks();
	}
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

void Bricks::initBricks()
{
	activeBrick = c.getBrickNum();

	for (size_t i = 0; i < c.getBrickNum(); i++)
	{
		vBricksActive[i] = true;
	}

	previewColumn = -1;
	previewRow = -1;
	changeX = false;
	changeY = false;
}
