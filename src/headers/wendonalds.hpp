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

//vectors
extern std::vector<interact_part*> wend_int_parts;

extern std::vector<Part> wend_parts;

//funcs
void initWendonalds();

#endif
