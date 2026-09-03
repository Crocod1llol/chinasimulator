//this file has the initialization of other files and logic of objects and stats
extern "C" {
    #include "lib/raylib.h"
}

#include <iostream>
#include <string.h>

//own headers
#include "src/headers/player.hpp"
#include "src/headers/general_parts.hpp"
#include "src/headers/home.hpp"
#include "src/headers/outside_home.hpp"
#include "src/headers/items.hpp"
#include "src/headers/supermarket.hpp"

//the seed that the program will use
//it may or may not be changed to anything you wish >:)
#define seed time(0)

//timer struct to make a timer
//example of a Timer struct
// Timer cool_timer = {2.0};
typedef struct Timer {

    double lifetime;

    //make start_time automatically begin with the GetTime
    double start_time = GetTime();
} Timer;


bool isTimerDone(Timer* timer) {

    //if enough time has passed to go over the lifetime
    if (GetTime() - timer->start_time >= timer->lifetime) {

        return true;
    } else {

        return false;
    }
}


//var to keep track of the room
//0 - home, 1 - outside home, 2 - supermarket, 
unsigned short int room = 0;

//misc rectangles
//they are placed here (in global) so all .cpp files can use it without getting linker errors
Rectangle mouseHitbox;

int main(void) { 

    const int screenWidth = 1000; 
    const int screenHeight = 800; 

    InitWindow(screenWidth, screenHeight, "title test m"); 
    InitAudioDevice();

    //disable exit key
    SetExitKey(KEY_NULL);

    SetTargetFPS(60);//limita de frameuri 
                     
    //textures that i dont know where to put them so ill leave them in the main.cpp file cause yeah
    Texture2D container_6_slots = LoadTexture("resources/img/other/container_6_slots.png");

    //sfx
    Sound door_int = LoadSound("resources/sfx/door_int.ogg");

    //misc vars
    
    //var so that the random greeting doesnt reset mid convo
    bool write_enable_random_greeting = true;

	//init
    init_player();
    init_items();

    //init places
    init_home();
    init_outside_home();
    initshop();
    
    //start the shop theme so it can continue in shop
    PlayMusicStream(shop_theme);

    //al timers get created here so that the start time doesnt reset

    //initiate a timer for hunger
    Timer hunger_timer = {8.0};

    //the chat bubble timer
    Timer bubble_timer = {3.0};
    //also a var so that the bubble timer keeps its start time and doesnt change
    bool write_enable_bubble_timer = true;


    // Main game loop
    while (!WindowShouldClose()) {

        //randomize the seed everytime
        srand(seed);

        //update mouse hitbox with new vars 
        mouseHitbox = {(float)GetMouseX(), (float)GetMouseY(), 20, 20};

        //PLAYER -----------------------------------------------------

        //player hitbox stays here so it updates with the new values of the vars
        guyHitbox = {guyX, guyY, guyWidth, guyHeight};
        
        //run player, movement, actions every frame
        every_frame_player();

        //check if 8 secs have passed to remove 1 point of hunger
        if (isTimerDone(&hunger_timer)) {

            if (guyHunger > 0) {
                guyHunger = guyHunger - 1;
            }

            //reset the timer
            hunger_timer.start_time = GetTime();
        }

        //MAP OBEJCTS -----------------------------------------------------------------------
        
        //run all parts collisions, interaction, logic based on what room we are in
        switch (room) {

            //home
            case 0:

                //checks if player near object and he pressed "E"
                //using address so it modifies the actual object, not a copy of it
                for (auto i : home_int_parts) {
                    
                    //set var based on if its colliding hitboxes and E being held
                    if (IsKeyDown(KEY_E) && CheckCollisionRecs(guyHitbox, i->hitbox)) {

                        i->isInteracted = true;

                    } else {

                        i->isInteracted = false;
                    }
                }

                //this is container
                //checks if player near object and he pressed "E"
                //using address so it modifies the actual object, not a copy of it
                for (auto i : home_containers) {
                    
                    //set var based on if its colliding hitboxes and E being held
                    if (IsKeyDown(KEY_E) && CheckCollisionRecs(guyHitbox, i->hitbox)) {

                        i->isInteracted = true;

                    } else {

                        i->isInteracted = false;
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
                if (CheckCollisionRecs(guyHitbox, outside_supermarket.hitbox) && IsKeyPressed(KEY_E)) {

                    //sfx
                    PlaySound(door_int);

                    //make him eneter to the right of the door 
                    guyX = market_exit.x + 110;

                    guyY = market_exit.y;

                    //go to another room
                    room = 2;
                }

                break;

            //the supermarket
            case 2:

                //check if the exit door in shop has been interacted
                if (CheckCollisionRecs(market_exit.hitbox, guyHitbox) && IsKeyPressed(KEY_E)) {

                    //sfx
                    PlaySound(door_int);

                    //set pos to the other door 
                    guyX = outside_supermarket.x;
                    //add door height so it doesnt spawn in door
                    guyY = outside_supermarket.y + outside_supermarket.sizeY;

                    //go to another room
                    room = 1;
                }

                //checks if player near object and he pressed "E"
                //using address so it modifies the actual object, not a copy of it
                for (auto i : shop_int_parts) {
                    
                    //set var based on if its colliding hitboxes and E being held
                    if (IsKeyDown(KEY_E) && CheckCollisionRecs(guyHitbox, i->hitbox)) {

                        i->isInteracted = true;

                    } else {

                        i->isInteracted = false;
                    }
                }

                //checks if player near object and he pressed "E"
                //using address so it modifies the actual object, not a copy of it
                for (auto i : shop_own_containers) {
                    
                    //set var based on if its colliding hitboxes and E being held
                    if (IsKeyDown(KEY_E) && CheckCollisionRecs(guyHitbox, i->hitbox)) {

                        i->isInteracted = true;

                    } else {

                        i->isInteracted = false;
                    }
                }

                break;

            //if something somehow goes wrong
            default:
                std::cout << "switch_case_logic: game is sad, room var is modified \n";
                return -1;

        }

        // DRAWING !!!!!!!!!!!!!!!!!!!!1
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(LIGHTGRAY);


        //draw everything that needs to be drawn in the respective room
        switch (room) {

            //this is all part of room 0, aka home
            case 0:

                //draw all doors
                for (auto i : home_doors) {

                     DrawTexture(i.tex, i.x, i.y, WHITE);
                }
            
                //draw all interactable parts
                for (auto i : home_int_parts) {

                     DrawTexture(i->tex, i->x, i->y, WHITE);
                }

                for (auto i : home_containers) {

                    DrawTexture(i->tex, i->x, i->y, WHITE);
                }
        
                //the "GUI" if you interacted with the cool object
                if (tester1.isInteracted) {

                    //make the interact state to 1 so that the item transfer works
                    inv_interact_state = 1;


                    DrawTexture(container_6_slots, screenWidth/2 - (300 / 2), screenHeight/2 - (300 / 2), WHITE);

                    //draw all items in the container
                    item_definer_6_slots(&tester1, (Vector2){393, 289}, (Vector2){487, 289}, (Vector2){569, 289}, (Vector2){396, 381}, (Vector2){487, 381}, (Vector2){567, 381});

                    //oh and also run func that makes the item transfer to container possible when this is open
                    transfer_inv_to_cont(&tester1);

                    //and check for any transfers from container to inventory
                    transfer_cont_to_inv(&tester1, (Vector2){393, 289}, (Vector2){487, 289}, (Vector2){569, 289}, (Vector2){396, 381}, (Vector2){487, 381}, (Vector2){567, 381});
                } else {
                    //honestly its just so item transfer is not sticky
                    inv_interact_state = 0;

                    //and also to reset the variable that decides which slot to switch
                    //its default value is 255
                    inv_slot_interacted = 255;
                }

                break;

            //outside of house
            case 1:

                //grass.
                DrawTexture(outside_home_grass, 0, 0, WHITE);

                //draw from vector
                for (auto i : outside_home_parts) {
                    DrawTexture(i.tex, i.x, i.y, WHITE);
                }

                for (auto i: outside_exits) {

                    DrawTexture(i -> tex, i -> x, i -> y, WHITE);
                }

                DrawTexture(outside_supermarket.tex, outside_supermarket.x, outside_supermarket.y, WHITE);
                //oh yeah and about supermarket, when leaving, you go outside, but the cashier needs
                //to greet everytime yyou enter, so allow the chat bubble to appear
                write_enable_bubble_timer = true;

                //same with the random greeting
                write_enable_random_greeting = true;
                break;
                
            //the supermarket
            //btw we use {} to make a scope so the compiler doesnt complain about
            //a variable declared here to fall through another case
            case 2: {

                //grab the rng value
                const unsigned int rng = rand();

                if (write_enable_random_greeting) {
                    //now copy the random greeting
                    strncpy(selected_line_1, greetings[rng % 3], 100);

                    write_enable_random_greeting = false;
                }

                //set start time to timer so it works
                if (write_enable_bubble_timer) {

                    bubble_timer.start_time = GetTime();

                    write_enable_bubble_timer = false;
                }

                //play the track
                UpdateMusicStream(shop_theme);

                //background
                DrawTexture(floortileshop, 0, 0, WHITE);

                //draw door since its not in the interact_parts vector
                DrawTexture(market_exit.tex, market_exit.x, market_exit.y, WHITE);

                //make the cashier say a random line from interactions 
                if (cashier.isInteracted) {
                    strncpy(selected_line_1, interaction_lines[rng % 5], 100);

                    //and activate bubble timer
                    write_enable_bubble_timer = true;
                }

                //check if the timer didnt expire
                if (!isTimerDone(&bubble_timer)) {
                    //draw chat bubble texture on cashier
                    DrawTexture(chat_bubble, cashier.x - 200, cashier.y + 135, WHITE);

                    //draw text
                    DrawText(selected_line_1, cashier.x - 180, cashier.y + 160, 25, BLACK);
                }

                //int_parts
                for (auto i : shop_int_parts) {

                    DrawTexture(i->tex, i->x, i->y, WHITE);
                }

                for (auto i : shop_own_containers) {

                    DrawTexture(i->tex, i->x, i->y, WHITE);
                }

                break;
            }

            //if it somehow goes wrong
            default:
                std::cout << "switch_case_draw: game is sad, room var is modified \n";
                return -1;
                break;


        }


        //draw player here so he overlaps all (if hes alive)
        if (guyHp > 0) {
            DrawTexture(guyTex, guyX, guyY, WHITE);
        } else {

            //sub the font size so its centered
            DrawText("You died.", screenWidth/2 - 118, screenHeight/2 - 60, 60, MAROON);
			DrawText("Press T to respawn.", screenWidth/2 - 140, screenHeight/2, 30, MAROON);
        }

        //the stat "menu"
        //temp: it is only the text of the stats, ill want it to be some sort of a bar or smth

        //this is the outline for the stat rec
        Rectangle stat_outline_rec = {(float)screenWidth - 225, 25, 200, 100};
        
        DrawRectangle(screenWidth - 225, 25, 200, 100, GRAY);
        DrawRectangleLinesEx(stat_outline_rec, 5, BLACK);

        DrawText(TextFormat("Health: %d", guyHp), screenWidth - 210, 40, 20, RED);
        DrawText(TextFormat("Hunger: %d", guyHunger), screenWidth - 210, 65, 20, ORANGE);
        DrawText(TextFormat("Cash: %d", cash), screenWidth - 210, 90, 20, GREEN);

        //draw inv slots
        DrawTexture(inventorySlot, 25, 25, WHITE);

        //run items code that need to run every frame
        //ITS BEING RAN IN THE DRAWING SECTIONS BECAUSE IT ALSO DRAWS TEXTURES
        every_frame_inv_func_items();


        //debug menu
        if (IsKeyDown(KEY_F3)) {

            DrawText(TextFormat("Mouse X: %d", GetMouseX()), 0, 5, 20, BLACK);
            DrawText(TextFormat("Mouse Y: %d", GetMouseY()), 0, 25, 20, BLACK);
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
