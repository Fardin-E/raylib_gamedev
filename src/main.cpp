#include "grid.h"

int main() {
	const float screenWidth = 1200;
	const float screenHeight = 800;
	const int gridWidth = screenWidth / 50;
	const int gridHeight = screenHeight / 50;

	InitWindow(screenWidth, screenHeight, "Window");

	SetTargetFPS(60);

	Grid game(gridWidth, gridHeight);

	while (!WindowShouldClose()) {

		game.update();

		BeginDrawing();
		
		game.draw();

		DrawText("Use WASD to move", 10, screenHeight - 30, 20, DARKGRAY);
		DrawText("ESC to quit", screenWidth - 120, screenHeight - 30, 20, DARKGRAY);

		EndDrawing();

	}

	CloseWindow();


	return 0;
}