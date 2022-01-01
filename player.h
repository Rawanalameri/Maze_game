#ifndef PLAYER_H
#define PLAYER_H
#include "map.h"

#define PLAYERH 32
#define PLAYERW 32
#define SPEED 1

typedef struct player_s
{
    int x;
    int y;
    int posc;
    int posl;
    int score;
    int lives;
    int gameover;
}player_t;

player_t* init_player(int posc,int posl);
bool handle_movement_up(char** tab,player_t*player);
bool handle_movement_down(char** tab,player_t*player);
bool handle_movement_left(char** tab,player_t*player);
bool handle_movement_right(char** tab,player_t*player);
bool handle_mouvement_trap(char** tab,player_t* player);
void movement(char** tab,player_t *player,char deplacement);
void gameover(player_t* player,char** tab, int nbc,int nbl);
void free_player(player_t* player);

#endif