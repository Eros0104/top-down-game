#include "Jogo.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "EntityComponentSystem.h"
#include "Component.h"

GameObject* player;
GameObject* enemy;
SDL_Renderer* Jogo::renderer = nullptr;
Map* map;

Manager manager;
auto& newPlayer(manager.addEntity());

Jogo::Jogo(){}

Jogo::~Jogo(){}

void Jogo::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, ypos, xpos, width, height, flags);
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 55, 0, 55, 255);
		}

		isRunning = true;
	}

	player = new GameObject("assets/char.png", 0, 0);
	enemy = new GameObject("assets/link.png", 60, 0);
	map = new Map();
	newPlayer.addComponent<PositionComponent>();
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
	player->Update();
	enemy->Update();
	manager.update();
	std::cout
		<< newPlayer.getComponent<PositionComponent>().x()
		<< ", "
		<< newPlayer.getComponent<PositionComponent>().y();
}

void Jogo::render() {
	SDL_RenderClear(renderer);
	map->DrawMap();
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}
