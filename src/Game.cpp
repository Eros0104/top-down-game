#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "EntityComponentSystem/Components.h"
#include "Collision.h"

Map *map;
Manager manager;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent *> Game::colliders;

auto &player(manager.addEntity());
auto &wall(manager.addEntity());

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, ypos, xpos, width, height, flags);

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 55, 0, 55, 255);
		}

		isRunning = true;
	}

	map = new Map();

	Map::LoadMap("../src/assets/maps/default.map", 16, 16);

	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("../src/assets/player.png");
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");

	wall.addComponent<TransformComponent>(300.0f, 300.0f, 160, 16, 1);
	wall.addComponent<SpriteComponent>("../src/assets/textures/sand.png");
	wall.addComponent<ColliderComponent>("wall");
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::update()
{
	manager.refresh();
	manager.update();

	for (auto cc : colliders)
	{
		Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);

	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::AddTile(int id, int x, int y)
{
	auto &tile(manager.addEntity());
	tile.addComponent<TileComponent>(x, y, 32, 32, id);
}
