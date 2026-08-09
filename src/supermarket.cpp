extern "C" {
#include "../lib/raylib.h"

}

#include <vector>

#include "headers/general_parts.hpp"

Texture2D floortileshop;

void initshop()
{
	floortileshop = LoadTexture("resources/img/textures/storebg1000x800.png");

}
