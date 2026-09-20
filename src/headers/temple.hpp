#include <vector>

#ifndef TEMPLE_HPP
#define TEMPLE_HPP

struct interact_part;

//the best music
extern Music temple_music;

//every structs
extern interact_part temple_door;
extern interact_part king_jing_um;

//king jing um's text lines
extern const char *jing_interact_lines[3];
//and also to fix on the screen, the last line in interaction_lines will have another line a bit down (has 21 chars)
extern const char *nuclear_bomb_interaction_line;

//the selected lines
extern char jing_selected_line1[50];
extern char jing_selected_line2[50];

//sfx
extern Sound temple_door_sfx;

//vectors
extern std::vector<interact_part*> temple_int_parts;

//funcs
void init_temple();


#endif 
