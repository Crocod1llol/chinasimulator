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

    Texture tex;

    bool isInteracted = false;

    const size_t max_items;

    std::vector <size_t> container_item_ids;

    //the hitbox is larger so the player can interact with it without colliding directly into it
    Rectangle hitbox = {x, y, sizeX + 30, sizeY + 30};

} container;

//a struct to help me manage items
/*
  NOTICE: for now i have no plans to use this struct since i will just be using item ids to choose 
  what to draw, what function it will do, etc

*/

/*
typedef struct item {

    float x;
    float y;

    //the item's id
    //check misc for more info
    size_t id;

    //the status, whether its in a container or on the floor
    //0 - in inventory
    //1 - in container
    //2 - on the floor
    int status;

    const char *name;

    Texture2D tex;

    //helpful for checking interactions
    //default is false (0)
    bool isInteracted = false;

    //its hitbox
    Rectangle hitbox = {x, y, 32, 32};

} item;
*/

#endif
