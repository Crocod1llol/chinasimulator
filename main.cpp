extern "C" {
    #include "lib/raylib.h"
}

#include <iostream>

//own headers
#include "src/headers/general_parts.hpp"
#include "src/headers/home.hpp"

//var to keep track of the room
//0 - home, 1 - outside home, more soon
int room = 0;

int main(void) { 

    const int screenWidth = 800; 
    const int screenHeight = 600; 

    InitWindow(screenWidth, screenHeight, "title test m"); 
    InitAudioDevice();

    SetTargetFPS(60);//limita de frameuri 
                     
    //sfx
    Sound door_int = LoadSound("resources/sfx/door_int.ogg");
                                                                                                
    Texture2D guyTex = LoadTexture("resources/img/player.png"); 

    //guy base stats
    int guyHp = 100;
    int guyHunger = 100;

    //default pos 
    float guyX = screenWidth/2; 
    float guyY = screenHeight/2; 

    //size
    const float guyWidth = 100;
    const float guyHeight = 100;

    int playerspeed = 3;

    //the default room is home, so init home
    init_home();   

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //cod----------------------------------------------------------------------
        
        //player hitbox stays here so it updates
        Rectangle guyHitbox = {guyX, guyY, guyWidth, guyHeight};
        
        //vertical
        if (IsKeyDown(KEY_W))
        {
            guyY=guyY-playerspeed;

            //THIS IS WHERE I UPDATED IT.
            //it didnt work because "guyy >= 1", it checks if its greater than 1, which in this case it would quite always be
            if(guyY <= 5) 
            {
                guyY = guyY + playerspeed;
            }
            
        }
        if (IsKeyDown(KEY_S))
        {
            guyY=guyY+playerspeed;

            // n is the height of the texture so its not a single line
            // plus 5 for the invisible borde
            if (guyY >= screenHeight - (100 + 10))
            {
                guyY = guyY - playerspeed;
            }
        }

        //horizontal
        if (IsKeyDown(KEY_D))
        {
            guyX=guyX+playerspeed;

            //here, its the same deal as going down
            //the border is too far, so we modify by player width (100)
            if (guyX >= screenWidth - (100 + 10)) {

                guyX = screenWidth - (100 + 10);
            }
        }

        if (IsKeyDown(KEY_A))
        {
            guyX=guyX-playerspeed;

            //here its more simpler
            if (guyX <= 0 + 10) {

                guyX = 0 + 10;
            }
        }

        //check if room is home
        if (room == 0) {

            //checks if player near object and he pressed "E"
            for (auto i : int_parts) {
                if (CheckCollisionRecs(guyHitbox, i.hitbox) && IsKeyDown(KEY_E)) {

                      i.isInteracted = true;
                } else {

                      i.isInteracted = false;
                }
            }

            //this is the door
            //and now we need to transport the player somewhere diferent
            if (CheckCollisionRecs(guyHitbox, outside_door_from_home.hitbox) && IsKeyDown(KEY_E)) {

                //sfx
                PlaySound(door_int);

                //go to another room
                room = 1;
            } 
        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        DrawTexture(guyTex, guyX, guyY, WHITE);

        //this is all part of room 0, aka home
        if (room == 0) {

            //draw all doors
            for (auto i : doors) {

                DrawTexture(i.tex, i.x, i.y, WHITE);
            }
            
            //draw all interactable parts
            for (auto i : int_parts) {

                DrawTexture(i.tex, i.x, i.y, WHITE);
            }
        
            //the "GUI" if you interacted with the object
            if (tester1.isInteracted) {

                //btw so they are on the middle, i divide by 2 on the pos based on the width and height
                DrawRectangle(screenWidth/2 - (300 / 2), screenHeight/2 - (200 / 2), 300, 200, GRAY);;

                DrawRectangleLinesEx((Rectangle){screenWidth/2 - (300 / 2), screenHeight/2 - (200 / 2), 300, 200}, 5, BLACK);
            }

        }

        //the stat "menu"
        //temp: it is only the text of the stats, ill want it to be some sort of a bar or smth

        //this is the outline for the stat rec
        Rectangle stat_outline_rec = {(float)screenWidth - 225, 25, 200, 100};
        
        DrawRectangle(screenWidth - 225, 25, 200, 100, GRAY);
        DrawRectangleLinesEx(stat_outline_rec, 5, BLACK);

        DrawText(TextFormat("Health: %d", guyHp), screenWidth - 210, 40, 20, RED);
        DrawText(TextFormat("Hunger: %d", guyHunger), screenWidth - 210, 65, 20, ORANGE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    CloseAudioDevice();
    //--------------------------------------------------------------------------------------
        
    return 0;
}
