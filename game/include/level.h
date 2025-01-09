#pragma once

#include "raylib.h"
#include <vector>

typedef enum LevelName { EmeraldHill, GreenHill, ChemicalPlant } LevelName;
typedef struct Level {
  LevelName name;
  std::vector<Rectangle> tileMap;
} Level;

void initLevel(Level *level, LevelName name);