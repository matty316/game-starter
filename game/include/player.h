#pragma once
#include "level.h"
#include "raylib.h"

typedef enum Direction {
  Left,
  Right,
} Direction;

typedef enum PlayerState {
  Ground,
  Air,
} PlayerState;

typedef struct Player {
  Vector2 velocity;
  Rectangle sprite;
  Direction direction;
  PlayerState state;
  int jumpCounter;
} Player;

void initPlayer(Player *player);
void updatePlayer(Player *player);
void applyVelocityY(Player *player);
void applyVelocityX(Player *player);
void applyGravity(Player *player);
void checkCollisionsX(Player *player, Level *level);
void checkCollisionsY(Player *player, Level *level);
void drawPlayer(Player *player);