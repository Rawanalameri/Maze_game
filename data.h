#ifndef DATA_H
#define DATA_H

#include "player.h"

#define SCREENH 900
#define SCREENW 600
#define BRICKH 32
#define BRICKW 32

typedef struct walls_s
{
    SDL_Rect bricks;
    SDL_Rect Src;
}walls_t;


typedef struct base_s
{
    walls_t* wall;
    player_t* player;
    int gameover;
    int chances;

}base_t;
base_t* init_base(player_t* player,int px,int py,int postx,int posty);
walls_t* init_wall(int px,int py,int postx,int posty);
void gameOver(char** tab,int nbl,int nbc,base_t* base);

#endif