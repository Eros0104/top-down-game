#pragma once

#include "../Game.h"
#include "EntityComponentSystem.h"
#include "SDL2/SDL.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"

class TileComponent : public Component {
public:
  TransformComponent *transform;
  SpriteComponent *sprite;

  SDL_Rect tileRect;
  int tileID;
  std::string path;

  TileComponent() = default;

  TileComponent(int x, int y, int w, int h, int id) {
    tileRect.x = x;
    tileRect.y = y;
    tileRect.h = h;
    tileRect.w = w;
    tileID = id;

    switch (tileID) {
    case 0:
      path = Game::assetPath + "textures/water.png";
      break;
    case 1:
      path = Game::assetPath + "textures/sand.png";
      break;
    case 2:
      path = Game::assetPath + "textures/grass.png";
      break;
    default:
      break;
    }
  }

  void init() override {
    entity->addComponent<TransformComponent>(
        (float)tileRect.x, (float)tileRect.y, (float)tileRect.w,
        (float)tileRect.h, 1);
    transform = &entity->getComponent<TransformComponent>();

    entity->addComponent<SpriteComponent>(path.c_str());
    sprite = &entity->getComponent<SpriteComponent>();
  }
};
