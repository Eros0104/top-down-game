#pragma once
#include "Game.h"

class GameObject {
public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	int yPosition;
	int xPosition;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};