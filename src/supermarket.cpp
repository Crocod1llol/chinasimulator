extern "C" {
    #include "../lib/raylib.h"
}

#include <vector>

#include "headers/general_parts.hpp"
//#include <stdio.h>

typedef struct shop_item {

    unsigned int item_id;
    unsigned int price;

} shop_item;

typedef struct shop_container {
    
    float x;
    float y;

    float sizeX;
    float sizeY;

    int max_items;

    std::vector<shop_item> container_contents;

    Texture2D tex;

    bool isInteracted = false;

    Rectangle hitbox = {x, y, sizeX, sizeY};

} shop_container;

//the background
Texture2D floortileshop;

//any created strutcs
interact_part market_exit = {};

interact_part cashier = {};

//vending machine ok
shop_container vending_machine = {};

//cashier chat bubble
Texture2D chat_bubble;

//the cashier text lines
const char *greetings[] = {"Welcome to china shop!", "Hello!", "hi bro whacha doin"};
const char *interaction_lines[] = {"What is it?", "what do you need bro", "hey buddy.", "whats wrong?", "no, i don't give free candy"};


//a variable to keep track of what greeting should be displayed next
char selected_line_1[100];
char selected_line_2[100];


//the shop theme
Music shop_theme;

//vectors
std::vector <interact_part*> shop_int_parts;

std::vector <shop_container*> shop_own_containers;

//the initialize func, it loads texture data into memory when window is init
void initshop()
{
    //init music
    shop_theme = LoadMusicStream("resources/music/shop.mp3");

    //background
	floortileshop = LoadTexture("resources/img/textures/storebg1000x800.png");

    //cashier chat bubbl
    chat_bubble = LoadTexture("resources/img/other/chat_bubble.png");

    //any created structs
    
    //subtract y by height so it isnt outside the map
    market_exit = (interact_part){100, 800 - 150, 90, 150, LoadTexture("resources/img/textures/market_door_90x150.png") };

    cashier = {755, 200, 198, 177, LoadTexture("resources/img/textures/cashier.png")}; 

    vending_machine  = {300, 10, 150, 180, 6, {{0, 0}, {0, 0}, {0,0}, {0, 0}, {0, 0}, {0, 0} }, LoadTexture("resources/img/textures/vending_machine_150x180.png")};

    //add to vector
    shop_int_parts.push_back(&cashier);

    shop_own_containers.push_back(&vending_machine);
}
