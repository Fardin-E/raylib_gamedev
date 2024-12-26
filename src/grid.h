#pragma once


#include "header.h"
#include <vector>

class Grid {
private:
	static const int CELL_SIZE = 50;
	int gridWidth;
	int gridHeight;
	std::vector<std::vector<bool>> grid;

public:
	Grid(int width, int height)
		:
		gridWidth(width),
		gridHeight(height),
		playerPos{ 0, 0 } {
		grid.resize(height, std::vector<bool>(width, false));
	}
	Vector2 playerPos;
	void update();
	void draw();
};