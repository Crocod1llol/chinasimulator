extern "C" {
    #include "../lib-include/raylib.h"
}

#include "headers/general_parts.hpp"

//floor
Texture2D wendonalds_floor;

//wendonalds beeping
Music wendonalds_theme;

//the exit door
interact_part wendonalds_exit = {};

void initWendonalds() {
    //load stuff
    wendonalds_floor = LoadTexture("resources/img/textures/wendonalds_floor_1050x850.png");

    //the ambient sound in wendonalds
    wendonalds_theme = LoadMusicStream("resources/music/wendonalds.mp3");

    //structs 
    
    wendonalds_exit = {123, 650, 90, 150, LoadTexture("resources/img/textures/market_door_90x150.png")};
}
