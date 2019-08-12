#ifndef Jogo_hpp
#define Jogo_hpp

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
using namespace std;

class Jogo
{

public:
	Jogo();
	~Jogo();

	void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }
private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
	int count = 0;
};
#endif // !Jogo_hpp

