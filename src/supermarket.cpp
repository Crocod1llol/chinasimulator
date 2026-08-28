extern "C" {
#include "../lib/raylib.h"

}

#include <vector>

#include "headers/general_parts.hpp"

//the background
Texture2D floortileshop;

//any created strutcs
interact_part market_exit;

interact_part cashier;

//the shop theme
Music shop_theme;

//vectors
std::vector <interact_part*> shop_int_parts;

//the initialize func, it loads texture data into memory when window is init
void initshop()
{
    //init music
    shop_theme = LoadMusicStream("resources/music/shop.mp3");

    //background
	floortileshop = LoadTexture("resources/img/textures/storebg1000x800.png");

    //any created structs
    
    //subtract y by height so it isnt outside the map
    market_exit = {100, 800 - 150, 90, 150, LoadTexture("resources/img/textures/market_door_90x150.png") };

    cashier = {755, 200, 198, 177, LoadTexture("resources/img/textures/cashier.png")}; 

    //add to vector
    shop_int_parts.push_back(&cashier);
}
