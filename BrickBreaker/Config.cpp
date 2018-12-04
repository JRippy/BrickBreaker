#include "pch.h"
#include "Config.h"


Config::Config()
{
}


int Config::getScreenHeight()
{
	return SCREEN_HEIGHT;
}

int Config::getScreenWidth()
{
	return SCREEN_WIDTH;
}

int Config::getRacketHeight()
{
	return RACKET_HEIGHT;
}

int Config::getRacketWidth()
{
	return RACKET_WIDTH;
}

int Config::getRacketVel()
{
	return RACKET_VEL;
}


int Config::getDotHeight()
{
	return DOT_HEIGHT;
}

int Config::getDotWidth()
{
	return DOT_WIDTH;
}

int Config::getDotVel()
{
	return DOT_VEL;
}

int Config::getBrickHeight()
{
	return BRICK_HEIGHT;
}

int Config::getBrickWidth()
{
	return BRICK_WIDTH;
}

int Config::getBrickNum()
{
	return BRICK_NUM;
}
