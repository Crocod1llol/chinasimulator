extern "C" {
#include "../lib/raylib.h"

}

#include <vector>
#include "headers/general_parts.hpp"

//the background
Texture2D floortileshop;

//will have more parts here bro trust me

//the initialize func, it loads texture data into memory when window is init
void initshop()
{
    //background
	floortileshop = LoadTexture("resources/img/textures/storebg1000x800.png");

}
