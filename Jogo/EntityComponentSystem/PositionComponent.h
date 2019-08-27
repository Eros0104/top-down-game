#pragma once
#include "Components.h"

class PositionComponent : public Component {
private:
	int xPosition;
	int yPosition;
public:
	int x() { return xPosition; }
	int y() { return yPosition; }

	PositionComponent() {
		xPosition = 0;
		yPosition = 0;
	}

	PositionComponent(int x, int y) {
		xPosition = x;
		yPosition = y;
	}

	void init() override {
		xPosition = 0;
		yPosition = 0;
	}

	void update() override {
		xPosition++;
		yPosition++;
	}

	void setPosition(int x, int y) {
		xPosition = x;
		yPosition = y;
	}
};