#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct player_s
{
    int x;
    int y;
    int width;
    int height;
    int score;
    int chances;
}player_t;

void init_player(player_t *player,char** tab,int nbl,int nbc,int w,int h);
bool handle_movement_up(char** tab,player_t*player);
bool handle_movement_down(char** tab,player_t*player);
bool handle_movement_left(char** tab,player_t*player);
bool handle_movement_right(char** tab,player_t*player);
void movement(char** tab,player_t *player,char deplacement);

#endif