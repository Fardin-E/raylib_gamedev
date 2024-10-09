#include "header.h"



void DrawTile(float pos_x, float pos_y, float texture_index_x, float texture_index_y, int texture) {
    Rectangle source = { (TILE_WIDTH * texture_index_x), (TILE_HEIGHT * texture_index_y), TILE_WIDTH, TILE_HEIGHT };
    Rectangle dest = { (pos_x), (pos_y), TILE_WIDTH, TILE_HEIGHT };
    Vector2 origin = { 0, 0 };
    DrawTexturePro(textures[texture], source, dest, origin, 0.0f, RAYWHITE);  // Access global textures array
}
