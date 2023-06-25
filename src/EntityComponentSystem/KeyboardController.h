#pragma once

#include "../Game.h"
#include "EntityComponentSystem.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
  TransformComponent *transform;

  void init() override
  {
    transform = &entity->getComponent<TransformComponent>();
  }

  void update() override
  {
    if (Game::event.type == SDL_KEYDOWN)
    {
      handleKeyPress();
    }
    else if (Game::event.type == SDL_KEYUP)
    {
      handleKeyRelease();
    }
  }

private:
  void handleKeyPress()
  {
    switch (Game::event.key.keysym.sym)
    {
    case SDLK_w:
      transform->velocity.y = -1;
      break;

    case SDLK_a:
      transform->velocity.x = -1;
      break;

    case SDLK_s:
      transform->velocity.y = 1;
      break;

    case SDLK_d:
      transform->velocity.x = 1;
      break;

    default:
      break;
    }
  }

  void handleKeyRelease()
  {
    switch (Game::event.key.keysym.sym)
    {
    case SDLK_w:
      transform->velocity.y = getUpdatedVelocityY();
      break;

    case SDLK_a:
      transform->velocity.x = getUpdatedVelocityX();
      break;

    case SDLK_s:
      transform->velocity.y = getUpdatedVelocityY();
      break;

    case SDLK_d:
      transform->velocity.x = getUpdatedVelocityX();
      break;

    default:
      break;
    }
  }

  int getUpdatedVelocityX()
  {
    int xVelocity = 0;

    if (Game::event.key.keysym.sym == SDLK_a && SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_D])
    {
      xVelocity = 1;
    }
    else if (Game::event.key.keysym.sym == SDLK_d && SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_A])
    {
      xVelocity = -1;
    }

    return xVelocity;
  }

  int getUpdatedVelocityY()
  {
    int yVelocity = 0;

    if (Game::event.key.keysym.sym == SDLK_w && SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_S])
    {
      yVelocity = 1;
    }
    else if (Game::event.key.keysym.sym == SDLK_s && SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_W])
    {
      yVelocity = -1;
    }

    return yVelocity;
  }
};