#pragma once
#include "Dot.h"
#include "Racket.h"
#include <vector>

class Bricks :
	public Racket
{
public:
	Bricks();

	void load();

	//Shows bricks on the screen
	void render(SDL_Renderer* gRenderer, float dotX, float dotY);

	void activeBrick(int i);

	void desactiveBrick(int i);

private:

	std::vector<int> vBricks;
	std::vector<bool> vBricksActive;

	//Texture
	Texture gBrickTexture;

};