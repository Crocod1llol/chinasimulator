//btw, this file also includes player inventory, so yeah
extern "C" {
    #include "../lib/raylib.h"
}

#include <vector>

//all textures
Texture2D guyTex;

Texture2D inventorySlot;

//all player variables

//guy base stats
int guyHp = 100;
int guyHunger = 100;
int cash = 100;
int card = 0;

//default pos
//the default X and Y are left undefined here is because
//they depend on getRenderWidth and height, which may run when window is uninit
float guyX;
float guyY;

//others
int playerspeed = 5;

//hitbox rectangle
//it will get defined in the main loop so its values will update
Rectangle guyHitbox;

//the vector that contains all item ids in inventory
std::vector <size_t> inventory_items;

//init variables and other stuff
void init_player() {

    //textures
    guyTex = LoadTexture("resources/img/textures/player.png");

    inventorySlot = LoadTexture("resources/img/other/inventory_slot.png");

    //init vars
    guyX = GetRenderWidth()/2;
    guyY = GetRenderWidth()/2;

}

//the every frame code that needs to run for the player
//ex. moving
void player_loop() {

    //PLAYER MOVEMENT -------------------------

    //vertical
    if (IsKeyDown(KEY_W))
    {
        guyY=guyY-playerspeed;

        //THIS IS WHERE I UPDATED IT.
        //it didnt work because "guyy >= 1", it checks if its greater than 1, which in this case it would quite always be
        if(guyY <= 5)
        {
            guyY = guyY + playerspeed;
        }

    }

    if (IsKeyDown(KEY_S))
    {
        guyY=guyY+playerspeed;

        // n is the height of the texture so its not a single line
        // plus 5 for the invisible borde
        if (guyY >= GetRenderHeight() - (100 + 10))
        {
            guyY = guyY - playerspeed;
        }
    }

    //horizontal
    if (IsKeyDown(KEY_D))
    {
        guyX=guyX+playerspeed;

        //here, its the same deal as going down
        //the border is too far, so we modify by player width (100)
        if (guyX >= GetRenderWidth() - (100 + 10)) {

            guyX = GetRenderWidth() - (100 + 10);
        }
    }

    if (IsKeyDown(KEY_A))
    {
        guyX=guyX-playerspeed;

        //here its more simpler
        if (guyX <= 0 + 10) {

            guyX = 0 + 10;
        }
    }
}
