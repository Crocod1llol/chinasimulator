extern "C" {
    #include "../lib/raylib.h"
}

#include "headers/general_parts.hpp"
#include <vector>

//array that contains all possible item ids
//check misc/all_item_ids.txt for all ids and respective object
const int all_ids[] = {0, 1};


//other resources
//textures for all items

Texture2D test_object_1;

//sound
Sound troll;

/*
  NOTICE: for now i have no plans to use this struct system since i will just be using item ids to choose 
  what to draw, what function it will do, etc

*/

// a vector to keep track of the spawned items
//std::vector <item*> spawned_items;

//item structs
//check the general_parts header for more info
//item test_item;

//load all item textures and init stuff
void init_items() {
    //init textures
    test_object_1 = LoadTexture("resources/img/textures/items/1_test_obj.png");


    //init sounds
    troll = LoadSound("resources/sfx/items/troll.ogg");

    //init all structs
    //test_item = {100, 200, 1, 2, "test obj", test_object_1};

    //insert into vectors
    //spawned_items.push_back(&test_item);
}

//ALL ITEM EXECUTION FUNCTIONS
//format: *return type* *item name*_*id_func(*args*)
//example: void test_obj_1_func()

void test_obj_1_func() {
    
    //play a sound
    PlaySound(troll);
}


