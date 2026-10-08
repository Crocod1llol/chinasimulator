extern "C" {

    #include "../lib-include/raylib.h"
}

#include <vector>
#include <cstdlib>
//#include <ctime>

typedef struct npc {

    float x;
    float y;

    int health;

    unsigned short int room_number;

    Texture2D tex;

    Rectangle hitbox = {x, y, 100, 100};
} npc;

//load all textures for npcs
//TEMP: ALL TEXTURES ARENT MADE YET
Texture2D npc1_tex;
Texture2D npc2_tex;
Texture2D npc3_tex;

Texture2D ash;

//vector to keep track the amount of npcs spawned
std::vector<npc> alive_npcs;

//init textures and other assets for npcs
void init_npc_asset() {

    npc1_tex = LoadTexture("resources/img/textures/npc1.png");
    npc2_tex = LoadTexture("resources/img/textures/npc2.png");
    npc3_tex = LoadTexture("resources/img/textures/npc3.png");

    ash = LoadTexture("resources/img/textures/ash.png");
}

//spawn npc
void spawn_npc(int x, int y) {

    //the future npc
    npc target_npc = {};
    target_npc.health = 100;

    //select a random texture
    const unsigned int selected_number = ( rand() % 3 ) + 1;

    //now select based on the number
    switch (selected_number) {

        case 1:

            target_npc.tex = npc1_tex;
        break;

        case 2:

            target_npc.tex = npc2_tex;
        break;

        case 3:

            target_npc.tex = npc3_tex;
        break;

    }

    //spawn them outside
    target_npc.room_number = 1;
    target_npc.x = x;
    target_npc.y = y;

    //update hitbox so values are correct
    target_npc.hitbox = (Rectangle){target_npc.x, target_npc.y, 100, 100};

    alive_npcs.push_back(target_npc);
}

//returns the values so main can then move all npcs by a timer
int random_move_coord(npc target_npc) {
    
    const unsigned int rng = rand();

    //declare here because of if's scope
    int future_x;

    //the direction: to the left or to the right
    unsigned short int x_direction;
    if (rng % 2) {
        x_direction = -1;
    } else {
        x_direction = 1;
    }
    
    future_x = target_npc.x - (rng % 450) + 140;

    //target_npc->x = future_x * x_direction;

    //also make sure it doesnt go offbounds
    //subtract by 100 so the texture doesnt go outside
    if (future_x * x_direction > GetRenderWidth()){
        future_x = GetRenderWidth() - 100;
    } else if (future_x * x_direction < 0) {
        future_x = 0;
    }

    return future_x * x_direction;
}
