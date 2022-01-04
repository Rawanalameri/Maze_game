#ifndef TRAP_H
#define TRAP_H
#include "graphics.h"

#define TRAPHT 60
#define TRAPWT 120

typedef struct trap_s{
    const char* text[4];
}trap_t;

SDL_Texture* createText(SDL_Renderer *renderer, TTF_Font *font,trap_t trap, SDL_Color color,SDL_Rect* position,int y,int i);
trap_t* init_trap(trap_t trap1,trap_t trap2,trap_t trap3);
void showTrap(trap_t trap,player_t* player,SDL_Event* event,int j);
void clean_trap(trap_t* trap);

#endif