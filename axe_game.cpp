#include "raylib.h"

int main()
{
    //Window
    int width = 480;
    int height = 480;

    //Circle
    int circle_X = 240;
    int circle_Y = 240;
    int circle_radius = 25;

    //Rectangle
    int rec_X = 220;
    int rec_Y = 240;


    InitWindow(width, height, "Fetus");

    SetTargetFPS(60);

    while(WindowShouldClose() != true)
    {
        BeginDrawing();
        ClearBackground(ORANGE);

        // Game Logic Starts

        DrawCircle(circle_X, circle_Y, circle_radius, BLUE);
        DrawRectangle(rec_X, rec_Y, , 120, RED);

        if(IsKeyDown(KEY_D) && circle_X < width)
        {
            circle_X += 10;
        }

        if(IsKeyDown(KEY_A) && circle_X > 0)
        {
            circle_X -= 10;
        }

        // Game logic ends

        EndDrawing();
    }  
}