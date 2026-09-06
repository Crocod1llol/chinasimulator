extern "C" {
    #include "../lib/raylib.h"
}

#include <vector>

#include "headers/general_parts.hpp"

//vectors containing all Parts
//store pointers pf the interact parts so we can actually so the copies in the vector affect the real obj
std::vector<interact_part*> home_int_parts;

std::vector <container*> home_containers;

std::vector<Part> home_parts;

std::vector<interact_part> home_doors;

//doors will be their own object since they go to different rooms
interact_part outside_door_from_home = {};

//separate interact items
container tester1 = {};

//parts
Part chair_and_table = {};

Part lamp = {};

void init_home() {

    //initiate objects when the window is open
    outside_door_from_home = {350, 0, 90, 150, LoadTexture("resources/img/textures/door_90x150.png")};


    tester1 = (container){20, 300, 100, 75, 6, {1, 1, 0, 2, 2, 2}, LoadTexture("resources/img/textures/chest_100x75.png")};

    chair_and_table = {550, 380, 350, 200, LoadTexture("resources/img/textures/chair_and_table_350x200.png")};
    lamp = {570, 320, 75, 125, LoadTexture("resources/img/textures/lamp_75x125.png")};

    //push to vectors
    home_containers.push_back(&tester1);

    home_doors.push_back(outside_door_from_home);

    home_parts.push_back(chair_and_table);
    home_parts.push_back(lamp);
}
