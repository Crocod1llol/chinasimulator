extern "C" {
    #include "../lib/raylib.h"
}

#include <vector>

#include "headers/general_parts.hpp"

//vectors containing all Parts
std::vector<interact_part> int_parts;
std::vector<Part> parts;

std::vector<interact_part> doors;

//doors will be their own object since they go to different rooms
interact_part outside_door_from_home;
interact_part tester1;

void init_home() {

    //initiate objects when the window is open
    outside_door_from_home = {350, 0, 90, 150, LoadTexture("resources/img/door_90x150.png")};
    tester1 = {20, 300, 100, 75, LoadTexture("resources/img/test_100x75.png")};

    //push to vectors
    int_parts.push_back(tester1);
    doors.push_back(outside_door_from_home);
}
