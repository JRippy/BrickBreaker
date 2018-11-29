#include "Timer.h"
#include "Config.h"
#include "Texture.h"
#include <SDL.h>

#pragma once
class Racket
{
public:
	Racket();

	Racket(float x, float y);

	Config c;

	float getRPosX();
	float getRPosY();

	//Takes key presses and adjusts the racket's velocity
	void handleEvent(SDL_Event& e, float timeStep);

	//Load
	void load();

	//Moves the racket
	void move(float timeStep);

	//Shows the racket on the screen
	void render(SDL_Renderer* gRenderer);

	void free();
private:
	float rPosX, rPosY; // remplacer par sdl_rect
	float rVelX, rVelY;

	//Texture
	Texture gRacketTexture;

	SDL_Rect racket;
};

