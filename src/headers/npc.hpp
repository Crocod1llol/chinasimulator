#include <vector>

#ifndef NPC_HPP
#define NPC_HPP

    //tell that the npc struct exists
typedef struct npc {

    float x;
    float y;

    int health;

    unsigned short int room_number;

    Texture2D tex;

    Rectangle hitbox;
} npc;

extern Texture2D npc1_tex;
extern Texture2D npc2_tex;
extern Texture2D npc3_tex;

extern Texture2D ash;

//vector to keep track the amount of npcs spawned
extern std::vector<npc> alive_npcs;

//funcs
void init_npc_asset();

void spawn_npc(int x, int y);

#endif
