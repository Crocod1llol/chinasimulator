extern "C" {
    #include "lib/raylib.h"
}

#include <iostream>


int main(void) { 

    int screenWidth = 800; 
    int screenHeight = 600; 

    InitWindow(screenWidth, screenHeight, "title test m"); 

    SetTargetFPS(60);//limita de frameuri 
                                                                                                
    Texture2D guy = LoadTexture("resources/player.png"); 

    //guy base stats
    int guyHp = 100;
    int guyHunger = 100;



    //default pos 
    float guyx = screenWidth/2; 
    float guyy = screenHeight/2; 

    int playerspeed = 3;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //cod----------------------------------------------------------------------
        
        //vertical
        if (IsKeyDown(KEY_W))
        {
            guyy=guyy-playerspeed;

            //THIS IS WHERE I UPDATED IT.
            //it didnt work because "guyy >= 1", it checks if its greater than 1, which in this case it would quite always be
            if(guyy <= 5) 
            {
                guyy = guyy + playerspeed;
            }
            
        }
        if (IsKeyDown(KEY_S))
        {
            guyy=guyy+playerspeed;

            // n is the height of the texture so its not a single line
            // plus 5 for the invisible borde
            if (guyy >= screenHeight - (100 + 10))
            {
                guyy = guyy - playerspeed;
            }
        }

        //horizontal
        if (IsKeyDown(KEY_D))
        {
            guyx=guyx+playerspeed;

            //here, its the same deal as going down
            //the border is too far, so we modify by player width (100)
            if (guyx >= screenWidth - (100 + 10)) {

                guyx = screenWidth - (100 + 10);
            }
        }

        if (IsKeyDown(KEY_A))
        {
            guyx=guyx-playerspeed;

            //here its more simpler
            if (guyx <= 0 + 10) {

                guyx = 0 + 10;
            }
        }



        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(guy, guyx, guyy, WHITE);
        
        //the stat "menu"
        //temp: it is only the text of the stats, ill want it to be some sort of a bar or smth

        //this is the outline for the stat rec
        Rectangle stat_outline_rec = {(float)screenWidth - 225, 25, 200, 100};
        
        DrawRectangle(screenWidth - 225, 25, 200, 100, GRAY);
        DrawRectangleLinesEx(stat_outline_rec, 5, BLACK);

        DrawText(TextFormat("Health: %d", guyHp), screenWidth - 210, 40, 20, BLACK);
        DrawText(TextFormat("Hunger: %d", guyHunger), screenWidth - 210, 65, 20, BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
        
    return 0;
}
