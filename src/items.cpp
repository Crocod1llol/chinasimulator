extern "C" {
    #include "../lib/raylib.h"
}

#include "headers/general_parts.hpp"
#include <vector>
#include <stdio.h>

//honestly just to have exit() func
#include <cstdlib>

//include player to manipulate values from it
#include "headers/player.hpp"

//extern the mouse hitbox since we will need it
extern Rectangle mouseHitbox;

//array that contains all possible item ids
//check misc/all_item_ids.txt for all ids and respective object
const unsigned int all_ids[] = {0, 1};


//other resources
//textures for all items

Texture2D test_object_1;

//sound
Sound troll;

//load all item textures and init stuff
void init_items() {
    //init textures
    test_object_1 = LoadTexture("resources/img/textures/items/1_test_obj.png");


    //init sounds
    troll = LoadSound("resources/sfx/items/troll.ogg");

}

//ALL ITEM EXECUTION FUNCTIONS
//format: void *item name*_*id*_func(*args*)
//example: void test_obj_1_func()

void test_obj_1_func() {
    
    //play a sound
    PlaySound(troll);
}

//functions to help define item slots in *almost* any container
//its still a help tho
//notice: put this in the drawing part because it also attempts to draw on screen
void item_definer_6_slots(container *cont, Vector2 slot1, Vector2 slot2, Vector2 slot3, Vector2 slot4, Vector2 slot5, Vector2 slot6) {

    //vars to help me in what slot should i put the item based on what slot it is iterating rn
    Vector2 current_slot_pos = {0, 0};

    for (int i = 0; i < 6; i++) {

        //select slot pos based on what slot is selected
        switch (i) {
            case 0:
                current_slot_pos = slot1;

            break;

            case 1:
                current_slot_pos = slot2;

            break;

            case 2:
                current_slot_pos = slot3;

            break;

            case 3:
                current_slot_pos = slot4;

            break;

            case 4:
                current_slot_pos = slot5;

            break;

            case 5:
                current_slot_pos = slot6;

            break;

            default:
                printf("FATAL ERROR: invalid variable i with value %d, while being supposed to be 0-5", i);
                exit(-1);

            break;
        }


        //now draw in the current slot the respective texture for the item
        switch (cont->container_item_ids.at(i)) {

            //nothing
            case 0:

            break;

            //the test object
            case 1:
                DrawTexture(test_object_1, current_slot_pos.x, current_slot_pos.y, WHITE);
                

            break;

            //if something goes wrong
            default:
                printf("FATAL ERROR: invalid item id at slot %d with id %d", i, cont -> container_item_ids.at(i));

                exit(-1);
            break;
        }

    }
}

//the function for itemsd that it needs to run every loop
void every_frame_inv_func_items() {

    //i know this will feel like "wtf man theres too many magic numbers" but i got an excuse
    //im using an *ID* based item system
    //im now immune haahahahahahah
    
    //jokes aside, yeah im checking in every slot to see what to render 
    //in what item spot and what action to do when clicked
    
    //vars to help me in what slot should i put the item based on what slot it is iterating rn
    //NOTICE: the y is the same for all of them
    int slotX = 0;

    //iteratee over all slots
    for (int i = 0; i < 3; i++) {

        //select slot pos based on what slot the loop is in
        switch (i) {
            //these macro vars are made in player.hpp
            case 0:
                slotX = guySlot1X;

            break;

            case 1:
                slotX = guySlot2X;

            break;

            case 2:
                slotX = guySlot3X;

            break;
        }

        switch(inventory_items.at(i)) {

            //0 belongs to void, or nothing
            case 0:

            break;

            //item 1 belongs to the test item
            case 1:

                DrawTexture(test_object_1, slotX, guySlotY, WHITE);

                //check if the user clicked on the icon using collisions
                //creating a rectangle on the spot to i dont have to make a struct
                if (CheckCollisionRecs((Rectangle){(float)slotX, guySlotY, 32, 32}, mouseHitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    //run the items's func
                    test_obj_1_func();

                    //then delete from inventory
                    inventory_items.at(i) = 0;
                }

            break;

            default:
                printf("FATAL ERROR: unreconized item id in slot %d in inventory", i);               
                exit(-1);

            break;
        }
    }
    
}
