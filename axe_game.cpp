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
    //Circle Edges
    int l_circle_X = circle_X - circle_radius;
    int r_circle_X = circle_X + circle_radius;
    int u_circle_Y = circle_Y - circle_radius;
    int b_circle_Y = circle_Y + circle_radius;


    //Rectangle
    int rec_X = 360;
    int rec_Y = 120;
    int rec_length = 50;
    //Rectangle Edges 
    int l_rec_X = rec_X;
    int r_rec_X = rec_X + rec_length;
    int u_rec_Y = rec_Y;
    int b_rec_Y = rec_Y + rec_length;

    int velocity = 10;
    bool collision_with_rec = (b_rec_Y >= u_circle_Y) && (u_rec_Y <= b_circle_Y) && (r_rec_X >= l_circle_X) && (l_rec_X <= r_circle_X);


    InitWindow(width, height, "Fetus");

    SetTargetFPS(60);

    while(WindowShouldClose() != true)
    {
        BeginDrawing();
        ClearBackground(ORANGE);

        if(collision_with_rec == true)
        {
            DrawText("Game Over", 240, 240, 20, RED);
        }
        else 
        {
            // Game Logic Starts

            //Update edges
            l_circle_X = circle_X - circle_radius;
            r_circle_X = circle_X + circle_radius;
            u_circle_Y = circle_Y - circle_radius;
            b_circle_Y = circle_Y + circle_radius;

            l_rec_X = rec_X;
            r_rec_X = rec_X + rec_length;
            u_rec_Y = rec_Y;
            b_rec_Y = rec_Y + rec_length;
            
            //Update collision
            collision_with_rec = (b_rec_Y >= u_circle_Y) && (u_rec_Y <= b_circle_Y) && (r_rec_X >= l_circle_X) && (l_rec_X <= r_circle_X);

            DrawCircle(circle_X, circle_Y, circle_radius, BLUE);
            DrawRectangle(rec_X, rec_Y, rec_length, rec_length, RED);

            rec_Y += velocity;

            if(rec_Y > height || rec_Y < 0)
            {
                velocity = -velocity;
            }

            if(IsKeyDown(KEY_D) && circle_X < width)
            {
                circle_X += 10;
            }

            if(IsKeyDown(KEY_A) && circle_X > 0)
            {
                circle_X -= 10;
            }

            // Game logic ends
        }

        EndDrawing();
    }  
}