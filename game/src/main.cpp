#include "level.h"
#include "player.h"
#include "raylib.h"

void run(Player *player, Level *level);
void update(Player *player, Level *level);
void render(Player *player, Level *level);

int main(void) {
  const int screenWidth = 1200;
  const int screenHeight = 800;
  InitWindow(screenWidth, screenHeight, "Hell Yeah");

  Player player;
  initPlayer(&player);

  Level level;
  initLevel(&level, EmeraldHill);

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    run(&player, &level);
  }
  CloseWindow();

  return 0;
}

void run(Player *player, Level *level) {
  // Update
  update(player, level);

  // Draw
  BeginDrawing();
  render(player, level);
  EndDrawing();
}

void update(Player *player, Level *level) {
  updatePlayer(player);
  applyGravity(player);
  applyVelocityY(player);
  checkCollisionsY(player, level);
  checkCollisionsX(player, level);
  applyVelocityX(player);
}

void render(Player *player, Level *level) {
  ClearBackground(SKYBLUE);
  for (auto &tile : level->tileMap) {
    DrawRectangleRec(tile, BLUE);
  }
  drawPlayer(player);
}