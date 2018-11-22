#pragma once
class Config
{
public:
	Config();

	static int getScreenHeight();
	static int getScreenWidth();

	static int getRacketHeight();
	static int getRacketWidth();
	static int getRacketVel();

	static int getDotHeight();
	static int getDotWidth();
	static int getDotVel();

private:

	//Screen dimension constants
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	//The dimensions of the dot
	static const int RACKET_WIDTH = 100;
	static const int RACKET_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int RACKET_VEL = 100;

	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 200;

};

