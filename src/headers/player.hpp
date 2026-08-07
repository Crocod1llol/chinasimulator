#ifndef PLAYER_HPP
#define PLAYER_HPP

//texture
extern Texture2D guyTex;

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


//functions
void init_player();

void player_loop();


#endif
