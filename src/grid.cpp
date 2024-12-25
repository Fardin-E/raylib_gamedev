#include "grid.h"

void Grid::update() {
	// store old position for validation
	Vector2 newPos = playerPos;

	// Handle input
	if (IsKeyPressed(KEY_W)) newPos.y--;
	if (IsKeyPressed(KEY_S)) newPos.y++;
	if (IsKeyPressed(KEY_A)) newPos.x--;
	if (IsKeyPressed(KEY_D)) newPos.x++;

	if (newPos.x >= 0 && newPos.x < gridWidth &&
		newPos.y >= 0 && newPos.y < gridHeight) {
		playerPos = newPos;
	}
}

void Grid::draw() {
	ClearBackground(RAYWHITE);

	// Draw grid
	for (int y = 0; y < gridHeight; y++) {
		for (int x = 0; x < gridWidth; x++) {
			// Calculate screen position
			Rectangle cellRect = {
				static_cast<float>(x * CELL_SIZE),
				static_cast<float>(y * CELL_SIZE),
				static_cast<float>(CELL_SIZE),
				static_cast<float>(CELL_SIZE),
			};
			
			// Draw cell border
			DrawRectangleLinesEx(cellRect, 1, LIGHTGRAY);
		}
	}

	// Draw player
	Rectangle playerRect = {
		playerPos.x * CELL_SIZE,
		playerPos.y * CELL_SIZE,
		CELL_SIZE,
		CELL_SIZE,
	};
	DrawRectangleRec(playerRect, BLUE);

	// Draw grid coordinates (optional, helpful for debugging)
	for (int y = 0; y < gridHeight; y++) {
		for (int x = 0; x < gridWidth; x++) {
			DrawText(TextFormat("%d,%d", x, y),
				x * CELL_SIZE + 5,
				y * CELL_SIZE + 5,
				10,
				GRAY);
		}
	}
}