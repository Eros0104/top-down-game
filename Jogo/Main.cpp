#include "Jogo.hpp"

Jogo *jogo = nullptr;

int main(int argc, char *argv[]) {
	jogo = new Jogo();

	jogo->init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (jogo->running()) {
		jogo->handleEvents();
		SDL_Delay(250);
		jogo->update();
		jogo->render();
	}

	jogo->clean();

	return 0;
}