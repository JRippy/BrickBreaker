#pragma once
#include "Racket.h"
#include <vector>

class Bricks :
	public Racket
{
public:
	Bricks();

	void load();

	//Shows bricks on the screen
	void render(SDL_Renderer* gRenderer);

	void activeBrick();

	void desactiveBrick();

private:

	std::vector<int> vBricks;
	std::vector<bool> vBricksActive;

	//Texture
	Texture gBrickTexture;

};