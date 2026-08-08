#ifndef ITEMS_HPP
#define ITEMS_HPP

//array that contains all possible item ids
//check misc/all_item_ids.txt for all ids and respective object
extern const int all_ids[];

//other resources like img, sfx

//all textures

extern Texture2D test_object_0;

//all sounds

extern Sound troll;

//funcs
void init_items();

//ALL ITEM EXECUTION FUNCTIONS
//format: *return type* *item name*_*id_func(*args*)
//example: void test_obj_0_func()

void test_obj_0_func();

#endif
