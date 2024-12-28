#pragma once


#include "header.h"
#include <vector>

class Grid {
private:
	std::vector<bool> grid;
	static const int CELL_SIZE = 50;
	int gridWidth;
	int gridHeight;

public:
	Grid(int width, int height)
		:
		gridWidth(width),
		gridHeight(height),
		passable(true),
		playerPos{ 0, 0 } {
		grid.resize(width * height, false);
	}
	Vector2 playerPos;
	void update();
	void drawGame();
	void drawPlayer();
	bool getCell(int x, int y) const;
	void setCell(int x, int y, bool value);
	void generateRandomWalls(int seed, float wallChance);
	bool passable;
};