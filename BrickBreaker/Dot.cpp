#include "pch.h"
#include "Dot.h"


Dot::Dot() :
	mVelX((float)c.getDotVel()),
	mVelY((float)c.getDotVel())
{
	resetPosition();
}

Dot::Dot(float x, float y) :
	mVelX((float)c.getDotVel()),
	mVelY((float)c.getDotVel())
{
	mPosX = x;
	mPosY = y;
}

Dot::Dot(SDL_Renderer * gRenderer) :
	mVelX((float)c.getDotVel()),
	mVelY((float)c.getDotVel()),
	Loaded(false)
{
	resetPosition();

	Loaded = loadMediaDot(gRenderer);

	//Set collision circle size
	mCollider.r = c.getDotWidth() / 2;

	//Move collider relative to the circle
	shiftColliders();
}

float Dot::getMPosX()
{
	return mPosX;
}

float Dot::getMPosY()
{
	return mPosY;
}

bool Dot::loadMediaDot(SDL_Renderer * gRenderer)
{
	//Loading success flag
	Loaded = true;

	//Load dot texture
	if (!gDotTexture.loadFromFile("dot.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		Loaded = false;
	}

	return Loaded;
}

bool Dot::isLoaded()
{
	return Loaded;
}

void Dot::move(float timeStep, SDL_Rect& square)
{
	float dotYMiddle = mPosX + (c.getDotWidth() / 2);

	//Move the dot left or right
	mPosX += mVelX * timeStep;
	shiftColliders();

	////If the dot went too far to the left or right
	if (mPosX + c.getDotWidth() >= c.getScreenWidth() || mPosX < 0)
	{
		mVelX = -mVelX;
		shiftColliders();
		//resetPosition();
	}


	//Move the dot up or down
	mPosY += mVelY * timeStep;
	shiftColliders();

	//If the dot went too far up or down
	if (mPosY <= 0)
	{
		mVelY = -mVelY;
		shiftColliders();
	}

	if (mPosY + c.getDotHeight() >= c.getScreenHeight())
	{
		resetPosition();
	}

	if (checkCollision(mCollider, square))
	{
		const float Pi = 3.141592654f;
		float MAXBOUNCEANGLE = 6 * Pi / 12;

		float relativeIntersectX = (mPosX + (c.getRacketWidth() / 2)) - dotYMiddle;
		float normalizedRelativeIntersectionX = (relativeIntersectX / (c.getRacketWidth() / 2));
		float bounceAngle = normalizedRelativeIntersectionX * MAXBOUNCEANGLE;

		mVelX = -mVelX;
		//mVelY = -mVelY;
		mVelY = -mVelY * sin(bounceAngle);

		//printf("Paddle mVelX : %f + mVelY : %f \n", mVelX, mVelY);
		printf("Vitesse Y : %f\n", -mVelY);
		printf("New Vitesse Y : %f\n", mVelY * sin(bounceAngle));
		printf("bounclAngle : %f\n", bounceAngle);
		printf("Sin bounclAngle : %f\n", sin(bounceAngle));
		printf("Cos bounclAngle : %f\n", cos(bounceAngle));
		printf("Relative bounclAngle : %f\n", normalizedRelativeIntersectionX);
	}
}

void Dot::render(SDL_Renderer* gRenderer)
{
	//Load dot texture
	if (!gDotTexture.loadFromFile("dot.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
	}

	//Show the dot
	gDotTexture.render((int)mPosX, (int)mPosY, gRenderer);
}

void Dot::resetPosition() {
	//Initialize the position
	mPosX = (float)c.getScreenWidth() / 2 - (float)c.getDotWidth();
	mPosY = (float)c.getScreenHeight() / 2 - (float)c.getDotHeight();
}

Circle & Dot::getCollider()
{
	return mCollider;
}

void Dot::shiftColliders()
{
	//Align collider to center of dot
	mCollider.x = mPosX + (c.getDotHeight() / 2);
	mCollider.y = mPosY + (c.getDotWidth() / 2);
}


bool Dot::checkCollision(Circle& a, SDL_Rect& b)
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


double Dot::distanceSquared(int x1, int y1, int x2, int y2)
{
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;
	return deltaX * deltaX + deltaY * deltaY;
}

void Dot::free()
{
	gDotTexture.free();
}
