#pragma once
#include "Components.h"
#include "../Vector2D.h"
#include <cmath>

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
		position.Zero();
	}

	TransformComponent(int sc)
	{
		position.Zero();
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
		velocity.Zero();
	}

	void update() override
	{
    // Normalize movement
    double h = sqrt(pow(velocity.x, 2) + pow(velocity.y, 2));
    if (h == 0) return;
    double normalizedX = velocity.x / h;
    double normalizedY = velocity.y / h;

		position.x += normalizedX * speed;
		position.y += normalizedY * speed;
	}
};
