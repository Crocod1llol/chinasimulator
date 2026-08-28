#ifndef SUPERMARKET_HPP
#define SUPERMARKET_HPP

//tell header that structs are declared somewhere else
struct interact_part;


//the background
extern Texture2D floortileshop;

//any created structs
extern interact_part market_exit;

extern interact_part cashier;

//cashier chat bubble
extern Texture2D chat_bubble;

//the cashier's text lines
extern const char *greetings[3];

//the shop theme
extern Music shop_theme;

//vectors
extern std::vector <interact_part*> shop_int_parts;

//funcs
void initshop();

#endif
