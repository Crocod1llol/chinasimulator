#include <vector>
#include <stddef.h>

#ifndef GENERAL_PARTS_HPP
#define GENERAL_PARTS_HPP


typedef struct Part {

    float x;
    float y;

    float sizeX;
    float sizeY;

    Texture tex;

    Rectangle hitbox = {x, y, sizeX, sizeY};

} Part;


typedef struct interact_part {

    float x;
    float y;

    float sizeX;
    float sizeY;

    Texture tex;

    bool isInteracted = false;

    //the hitbox is larger so the player can interact with it without colliding directly into it
    Rectangle hitbox = {x, y, sizeX + 30, sizeY + 30};

} interact_part;

//struct to help me make parts made to store stuff
typedef struct container {

    float x;
    float y;

    float sizeX;
    float sizeY;

    bool isInteracted = false;

    int max_items;

    std::vector <int> container_item_ids;

    Texture tex;

    //the hitbox is larger so the player can interact with it without colliding directly into it
    Rectangle hitbox = {x, y, sizeX + 30, sizeY + 30};

} container;

#endif
