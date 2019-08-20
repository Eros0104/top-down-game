#pragma once
#include "Jogo.h"

class Map {
public:
	Map();
	~Map();

	void LoadMap(int lvl[20][20]);
	void DrawMap();

private:
	SDL_Rect src, dest;

	SDL_Texture* dirt;
	SDL_Texture* water;
	SDL_Texture* grass;

	int map[20][20];

};
