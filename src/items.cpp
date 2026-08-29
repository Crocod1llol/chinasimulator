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

Texture2D burger_2;

//sound
Sound troll;

Sound eat;

//load all item textures and init stuff
void init_items() {
    //init textures
    test_object_1 = LoadTexture("resources/img/textures/items/1_test_obj.png");

    burger_2 = LoadTexture("resources/img/textures/items/2_burger.png");

    //init sounds
    troll = LoadSound("resources/sfx/items/troll.ogg");

    eat = LoadSound("resources/sfx/items/eat.ogg");
}

//ALL ITEM EXECUTION FUNCTIONS
//format: void *item name*_*id*_func(*args*)
//example: void test_obj_1_func()

void test_obj_1_func() {
    
    //play a sound
    PlaySound(troll);
}

void burger_2_func() {

    //feed the guy
    guyHunger = guyHunger + 35;

    PlaySound(eat);
}

//variable that is responsible for transmitting the interacted slot
//default value is 255
int inv_slot_interacted = 255;

//func to help tranfer an item from a container to player inv
//this detects collisions with my mouse, which helps in selecting which items to transfer
void transfer_cont_to_inv(container *cont, Vector2 slot1, Vector2 slot2, Vector2 slot3, Vector2 slot4, Vector2 slot5, Vector2 slot6) {
    
    //vars to help me in what slot should i put the item based on what slot it is iterating rn
    Rectangle current_slot_hitbox = {0, 0, 32, 32};
    
    //iterate over container storage
    for (int i = 0; i < 6; i++) {

        //select slot pos based on what slot is selected
        switch (i) {
            case 0:
                current_slot_hitbox = {slot1.x, slot1.y, 32, 32};

            break;

            case 1:
                current_slot_hitbox = {slot2.x, slot2.y, 32, 32};

            break;

            case 2:
                current_slot_hitbox = {slot3.x, slot3.y, 32, 32};

            break;

            case 3:
                current_slot_hitbox = {slot4.x, slot4.y, 32, 32};

            break;

            case 4:
                current_slot_hitbox = {slot5.x, slot5.y, 32, 32};

            break;

            case 5:
                current_slot_hitbox = {slot6.x, slot6.y, 32, 32};

            break;

            default:
                printf("FATAL ERROR: invalid variable i with value %d, while being supposed to be 0-5", i);
                exit(-1);

            break;
        }

        //now check if a slot has been interacted and it has an item
        if (cont->container_item_ids.at(i) != 0 && CheckCollisionRecs(current_slot_hitbox, mouseHitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

            //variable to keep the first empty slot in player inv
            //255 default value
            int empty_slot = 255;

            //now check for empty space in player inv
            for (int a = 0; a < 3; a++) {

                //if yes, then get da hell out of here
                if (inventory_items.at(a) == 0) {
                    empty_slot = a;

                    break;
                }
            }

            //check if there is any empty slot
            if (empty_slot == 255) {
                //then exit func
                return;
            }

            //now make switch
            inventory_items.at(empty_slot) = cont->container_item_ids.at(i);
            cont->container_item_ids.at(i) = 0;
        } 

        /* also reset the last interacted slot to avoid bugs
         * like not being able to place an item in the last spot in inv that was used to transer an item to container
         * insane. */
        inv_slot_interacted = 255;
    }
}

//function to transfer an item from inv to a container
void transfer_inv_to_cont(container *cont) {

    //if the player is interacting with a cont AND the interacted slot's contents doesnt have an id of 0 AND if the var doesnt have the default value
    if (inv_slot_interacted != 255 && inv_interact_state == 1 && inventory_items.at(inv_slot_interacted) != 0 ) {

        //var to help keep the available empty spot
        //255 is the default, aka if no spot is free
        int available_spot = 255;

        //find empty slot in contaainer
        for (int i = 0; i < cont->max_items; i++) {

            if (cont->container_item_ids.at(i) == 0) {

                //if we found the desired slot, store in variable and get out of here
                available_spot = i;
                break;

            }
        }

        //checking of all spots are taken
        if (available_spot == 255) {

            //if yes, then return nothing and exit func
            return;
        }
        
        //if all passed, then make the switch
        cont->container_item_ids.at(available_spot) = inventory_items.at(inv_slot_interacted);
        inventory_items.at(inv_slot_interacted) = 0;
    }
}

//functions to help define item slots in *almost* any container
//its still a help tho
//notice: put this in the drawing part because it also attempts to draw on screen
void item_definer_6_slots(container *cont, Vector2 slot1, Vector2 slot2, Vector2 slot3, Vector2 slot4, Vector2 slot5, Vector2 slot6) {

    //vars to help me in what slot should i put the item based on what slot it is iterating rn
    Vector2 current_slot_pos = {0, 0};
    Rectangle current_slot_hitbox = {0, 0, 32, 32};

    for (int i = 0; i < 6; i++) {

        //select slot pos based on what slot is selected
        switch (i) {
            case 0:
                current_slot_pos = slot1;
                current_slot_hitbox = {slot1.x, slot1.y, 32, 32};

            break;

            case 1:
                current_slot_pos = slot2;
                current_slot_hitbox = {slot2.x, slot2.y, 32, 32};

            break;

            case 2:
                current_slot_pos = slot3;
                current_slot_hitbox = {slot3.x, slot3.y, 32, 32};

            break;

            case 3:
                current_slot_pos = slot4;
                current_slot_hitbox = {slot4.x, slot4.y, 32, 32};

            break;

            case 4:
                current_slot_pos = slot5;
                current_slot_hitbox = {slot5.x, slot5.y, 32, 32};

            break;

            case 5:
                current_slot_pos = slot6;
                current_slot_hitbox = {slot6.x, slot6.y, 32, 32};

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

            case 2:

                DrawTexture(burger_2, current_slot_pos.x, current_slot_pos.y, WHITE);
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

        //simplified var so that i dont have to write the spagetti to check if its been interacted
        bool inv_interacted = CheckCollisionRecs((Rectangle){(float)slotX, guySlotY, 32, 32}, mouseHitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        //if its interacted, then transmit the slot it has been interacted
        if (inv_interacted) {
            inv_slot_interacted = i;

        }

        switch(inventory_items.at(i)) {

            //0 belongs to void, or nothing
            case 0:

            break;

            //item 1 belongs to the test item
            case 1:

                DrawTexture(test_object_1, slotX, guySlotY, WHITE);

                //use only if the usage state is set to interact
                if (inv_interact_state == 0 && inv_interacted) {
                    
                    //run the items's func
                    test_obj_1_func();

                    //then delete from inventory
                    inventory_items.at(i) = 0;

                }

            break;

            //burger
            case 2:
                DrawTexture(burger_2, slotX, guySlotY, WHITE);

                //use only if the usage state is set to interact
                if (inv_interact_state == 0 && inv_interacted) {

                    //run items's
                    burger_2_func();

                    //then del from inv
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
