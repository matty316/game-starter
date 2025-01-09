#include "level.h"

void initTileMap(Level *level);
void loadLevel(Level *level, int width, int height, int *tileMap);

void initLevel(Level *level, LevelName name) {
  int tileMap[96];
  level->name = name;
  level->tileMap = {};
  initTileMap(level);
}

void initTileMap(Level *level) {
  switch (level->name) {
  case EmeraldHill: {
    const int width = 12;
    const int height = 8;
    // clang-format off
    static int emeraldHillTileMap[width * height] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };
    // clang-format on
    loadLevel(level, width, height, emeraldHillTileMap);
  }
  }
}

void loadLevel(Level *level, int width, int height, int *tileMap) {
  for (int i = 0; i < width * height; i++) {
    int x = i % width;
    int y = i / width;

    int tile = tileMap[i];
    if (tile > 0) {
      Rectangle rec = {
          .x = x * 100.0f, .y = y * 100.0f, .width = 100.0f, .height = 100.0f};
      level->tileMap.push_back(rec);
    }
  }
}