
extern "C" {
    #include "lib/raylib.h"
}

#include <iostream>
using namespace std;

int main()
{
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "title test m");

    SetTargetFPS(60);//limita de frameuri
    
    Texture2D guy = LoadTexture("resources/square.png");
    //default pos
    cout << screenWidth / 2;
    float guyx = screenWidth/2;
    float guyy = screenHeight/2;

    //ok
    int playerspeed;
    playerspeed = 5;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //cod----------------------------------------------------------------------
        
        if (IsKeyDown(KEY_W))
        {
            guyy=guyy-playerspeed;
            if(guyy>=1)
            {
                guyy = guyy + playerspeed;
            }
            
        }
        if (IsKeyDown(KEY_S))
        {
            guyy=guyy+playerspeed;
            if (guyy >= screenHeight)
            {
                guyy = guyy - playerspeed;
            }
        }
        if (IsKeyDown(KEY_D))
        {
            guyx=guyx+playerspeed;
        }
        if (IsKeyDown(KEY_A))
        {
            guyx=guyx-playerspeed;
        }



        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(guy, guyx, guyy, WHITE);
        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
        
    return 0;
}