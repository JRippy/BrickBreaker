#pragma once
#include "Dot.h"
#include "Racket.h"
#include "Brick.h"
#include "Config.h"
#include <vector>

class BricksArray : public Racket
{
public:

	Config c;

	BricksArray();

	void load();

	//Shows bricks on the screen
	void render(SDL_Renderer* gRenderer);

	bool isCollide(Circle& c);

	bool isCollideBrick(Circle& a, SDL_Rect& b);

	double distanceSquared(int x1, int y1, int x2, int y2);

	void activateBrick(int i);

	void desactivateBrick(int j);

	bool isActiv(int k);

	bool changeVelX();
	bool changeVelY();

	void reInitBoolVel();

	void initBricks();
	void reinitBricks();

private:

	std::vector<Brick> vBricks;
	int activeBrick;
	int desactiveBrick;

	//Texture
	Texture gBrickTexture;

	int previewColumn;
	int previewRow;

	bool changeX;
	bool changeY;
};