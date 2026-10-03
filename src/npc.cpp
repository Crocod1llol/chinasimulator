extern "C" {

    #include "../lib-include/raylib.h"
}

#include <vector>
#include <cstdlib>
#include <ctime>

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

//vector to keep track the amount of npcs spawned
std::vector<npc> alive_npcs;

//init textures and other assets for npcs
void init_npc_asset() {

    npc1_tex = LoadTexture("resources/img/textures/npc1.png");
    npc2_tex = LoadTexture("resources/img/textures/npc2.png");
    npc3_tex = LoadTexture("resources/img/textures/npc3.png");
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

    alive_npcs.push_back(target_npc);
}
