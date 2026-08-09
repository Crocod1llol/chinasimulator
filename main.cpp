//this file houses the logic behind the player, the initialization of other files and logic of objects and stats
extern "C" {
    #include "lib/raylib.h"
}

#include <iostream>

//own headers
#include "src/headers/player.hpp"

#include "src/headers/general_parts.hpp"
#include "src/headers/home.hpp"
#include "src/headers/outside_home.hpp"
#include "src/headers/items.hpp"

//var to keep track of the room
//0 - home, 1 - outside home, more soon
int room = 0;

int main(void) { 

    const int screenWidth = 1000; 
    const int screenHeight = 800; 

    InitWindow(screenWidth, screenHeight, "title test m"); 
    InitAudioDevice();

    SetTargetFPS(60);//limita de frameuri 
                     
    //textures that i dont know where to put them so ill leave them in the main.cpp file cause yeah
    Texture2D container_6_slots = LoadTexture("resources/img/other/container_6_slots.png");

    //sfx
    Sound door_int = LoadSound("resources/sfx/door_int.ogg");

	//init
    init_player();
    init_items();

    //init places
    init_home();
    init_outside_home();

    // Main game loop
    while (!WindowShouldClose()) {

        //mouse hitbox
        //Rectangle mouseHitbox = {(float)GetMouseX(), (float)GetMouseY(), 20, 20};

        //PLAYER -----------------------------------------------------

        //player hitbox stays here so it updates
        guyHitbox = {guyX, guyY, guyWidth, guyHeight};
        
        //run player loop in main loop
        player_loop();


        //MAP OBEJCTS -----------------------------------------------------------------------
        
        //run map logic based on room
        switch (room) {

            //home
            case 0:


                //checks if player near object and he pressed "E"
                //using address so it modifies the actual object, not a copy of it
                for (long unsigned int i = 0; i < home_int_parts.size(); i++) {

                    //alias so i dont have to type home_int_parts.at(i) everytime
                    auto &a = home_int_parts.at(i);
                    
                    //set var based on if its colliding hitboxes and E being held
                    if (IsKeyDown(KEY_E) && CheckCollisionRecs(guyHitbox, a->hitbox)) {

                        a->isInteracted = true;

                        continue;

                    } else {

                        a->isInteracted = false;
                    }
                }

                //this is the door
                //and now we need to transport the player somewhere diferent
                if (CheckCollisionRecs(guyHitbox, outside_door_from_home.hitbox) && IsKeyPressed(KEY_E)) {

                     //sfx
                     PlaySound(door_int);
                     
                     //set pos to the other door 
                     guyX = outside_door_to_home.x;
                     //subtract guyHeight so it doesnt spawn in the door
                     guyY = outside_door_to_home.y - guyHeight;

                     //go to another room
                     room = 1;
                } 

                break;

            //outside of house
            case 1:

                //the door to home
                if (CheckCollisionRecs(guyHitbox, outside_door_to_home.hitbox) && IsKeyPressed(KEY_E)) {

                     //sfx
                     PlaySound(door_int);
                     
                     //set pos to the other door 
                     guyX = outside_door_from_home.x;
                     //add door height so it doesnt spawn in door
                     guyY = outside_door_from_home.y + outside_door_from_home.sizeY;

                     //go to another room
                     room = 0;
                }

                break;

            //if something somehow goes wrong
            default:
                std::cout << "switch_case_logic: game is sad, room var is modified \n";
                return -1;

        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(LIGHTGRAY);


        //render everything to its room
        switch (room) {

            //this is all part of room 0, aka home
            case 0:

                //draw all doors
                for (auto& i : home_doors) {

                     DrawTexture(i.tex, i.x, i.y, WHITE);
                }
            
                //draw all interactable parts
                for (auto &i : home_int_parts) {

                     DrawTexture(i->tex, i->x, i->y, WHITE);
                }
        
                //the "GUI" if you interacted with the cool object
                if (tester1.isInteracted) {


                    DrawTexture(container_6_slots, screenWidth/2 - (300 / 2), screenHeight/2 - (300 / 2), WHITE);
                }

                break;

            //outside of house
            case 1:

                //grass.
                DrawTexture(outside_home_grass, 0, 0, WHITE);

                //draw from vectors
                for (auto i : outside_home_parts) {
                    DrawTexture(i.tex, i.x, i.y, WHITE);
                }

                for (auto i: outside_exits) {

                    DrawTexture(i -> tex, i -> x, i -> y, WHITE);
                }

                break;

            //if it somehow goes wrong
            default:
                std::cout << "switch_case_draw: game is sad, room var is modified \n";
                return -1;
                break;

        }


        //draw all items.
        for (auto& i : spawned_items) {

            DrawTexture(i -> tex, i -> x, i -> y, WHITE);
        }


        //draw player here so he overlaps all
        DrawTexture(guyTex, guyX, guyY, WHITE);

        //the stat "menu"
        //temp: it is only the text of the stats, ill want it to be some sort of a bar or smth

        //this is the outline for the stat rec
        Rectangle stat_outline_rec = {(float)screenWidth - 225, 25, 200, 100};
        
        DrawRectangle(screenWidth - 225, 25, 200, 100, GRAY);
        DrawRectangleLinesEx(stat_outline_rec, 5, BLACK);

        DrawText(TextFormat("Health: %d", guyHp), screenWidth - 210, 40, 20, RED);
        DrawText(TextFormat("Hunger: %d", guyHunger), screenWidth - 210, 65, 20, ORANGE);

        //draw inv slots
        DrawTexture(inventorySlot, 25, 25, WHITE);

        //debug menu
        if (IsKeyDown(KEY_F3)) {

            DrawText(TextFormat("Mouse X: %d", GetMouseX()), 0, 5, 15, BLACK);
            DrawText(TextFormat("Mouse Y: %d", GetMouseY()), 0, 20, 15, BLACK);
        }

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
