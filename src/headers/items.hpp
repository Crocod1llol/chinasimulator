#include <vector>

#ifndef ITEMS_HPP
#define ITEMS_HPP

//extern structs
struct item;

//array that contains all possible item ids
//check misc/all_item_ids.txt for all ids and respective object
extern const int all_ids[];

//other resources like img, sfx

//all textures

extern Texture2D test_object_1;

//all sounds

extern Sound troll;

/*
  NOTICE: for now i have no plans to use this struct system since i will just be using item ids to choose 
  what to draw, what function it will do, etc

*/

//all currently spawned items
//extern item test_item;

//extern vectors to keep track of the items
//extern std::vector <item*> spawned_items;

//funcs
void init_items();
void every_frame_func_items();

//ALL ITEM EXECUTION FUNCTIONS
//format: *return type* *item name*_*id_func(*args*)
//example: void test_obj_1_func()

void test_obj_1_func();

#endif
