#include "Jogo.hpp"

SDL_Texture* playerTexture;
SDL_Rect scrR, destR;

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		//std::cout << "Subsystems Initialized..." << std::endl;

		window = SDL_CreateWindow(title, ypos, xpos, width, height, flags);
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 55, 0, 55, 255);
		}

		isRunning = true;
	}

	SDL_Surface* tempSurface = IMG_Load("char.png");
	playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

}

void Jogo::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
	}
}

void Jogo::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Jogo::update() {
	if (count == 255)
		clean();
	count++;

	destR.h = 32;
	destR.w = 32;
	destR.x = count;

	cout << count;
}

void Jogo::render() {
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 55, count, 55, 255);
	SDL_RenderCopy(renderer, playerTexture, NULL, &destR);
	
	SDL_RenderPresent(renderer);
}
