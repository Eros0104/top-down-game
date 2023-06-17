#include "Jogo.h"

Jogo *jogo = nullptr;

int WinMain(int argc, char *argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / 60;

	Uint32 frameStart;
	int frameTime;

	jogo = new Jogo();

	jogo->init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (jogo->running())
	{

		frameStart = SDL_GetTicks();

		jogo->handleEvents();
		SDL_Delay(100);
		jogo->update();
		jogo->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	jogo->clean();
	return 0;
}