extern "C" {
    #include "lib/raylib.h"
}

#include <iostream>
using std::cout; 

int main(void) { 

int screenWidth = 800; 
int screenHeight = 600; 

InitWindow(screenWidth, screenHeight, "title test m"); SetTargetFPS(60);//limita de frameuri 
                                                                                                
Texture2D guy = LoadTexture("resources/square.png"); //default pos 

float guyx = screenWidth/2; 
float guyy = screenHeight/2; 

int playerspeed = 5;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //cod----------------------------------------------------------------------
        
        if (IsKeyDown(KEY_W))
        {
            guyy=guyy-playerspeed;

            //THIS IS WHERE I UPDATED IT.
            //it didnt work because "guyy >= 1", it checks if its greater than 1, which in this case it would quite always be
            if(guyy <= 1) 
            {
                guyy = guyy + playerspeed;
            }
            
        }
        if (IsKeyDown(KEY_S))
        {
            guyy=guyy+playerspeed;

            // n is the height of the texture so its not a single line
            // plus 5 for the invisible border
            if (guyy >= screenHeight - (100 + 5))
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
