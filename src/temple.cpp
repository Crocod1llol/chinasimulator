extern "C" {

    #include "../lib-include/raylib.h"
}
#include "headers/general_parts.hpp"

//every struct
interact_part temple_door = {};

//sfx 
Sound temple_door_sfx;

void init_temple() {

    temple_door = {100, 650, 170, 150, LoadTexture("resources/img/textures/temple_door_170x150.png")};

    //init sfx
    temple_door_sfx = LoadSound("resources/sfx/temple_door.ogg");
}
