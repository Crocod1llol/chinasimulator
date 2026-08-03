#include <vector>

#ifndef HOME_HPP
#define HOME_HPP

//extern structs so we can use them here
struct Part;
struct interact_part;

//vectors
extern std::vector<Part> parts;
extern std::vector<interact_part> int_parts;
extern std::vector<interact_part> doors;

//declare items
//------------------------

//doors
extern interact_part outside_door_from_home;

//interactable items
extern interact_part tester1;

//funcs
void init_home();

#endif
