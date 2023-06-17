#pragma once
#include "Game.h"

class Map
{
public:
	Map();
	~Map();

	void LoadMap(int lvl[20][20]);
	void DrawMap();

private:
	SDL_Rect src, dest;

	SDL_Texture *sand;
	SDL_Texture *water;
	SDL_Texture *grass;

	int map[20][20];
};
