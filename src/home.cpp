extern "C" {
    #include "../lib/raylib.h"
}

#include <vector>

#include "headers/general_parts.hpp"


//vectors containing all Parts
//store pointers pf the interact parts so we can actually so the copies in the vector affect the real obj
std::vector<interact_part*> home_int_parts;

std::vector<Part> home_parts;

std::vector<interact_part> home_doors;

//doors will be their own object since they go to different rooms
interact_part outside_door_from_home;

//separate interact items
interact_part tester1;

interact_part tester2;

void init_home() {

    //initiate objects when the window is open
    outside_door_from_home = {350, 0, 90, 150, LoadTexture("resources/img/textures/door_90x150.png")};
    tester1 = {20, 300, 100, 75, LoadTexture("resources/img/textures/test_100x75.png")};
    tester2 = {600, 220, 100, 75, LoadTexture("resources/img/textures/test_100x75.png")};

    //push to vectors
    home_int_parts.push_back(&tester1);
    home_int_parts.push_back(&tester2);

    home_doors.push_back(outside_door_from_home);
}
