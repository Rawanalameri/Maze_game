#ifndef TRAP_H
#define TRAP_H
#include "graphics.h"
#include "sdl2-ttf-light.h"

#define TRAPHT 60
#define TRAPWT 120

typedef struct trap_s{
    const char* question;
    const char* answers;
    const char* answers1;
    const char* answers2;
}trap_t;

typedef struct FontPosition_s{
    SDL_Rect position[4];
    /*
    SDL_Surface* textSurfQ;
    SDL_Surface* textSurfR[3];
    SDL_Texture* textTextureQ;
    SDL_Texture* textTextureR[3];
    TTF_Font* font;*/
}FontPosition_t;

FontPosition_t initFontPosition();
void initialiser_text_surf(FontPosition_t fontPos,SDL_Renderer* renderer,trap_t trap);
SDL_Texture* createText(SDL_Renderer *renderer, TTF_Font *font, const char* text, SDL_Color color,SDL_Rect* position);
trap_t* init_trap(trap_t trap1,trap_t trap2,trap_t trap3);
void showTrap(trap_t trap,player_t* player,SDL_Event* event);
void clean_trap(trap_t* trap);
void clean_FontPosition(FontPosition_t fontPos);
//void check_Trap(player_t* player,trap_t trap,char** map,int* i,walls_t* walls);

#endif