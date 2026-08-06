extern "C" {
    #include "../lib/raylib.h"

}

#include <vector>

#include "headers/general_parts.hpp"

//the outside grass
Texture outside_home_grass;

//declaration
//vectors
std::vector <Part> outside_home_parts;
std::vector <interact_part*> outside_exits;

//parts
Part maybe_flowers;

//doors/gateways
interact_part outside_door_to_home;

void init_outside_home() {
    //the outside grass
    outside_home_grass = LoadTexture("resources/img/outside_grass_home_2000x2000.png");
    //definition

    //interactable parts
    outside_door_to_home = {400, 450, 90, 150, LoadTexture("resources/img/door_90x150.png")};

    //Parts
    maybe_flowers = {75, 170, 150, 100, LoadTexture("resources/img/bad_flowers_150x100.png")};


    //inserting into vectors
    //parts vector
    outside_home_parts.push_back(maybe_flowers);

    //exists vector
    outside_exits.push_back(&outside_door_to_home);
}
