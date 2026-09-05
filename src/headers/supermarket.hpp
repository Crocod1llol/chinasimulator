#include <vector>

#ifndef SUPERMARKET_HPP
#define SUPERMARKET_HPP

//tell header that structs are declared somewhere else
struct interact_part;

typedef struct shop_item {

    unsigned int item_id;
    unsigned int price;

} shop_item;

typedef struct shop_container {
    
    float x;
    float y;

    float sizeX;
    float sizeY;

    int max_items;

    std::vector<shop_item> container_contents;

    Texture2D tex;

    bool isInteracted = false;

    Rectangle hitbox = {x, y, sizeX, sizeY};

} shop_container;

//the background
extern Texture2D floortileshop;

//any created structs
extern interact_part market_exit;

extern interact_part cashier;

extern shop_container vending_machine;

//cashier chat bubble
extern Texture2D chat_bubble;

//the cashier's text lines
extern const char *greetings[3];

extern const char *interaction_lines[5];

//a variable to keep track of what greeting should be displayed next
extern char selected_line_1[100];

extern char selected_line_2[100];

//the shop theme
extern Music shop_theme;

//vectors
extern std::vector <interact_part*> shop_int_parts;

extern std::vector <shop_container*> shop_own_containers;

//funcs
void initshop();

void shop_container_definer(shop_container *cont, Vector2 slot1, Vector2 slot2, Vector2 slot3, Vector2 slot4, Vector2 slot5, Vector2 slot6); 

#endif
