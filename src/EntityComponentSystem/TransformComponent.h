#pragma once
#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{

public:
	Vector2D position;
	Vector2D velocity;

	int height = 16;
	int width = 16;
	int scale = 2;

	int speed = 3;

	TransformComponent()
	{
		position.x = 0.0f;
		position.y = 0.0f;
	}

	TransformComponent(int sc)
	{
		position.x = 0.0f;
		position.y = 0.0f;
		scale = sc;
	}

	TransformComponent(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	TransformComponent(float x, float y, int h, int w, int sc)
	{
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
	}

	void init() override
	{
		velocity.x = 0;
		velocity.y = 0;
	}

	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};