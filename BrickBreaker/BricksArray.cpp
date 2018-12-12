#include "pch.h"
#include "BricksArray.h"


BricksArray::BricksArray()
{
	vBricks.reserve(c.getBrickNum());
	initBricks();
}

void BricksArray::load()
{
	int bricksColNum = 0;

	for (size_t j = 0; j < 280; j += 20)
	{	
		for (size_t i = 0; i < 800; i += 80)
		{

			Brick b = Brick(i, j, i + bricksColNum * j, (i / 80) + bricksColNum * (j / 20));

			vBricks.push_back(b);
			bricksColNum++;
		}

		bricksColNum = 0;
	}

	//Remove 3 first line
	for (size_t i = 0; i < 30; i++)
	{
		desactivateBrick(i);
	}
}

void BricksArray::render(SDL_Renderer * gRenderer)
{
	for (size_t bricksNum = 0; bricksNum < c.getBrickNum(); bricksNum++)
	{

		if (vBricks[bricksNum].visible == true) {

			SDL_Rect racket;

			racket.x = vBricks[bricksNum].posBX;
			racket.y = vBricks[bricksNum].posBY;
			racket.w = c.getBrickWidth() - 2 ;
			racket.h = c.getBrickHeight()- 2;

			//Render racket
			SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
			SDL_RenderDrawRect(gRenderer, &racket);
			SDL_RenderFillRect(gRenderer, &racket);

			//Show the Racket
			gBrickTexture.render(racket.x, racket.y, gRenderer);
		}

	}
}

bool BricksArray::isCollide(Circle& circle)
{
	if (circle.y < (c.getScreenHeight() / 2 - 20))
	{

		int dotBrickx = circle.x / c.getBrickWidth();
		int dotBricky = circle.y / c.getBrickHeight();

		int numB = dotBrickx + 10 * dotBricky;


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

				desactivateBrick(numB);
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

bool BricksArray::isCollideBrick(Circle& a, SDL_Rect& b)
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

double BricksArray::distanceSquared(int x1, int y1, int x2, int y2)
{
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;
	return deltaX * deltaX + deltaY * deltaY;
}

void BricksArray::activateBrick(int i)
{
	activeBrick++;
	desactiveBrick--;
	Brick& b = vBricks[i];
	b.visible = true;
}

void BricksArray::desactivateBrick(int i)
{
	Brick& b = vBricks[i];
	b.visible =  false;
	activeBrick--;
	desactiveBrick++;

	if (activeBrick <= 0 || desactiveBrick >= c.getBrickNum())
	{
		reinitBricks();
	}
}

bool BricksArray::isActiv(int k)
{
	return vBricks[k].visible;
}

bool BricksArray::changeVelX()
{
	return changeX;
}

bool BricksArray::changeVelY()
{
	return changeY;
}

void BricksArray::reInitBoolVel()
{
	changeX = false;
	changeY = false;
}

void BricksArray::initBricks()
{
	activeBrick = c.getBrickNum();
	desactiveBrick = 0;
	previewColumn = -1;
	previewRow = -1;
	changeX = false;
	changeY = false;
}

void BricksArray::reinitBricks()
{
	//Remove 30 first blocks
	//activeBrick = activeBrick - 30;
	//desactiveBrick = desactiveBrick + 30;
	for (size_t i = 30; i < c.getBrickNum(); i++)
	{
		activateBrick(i);
	}

	initBricks();
}
