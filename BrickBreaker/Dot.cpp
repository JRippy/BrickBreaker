#include "pch.h"
#include "Dot.h"


Dot::Dot()
{
}

Dot::Dot(SDL_Renderer * gRenderer) :
	mVelX((float)c.getDotVel()),
	mVelY((float)c.getDotVel()),
	Loaded(false)
{
	Loaded = loadMediaDot(gRenderer);
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

void Dot::move(float timeStep, SDL_Rect& square, Circle& circle)
{

	//Move the dot left or right
	mPosX += mVelX * timeStep;

	////If the dot went too far to the left or right
	//if (mPosX <= 0)
	//{
	//	mVelX = -mVelX;
	//	resetPosition();

	//}
	if (mPosY + c.getDotHeight() >= c.getScreenHeight())
	{
		mVelY = -mVelY;
		resetPosition();

	}

	//Move the dot up or down
	mPosY += mVelY * timeStep;

	//If the dot went too far up or down
	if (mPosY < 0)
	{
		mVelY = -mVelY;
	}
	else if (mPosY + c.getDotHeight() > c.getScreenHeight())
	{
		mVelY = -mVelY;
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
