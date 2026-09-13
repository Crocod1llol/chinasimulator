//if you want comments, check the .cpp file of the same name
#include <vector>

#ifndef WENDONALDS_HPP
#define WENDONALDS_HPP

//define extern structs
struct interact_part;
struct Part;

//floor
extern Texture2D wendonalds_floor;

//ambient sound
extern Music wendonalds_theme;

//any structs 
extern interact_part wendonalds_exit;

extern interact_part wend_counter;

extern interact_part food_cooker;

//var is self explanatory
extern unsigned short int food_cooker_state;

//vectors
extern std::vector<interact_part*> wend_int_parts;

extern std::vector<Part> wend_parts;

//funcs
void initWendonalds();

#endif
