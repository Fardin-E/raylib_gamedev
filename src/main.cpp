#include "header.h"

const int screenWidth = 1200;
const int screenHeight = 900;

constexpr int WORLD_WIDTH = 960;
constexpr int WORLD_HEIGHT = 960;

Texture2D textures[MAX_TEXTURES];  // Definition of the textures array

sTile world[WORLD_WIDTH][WORLD_HEIGHT];

sTile player;

static void GameStartup() {

	Image warrior_img = LoadImage("assets/Warrior_Red.png");
	textures[0] = LoadTextureFromImage(warrior_img);
	UnloadImage(warrior_img);

	Image tile_img = LoadImage("assets/Tilemap_Flat.png");
	textures[1] = LoadTextureFromImage(tile_img);
	UnloadImage(tile_img);

	/*for (int i = 0; i < WORLD_WIDTH; i++) {
		for (int j = 0; j < WORLD_HEIGHT; j++) {
			world[i][j] = sTile(i, j);
		}
	}*/

	// x, y position of the player
	player.x = PLAYER_TILE_WIDTH; 
	player.y = PLAYER_TILE_HEIGHT;

}


static void GameUpdate() {
	
}

static void GameRender() {
	DrawWarrior(player.x, player.y, 0, 0);

	sTile tile;
	int texture_index_x = 0;
	int texture_index_y = 0;

	for (int i = 0; i < WORLD_WIDTH; i++) {
		for (int j = 0; j < WORLD_HEIGHT; j++) {
			tile = world[i][j];

			
		}
	}
}

static void GameShutdown() {
	for (int i = 0; i < MAX_TEXTURES; i++) {
		UnloadTexture(textures[i]);
	}
}

int main() {
	InitWindow(screenWidth, screenHeight, "Raylib Gamedev");
	SetTargetFPS(60);

	GameStartup();

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(GRAY);

		GameRender();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}