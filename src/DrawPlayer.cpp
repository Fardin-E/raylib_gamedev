#include "header.h"



void DrawWarrior(float pos_x, float pos_y, float texture_index_x, float texture_index_y) {
    Rectangle source = { (PLAYER_TILE_WIDTH * texture_index_x), (PLAYER_TILE_HEIGHT * texture_index_y), PLAYER_TILE_WIDTH, PLAYER_TILE_HEIGHT };
    Rectangle dest = { (pos_x), (pos_y), PLAYER_TILE_WIDTH, PLAYER_TILE_HEIGHT };
    Vector2 origin = { 0, 0 };
    DrawTexturePro(textures[0], source, dest, origin, 0.0f, RAYWHITE);  // Access global textures array
}
