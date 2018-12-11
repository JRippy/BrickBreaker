#pragma once
#include "Dot.h"
#include "Racket.h"
#include "Brick.h"
#include "Config.h"
#include <vector>

class Bricks :
	public Racket
{
public:

	Config c;

	Bricks();

	void load();

	//Shows bricks on the screen
	void render(SDL_Renderer* gRenderer);

	bool isCollide(Circle& c);

	bool isCollideBrick(Circle& a, SDL_Rect& b);

	double distanceSquared(int x1, int y1, int x2, int y2);

	void activateBrick(int i);

	void desactiveBrick(int j);

	bool isActiv(int k);

	bool changeVelX();
	bool changeVelY();

	void reInitBoolVel();

	void initBricks();

private:

	std::vector<Brick> vBricks;
	bool vBricksActive[140];
	int activeBrick;

	//Texture
	Texture gBrickTexture;

	int previewColumn;
	int previewRow;

	bool changeX;
	bool changeY;
};