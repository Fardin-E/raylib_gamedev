#include "grid.h"
#include <random>

int main() {
	const float screenWidth = 1200;
	const float screenHeight = 800;
	const int gridWidth = screenWidth / 25;
	const int gridHeight = screenHeight / 25;


	int zoomMode = 0;

	InitWindow(screenWidth, screenHeight, "Window");


	Grid game(gridWidth, gridHeight);

	Camera2D camera = { 0 };
	camera.zoom = 1.0f;

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		// Translate based on mouse right click
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			Vector2 delta = GetMouseDelta();
			delta = Vector2Scale(delta, -1.0f / camera.zoom);
			camera.target = Vector2Add(camera.target, delta);
		}

		float wheel = GetMouseWheelMove();
		if (wheel != 0) {
			Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);

			camera.offset = GetMousePosition();

			camera.target = mouseWorldPos;

			float scaleFactor = 1.0f + (0.25f * fabs(wheel));
			if (wheel < 0) scaleFactor = 1.0f / scaleFactor;
			camera.zoom = Clamp(camera.zoom * scaleFactor, 0.125f, 64.0f);
		}

		game.update();

		BeginDrawing();

		BeginMode2D(camera);

		// camera.target = static_cast<Vector2> (game.playerPos.x + 20, game.playerPos.y + 20);
		
		game.drawGame();
		game.drawPlayer();
		game.generateRandomWalls(32, 0.3f);

		EndMode2D();

		DrawText("Use WASD to move", 10, screenHeight - 30, 20, DARKGRAY);
		DrawText("ESC to quit", screenWidth - 120, screenHeight - 30, 20, DARKGRAY);

		EndDrawing();

	}

	CloseWindow();


	return 0;
}