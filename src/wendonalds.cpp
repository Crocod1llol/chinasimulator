extern "C" {
    #include "../lib-include/raylib.h"
}

#include "headers/general_parts.hpp"

#include <vector>

//floor
Texture2D wendonalds_floor;

//wendonalds beeping
Music wendonalds_theme;

//structs

//the exit door
interact_part wendonalds_exit = {};

//the counter where the player will be placing stuff
interact_part wend_counter = {};

//the part where you will get food to serve
interact_part food_cooker = {};

//the var is self explanatory
//0 - turned off; 1 - on, cooking; 2 - food finished, turned off
unsigned short int food_cooker_state = 0;

//vectors 
std::vector<interact_part*> wend_int_parts;

std::vector<Part> wend_parts;

void initWendonalds() {
    //load stuff
    wendonalds_floor = LoadTexture("resources/img/textures/wendonalds_floor_1050x850.png");

    //the ambient sound in wendonalds
    wendonalds_theme = LoadMusicStream("resources/music/wendonalds.mp3");

    //structs 
    
    wendonalds_exit = {123, 650, 90, 150, LoadTexture("resources/img/textures/market_door_90x150.png")};

    wend_counter = {200, 90, 550, 225, LoadTexture("resources/img/textures/wend_order_counter_550x225.png")};

    food_cooker = {800, 620, 150, 175, LoadTexture("resources/img/textures/no_food_food_cooker_200x175.png")};

    //push to vectors
    wend_int_parts.push_back(&wend_counter);

    wend_int_parts.push_back(&food_cooker);

    //push multiple copies of tables and chairs
    for (float i = 300.0; i <= 700.0; i = i + 250.0) {
        wend_parts.push_back((Part){275.0, i, 450, 210, LoadTexture("resources/img/textures/wend_chair_table_450x210.png") });
    }

}
