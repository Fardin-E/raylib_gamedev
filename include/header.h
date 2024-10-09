#pragma once

#include <iostream>
#include "raylib.h"
#include "raymath.h"

#define MAX_TEXTURES 2

// Declare the textures array
extern Texture2D textures[MAX_TEXTURES];

constexpr float TILE_WIDTH = 192;
constexpr float TILE_HEIGHT = 192;

struct sTile {
    float x;
    float y;

    sTile(float x_ = 0, float y_ = 0)
        : x(x_)
        , y(y_)
    {}
};

// Declare the DrawWarrior function
void DrawTile(float pos_x, float pos_y, float texture_index_x, float texture_index_y, int texture);
