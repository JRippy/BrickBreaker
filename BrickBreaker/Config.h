#pragma once
class Config
{
public:
	Config();

	static int getScreenHeight();
	static int getScreenWidth();

private:

	//Screen dimension constants
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

};

