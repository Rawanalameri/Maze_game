#ifndef TRAP_H
#define TRAP_H
#include "graphics.h"
#include "sdl2-ttf-light.h"

typedef struct trap_s{
    const char* question;
    const char* answer;
}trap_t;

trap_t* init_trap(trap_t trap1,trap_t trap2,trap_t trap3,trap_t trap4);
void showTrap(trap_t trap,player_t* player,SDL_Event* event);
//void check_Trap(player_t* player,trap_t trap,char** map,int* i,walls_t* walls);

#endif