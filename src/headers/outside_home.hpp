#ifndef OUTSIDE_HOME_HPP
#define OUTSIDE_HOME_HPP

//extern structs
struct Texture;
struct Part;
struct interact_part;

//created structs
//parts
extern Part maybe_flowers;

//exits
extern interact_part outside_door_to_home;
extern interact_part outside_supermarket;


//vectors
extern std::vector <Part> outside_home_parts;
extern std::vector <interact_part*> outside_exits;

//funcs
void init_outside_home();

//unique texture
extern Texture outside_home_grass;

#endif
