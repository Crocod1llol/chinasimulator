#include <vector>

#ifndef PLAYER_HPP
#define PLAYER_HPP

//textures
extern Texture2D guyTex;

extern Texture2D inventorySlot;

//player vars

//guy base stats
extern int guyHp;
extern int guyHunger;

//pos
extern float guyX;
extern float guyY;

//size
#define guyWidth 100
#define guyHeight 100

//others
extern int playerspeed;

//hitbox rectangle
//it will get defined in the main loop so its values will update
extern Rectangle guyHitbox;

//the vector that contains all item ids in inventory
extern std::vector <size_t> inventory_items;


//functions
void init_player();

void player_loop();


#endif
