#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "Mario Forensic Lab - Environment Test");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Raylib environment successfully installed!", 150, 200, 20, DARKGRAY);
        DrawRectangle(375, 250, 50, 50, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}