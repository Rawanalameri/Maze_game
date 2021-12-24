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
    SDL_Texture* texture;
}walls_t;


walls_t* init_wall(int px,int py,int postx,int posty);

#endif