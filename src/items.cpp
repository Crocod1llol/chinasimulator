extern "C" {
    #include "../lib/raylib.h"
}

//#include <vector>

//array that contains all possible item ids
//check misc/all_item_ids.txt for all ids and respective object
const int all_ids[] = {0};


//other resources
//textures for all items

Texture2D test_object_0;

//sound

Sound troll;


//load all item textures and init stuff
void init_items() {
    //init textures
    test_object_0 = LoadTexture("resources/img/textures/items/0_test_obj.png");


    //init sounds
    troll = LoadSound("resources/sfx/items/troll.ogg");
}

//ALL ITEM EXECUTION FUNCTIONS
//format: *return type* *item name*_*id_func(*args*)
//example: void test_obj_0_func()

void test_obj_0_func() {
    
    //play a sound
    PlaySound(troll);
}


