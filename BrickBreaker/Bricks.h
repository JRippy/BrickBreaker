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
	void render(SDL_Renderer* gRenderer);

	bool isCollide(float dotX, float dotY, float dotVelX, float dotVelY);

	bool isCollideBrick(float timeStep, SDL_Rect& square);

	void activeBrick(int i);

	void desactiveBrick(int j);

	bool isActiv(int k);

	bool changeVelX();
	bool changeVelY();

	void reInitBoolVel();

private:

	std::vector<int> vBricks;
	bool vBricksActive[140];

	//Texture
	Texture gBrickTexture;

	int previewColumn;
	int previewRow;

	bool changeX;
	bool changeY;
};