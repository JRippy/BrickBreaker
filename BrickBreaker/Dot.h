#include "Timer.h"
#include "Config.h"
#include "Texture.h"
#include <SDL.h>
#include <math.h>

#pragma once

//A circle stucture
struct Circle
{
	int x, y;
	int r;
};

class Dot
{
public:

	Dot();

	Dot(int x, int y);

	Config c;

	//Initializes the variables
	Dot(SDL_Renderer * gRenderer);

	float getMPosX();
	float getMPosY();

	//load Media Dot
	bool loadMediaDot(SDL_Renderer* gRenderer);
	bool isLoaded();

	//Moves the dot and checks collision
	void move(float timeStep, SDL_Rect& square, Circle& circle);

	//Shows the dot on the screen
	void render(SDL_Renderer* gRenderer);

	//Reset position initial
	void resetPosition();

	//Gets collision circle
	Circle& getCollider();

	void free();

private:
	bool Loaded;

	//The X and Y offsets of the dot
	int mPosX, mPosY;

	//The velocity of the dot
	int mVelX, mVelY;

	//Scene textures
	Texture gDotTexture;

	//Dot's collision circle
	Circle mCollider;

	//Moves the collision circle relative to the dot's offset
	void shiftColliders();

	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 1;
};

