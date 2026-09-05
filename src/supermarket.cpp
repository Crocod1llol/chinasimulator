extern "C" {
    #include "../lib/raylib.h"
}

#include <vector>

#include "headers/general_parts.hpp"
#include "headers/player.hpp"
#include "headers/items.hpp"
#include <cstdio>
#include <cstdlib>

typedef struct shop_item {

    unsigned short int item_id;
    unsigned short int price;

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

//we are gonna need this for collision clicks
extern Rectangle mouseHitbox;

//the background
Texture2D floortileshop;

//any created strutcs
interact_part market_exit = {};

interact_part cashier = {};

//vending machine ok
shop_container vending_machine = {};

//cashier chat bubble
Texture2D chat_bubble;

//the cashier text lines
const char *greetings[] = {"Welcome to china shop!", "Hello!", "hi bro whacha doin"};
const char *interaction_lines[] = {"What is it?", "what do you need bro", "hey buddy.", "whats wrong?", "i don't give free candy"};


//a variable to keep track of what greeting should be displayed next
char selected_line_1[100];
char selected_line_2[100];


//the shop theme
Music shop_theme;

//vectors
std::vector <interact_part*> shop_int_parts;

std::vector <shop_container*> shop_own_containers;

//the initialize func, it loads texture data into memory when window is init
void initshop()
{
    //init music
    shop_theme = LoadMusicStream("resources/music/shop.mp3");

    //background
	floortileshop = LoadTexture("resources/img/textures/storebg1000x800.png");

    //cashier chat bubbl
    chat_bubble = LoadTexture("resources/img/other/chat_bubble.png");

    //any created structs
    
    //subtract y by height so it isnt outside the map
    market_exit = (interact_part){100, 800 - 150, 90, 150, LoadTexture("resources/img/textures/market_door_90x150.png") };

    cashier = {755, 200, 198, 177, LoadTexture("resources/img/textures/cashier.png")}; 

    vending_machine  = {300, 10, 150, 180, 6, {{1, 10}, {2, 30}, {0,0}, {0, 0}, {0, 0}, {0, 0} }, LoadTexture("resources/img/textures/vending_machine_150x180.png")};

    //add to vector
    shop_int_parts.push_back(&cashier);

    shop_own_containers.push_back(&vending_machine);
}

//define a macro so that i wont be writing 15 lines everytime i 
//want to buy the item
#define try_buy_item()                                                   \
do {                                                             \
    if (interacted && cash >= cont->container_contents.at(i).price) { \
        for (int a = 0; a < 3; ++a) {                            \
            if (inventory_items.at(a) == 0) {                   \
                cash -= cont->container_contents.at(i).price;  \
                cont->container_contents.at(i).price = 0;      \
                                                                \
                inventory_items.at(a) = cont->container_contents.at(i).item_id;    \
                cont->container_contents.at(i).item_id = 0;    \
            }                                                    \
        }                                                        \
    }                                                            \
} while (false)

//functions to help define item slots in *almost* any shop container
//notice: put this in the drawing part because it also attempts to draw on screen
void shop_container_definer(shop_container *cont, Vector2 slot1, Vector2 slot2, Vector2 slot3, Vector2 slot4, Vector2 slot5, Vector2 slot6) {

    //vars to help me in what slot should i put the item based on what slot it is iterating rn
    Rectangle current_slot_hitbox = {0, 0, 32, 32};

    for (int i = 0; i < 6; i++) {

        //select slot pos based on what slot is selected
        switch (i) {
            case 0:
                current_slot_hitbox = {slot1.x, slot1.y, 32, 32};

            break;

            case 1:
                current_slot_hitbox = {slot2.x, slot2.y, 32, 32};

            break;

            case 2:
                current_slot_hitbox = {slot3.x, slot3.y, 32, 32};

            break;

            case 3:
                current_slot_hitbox = {slot4.x, slot4.y, 32, 32};

            break;

            case 4:
                current_slot_hitbox = {slot5.x, slot5.y, 32, 32};

            break;

            case 5:
                current_slot_hitbox = {slot6.x, slot6.y, 32, 32};

            break;

            default:
                printf("FATAL ERROR: invalid variable i with value %d, while being supposed to be 0-5", i);
                exit(-1);

            break;
        }

        bool interacted = CheckCollisionRecs(mouseHitbox, current_slot_hitbox) && IsMouseButtonDown(MOUSE_BUTTON_LEFT);

        //now draw in the current slot the respective texture for the item
        switch (cont->container_contents.at(i).item_id) {

            //nothing
            case 0:

            break;

            //the test object
            case 1:
                DrawTexture(test_object_1, current_slot_hitbox.x, current_slot_hitbox.y, WHITE);

                try_buy_item();
            break;

            case 2:

                DrawTexture(burger_2, current_slot_hitbox.x, current_slot_hitbox.y, WHITE);

                try_buy_item();
            break;

            //if something goes wrong
            default:
                printf("FATAL ERROR: invalid item id at slot %d with id %d", i, cont -> container_contents.at(i).item_id);

                exit(-1);
            break;
        }

        //increasing the values a bit so the text is at the correct pos
        DrawText(TextFormat("%d Cash", cont->container_contents.at(i).price), current_slot_hitbox.x - 7, current_slot_hitbox.y + 45, 16, BLACK);

    }
}
