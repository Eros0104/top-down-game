#pragma once
#include "EntityComponentSystem.h"

class PositionComponent : public Component{
private:
	int xPosition = 0;
	int yPosition = 0;
public:
	int x() { return xPosition; }
	int y() { return yPosition; }

	void init() override {
		xPosition = 0;
		yPosition = 0;
	}

	void update() override{
		xPosition++;
		yPosition++;
	}

	void setPosition(int x, int y) {
		xPosition = x;
		yPosition = y;
	}
};

