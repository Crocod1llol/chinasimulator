#ifndef ITEMS_HPP
#define ITEMS_HPP

//extern structs
struct item;
struct container;

//array that contains all possible item ids
//check misc/all_item_ids.txt for all ids and respective object
extern const int all_ids[];

//other resources like img, sfx

//all textures

extern Texture2D test_object_1;

//all sounds

extern Sound troll;

//any eventual variables:

//variable that is responsible for transmitting the inv interacted slot
//default value is 255
extern int inv_slot_interacted;


//funcs
void init_items();
void every_frame_inv_func_items();

void transfer_inv_to_cont(container *cont);

void item_definer_6_slots(container *cont, Vector2 slot1, Vector2 slot2, Vector2 slot3, Vector2 slot4, Vector2 slot5, Vector2 slot6);

//ALL ITEM EXECUTION FUNCTIONS
//format: *return type* *item name*_*id_func(*args*)
//example: void test_obj_1_func()

void test_obj_1_func();

#endif
