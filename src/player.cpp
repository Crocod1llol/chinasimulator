//btw, this file also includes player inventory, so yeah
extern "C" {
    #include "../lib/raylib.h"
}

#include <vector>

//the maximum hunger and hp is 100
#define MAX_HUMANOID_STATS 100

//extern the room var since its from main and player respawns in home
extern unsigned int room;

//all textures
Texture2D guyTex;

Texture2D inventorySlot;

//all player variables

//all player's stats
int guyHp = 100;
int guyHunger = 1;
int cash = 100;
int card = 0;

//default pos
//the default X and Y are left undefined here is because
//they depend on getRenderWidth and height, which may run when window is uninit
//which results in undefined behavior
float guyX;
float guyY;

//others
int playerspeed = 5;

//hitbox rectangle
//it will get defined in the main loop so its values will update
Rectangle guyHitbox;

//the vector that contains all item ids in inventory
std::vector <size_t> inventory_items = {2, 2, 1};

//var to keep track of what state does the inventory interact do
//0 - normal, click on item to do stuff
//1 - container opened, clicking will direct to container
int inv_interact_state = 0;

//sounds
Sound death;

//init variables and other stuff
void init_player() {

    //textures
    guyTex = LoadTexture("resources/img/textures/player.png");

    inventorySlot = LoadTexture("resources/img/other/inventory_slot.png");

    //init vars
    guyX = GetRenderWidth()/2;
    guyY = GetRenderHeight()/2;

    //sound
    death = LoadSound("resources/sfx/death.ogg");
}

//variable to play the death sound once
bool soundCount = true;

//a func that resets the player state to the default values after they died
void resetPlayer() {

    guyHp = 50;
    guyHunger = 86;

    guyX = GetRenderWidth()/2;
    guyY = GetRenderHeight()/2;

    room = 0;
    
    soundCount = true;
}


//code that needs to run every frame for the player
void every_frame_player() {

    //if player died
    if (guyHp <= 0) {
    
    	//also drop all player items if they died
    	for (unsigned int i = 0; i < inventory_items.size(); i++) {
    		inventory_items.at(i) = 0;
    	}

		//i use this variable so that the sfx doesnt repeat forever while dead
		if (soundCount) {
			PlaySound(death);
			
			soundCount = false;
		}

        //reset player if key T is pressed
    	if (IsKeyPressed(KEY_T)) {
    		resetPlayer();
    	}
    }

    //check if player doesnt have hunger anymore
    if (guyHunger <= 0) {

        //kill.
        guyHp = 0;
    }

    //check if hunger or health surpassed the limit
    if (guyHunger >= MAX_HUMANOID_STATS) {

        guyHunger = MAX_HUMANOID_STATS;
    }
    if (guyHp >= MAX_HUMANOID_STATS) {
        
        guyHp = MAX_HUMANOID_STATS;
    }
    


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
