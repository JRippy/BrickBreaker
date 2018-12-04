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

	Dot(float x, float y);

	Config c;

	//Initializes the variables
	Dot(SDL_Renderer * gRenderer);

	float getMPosX();
	float getMPosY();

	float getMVelX();
	float getMVelY();

	//load Media Dot
	bool loadMediaDot(SDL_Renderer* gRenderer);
	bool isLoaded();

	//Moves the dot and checks collision
	void move(float timeStep, SDL_Rect& square);

	void changeDirectionX();
	void changeDirectionY();

	//Shows the dot on the screen
	void render(SDL_Renderer* gRenderer);

	//Reset position initial
	void resetPosition();

	//Gets collision circle
	Circle& getCollider();

	//Gets collision
	bool checkCollision(Circle& a, SDL_Rect& b);

	double distanceSquared(int x1, int y1, int x2, int y2);

	//Debug
	void handleEvent(SDL_Event& e, float timeStep);
	void mousePress(SDL_MouseButtonEvent& b);

	void free();

private:
	bool Loaded;

	//The X and Y offsets of the dot
	float mPosX, mPosY;

	//The velocity of the dot
	float mVelX, mVelY;

	//Scene textures
	Texture gDotTexture;

	//Dot's collision circle
	Circle mCollider;

	//Moves the collision circle relative to the dot's offset
	void shiftColliders();

};

