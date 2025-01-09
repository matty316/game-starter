#include "player.h"

void initPlayer(Player *player) {
  player->sprite = {.x = 0.0f, .y = 0.0f, .width = 100.0f, .height = 100.0f};
  player->velocity = {.x = 0.0f, .y = 0.0f};
  player->direction = Left;
  player->jumpCounter = 0;
}
void updatePlayer(Player *player) {
  if (player->state == Ground) {
    player->velocity.x = 0.0f;
  }
  static float velocity = 200.0f;
  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
    player->velocity.x = -velocity;
    player->direction = Left;
  }
  if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
    player->velocity.x = velocity;
    player->direction = Right;
  }

  static float jumpForce = 500.0f;
  if (IsKeyPressed(KEY_SPACE) && player->jumpCounter < 2) {
    player->velocity.y = -jumpForce;
    player->jumpCounter += 1;
    player->state = Air;
  }
}

void applyVelocityY(Player *player) {
  player->sprite.y += player->velocity.y * GetFrameTime();
}

void applyVelocityX(Player *player) {
  player->sprite.x += player->velocity.x * GetFrameTime();
}

void applyGravity(Player *player) {
  static float gravity = 1000.0f;
  player->velocity.y += gravity * GetFrameTime();
  static float maxVel = 1500.0f;
  if (player->velocity.y > maxVel) {
    player->velocity.y = maxVel;
  }
}

void checkCollisionsX(Player *player, Level *level) {
  for (auto &tile : level->tileMap) {
    if (CheckCollisionRecs(player->sprite, tile)) {
      if (player->sprite.x > tile.x) {
        player->sprite.x = tile.x + tile.width;
      } else {
        player->sprite.x = tile.x - tile.width;
      }
    }
  }
}

void checkCollisionsY(Player *player, Level *level) {
  for (auto &tile : level->tileMap) {
    if (CheckCollisionRecs(player->sprite, tile)) {
      if (player->sprite.y > tile.y) {
        player->sprite.y = tile.y + tile.height;
      } else {
        player->sprite.y = tile.y - tile.height;
      }
      player->state = Ground;
      player->jumpCounter = 0;
    }
  }
}

void drawPlayer(Player *player) { DrawRectangleRec(player->sprite, RED); }