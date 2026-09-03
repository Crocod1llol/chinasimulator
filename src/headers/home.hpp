#include <vector>

#ifndef HOME_HPP
#define HOME_HPP

//extern structs so we can use them here
struct Part;
struct interact_part;
struct container;

//vectors
extern std::vector<Part> home_parts;
extern std::vector<interact_part*> home_int_parts;
extern std::vector<container*> home_containers;
extern std::vector<interact_part> home_doors;

//declare items
//------------------------

//doors
extern interact_part outside_door_from_home;

//interactable items
extern container tester1;

//funcs
void init_home();

#endif
