#include <vector>
extern "C" {

    #include "../lib-include/raylib.h"
}
#include <vector>
#include "headers/general_parts.hpp"

//the wonderful music
Music temple_music;

//every struct
interact_part temple_door = {};

//king jing um
interact_part king_jing_um = {};

//king jing um's text lines
const char *jing_interact_lines[] = {"what?", "you want something?", "if you give me 200$,", };
//and also to fix on the screen, the last line in interaction_lines will have another line a bit down (has 21 chars)
const char *nuclear_bomb_interaction_line = "i will give you bomb";

//the selected lines
char jing_selected_line1[50];
char jing_selected_line2[50];

//sfx 
Sound temple_door_sfx;

//vectors

//std::vector<Part> temple_parts;
std::vector<interact_part*> temple_int_parts;

void init_temple() {

    //init music
    temple_music = LoadMusicStream("resources/music/china_temple.mp3");

    temple_door = {100, 650, 170, 150, LoadTexture("resources/img/textures/temple_door_170x150.png")};

    king_jing_um = {350, 125, 100, 100, LoadTexture("resources/img/textures/king_jing_um.png")};

    //init sfx
    temple_door_sfx = LoadSound("resources/sfx/temple_door.ogg");

    //push to vectors
    temple_int_parts.push_back(&king_jing_um);
}
