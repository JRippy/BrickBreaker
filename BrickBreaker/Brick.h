#pragma once
class Brick
{
public:
	Brick();
	Brick(int x, int y, int coord, int nmB);
	
	int posBX;
	int posBY;
	int coordinate;
	int numBrick;
	bool visible;
};

