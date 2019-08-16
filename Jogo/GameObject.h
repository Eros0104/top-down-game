#pragma once
#include "Jogo.hpp"

class GameObject {
public:
	GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	int yPosition;
	int xPosition;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};