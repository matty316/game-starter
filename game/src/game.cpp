#include "game.h"
#include "player.h"
#include "raylib.h"

void main() {
    run();
}

void run() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hell Yeah");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        updatePlayer();
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        drawPlayer();
        EndDrawing();
    }
    CloseWindow();
}
