#include "Game.h"
#include "Collision.h"
#include "EntityComponentSystem/Components.h"
#include "Map.h"
#include "TextureManager.h"
#include <cstddef>
#include <unistd.h>

Map *map;
Manager manager;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent *> Game::colliders;
std::string Game::assetPath;

auto &player(manager.addEntity());
auto &wall(manager.addEntity());

enum groupLabels : std::size_t
{
  groupMap,
  groupPlayers,
  groupEnemies,
  groupColliders
};

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {

  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  std::cout << "CWD:" << cwd << std::endl;
  int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    window = SDL_CreateWindow(title, ypos, xpos, width, height, flags);

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 55, 0, 55, 255);
    }

    char* basePath = SDL_GetBasePath();
    assetPath = std::string(basePath) + "../assets/";
    SDL_free(basePath);

    isRunning = true;
  }

  map = new Map();

  Map::LoadMap(assetPath + "maps/default.map", 16, 16);

  player.addComponent<TransformComponent>(3);
  player.addComponent<SpriteComponent>((assetPath + "player.png").c_str());
  player.addComponent<KeyboardController>();
  player.addComponent<ColliderComponent>("player");
  player.addGroup(groupPlayers);

  wall.addComponent<TransformComponent>(300.0f, 300.0f, 160, 16, 1);
  wall.addComponent<SpriteComponent>((assetPath + "textures/sand.png").c_str());
  wall.addComponent<ColliderComponent>("wall");
  wall.addGroup(groupColliders);
}

void Game::handleEvents() {
  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT:
    isRunning = false;
    break;

  default:
    break;
  }
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void Game::update() {
  manager.refresh();
  manager.update();

  for (auto cc : colliders) {
    Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
  }
}

auto& players(manager.getGroup(groupPlayers));
auto& tiles(manager.getGroup(groupMap));
auto& enemies(manager.getGroup(groupEnemies));
auto& walls(manager.getGroup(groupColliders));

void Game::render() {
  SDL_RenderClear(renderer);

  for (auto& t : tiles) 
  {
    t->draw();
  }
  for (auto& e : enemies)
  {
    e->draw();
  }
  for (auto& p : players) 
  {
    p->draw();
  }
  for (auto& c : colliders) 
  {
    c->draw();
  }

  SDL_RenderPresent(renderer);
}

void Game::AddTile(int id, int x, int y) {
  std::cout << id << std::endl;
  auto &tile(manager.addEntity());
  tile.addComponent<TileComponent>(x, y, 32, 32, id);
  tile.addGroup(groupMap);
}
