#include "player.h"

void init_player(player_t *player,char** tab,int nbl,int nbc,int w,int h){
    for (int i=0;i<nbl;i++){
        for (int j= 0; j < nbc; j++)
        {
            if(tab[i][j]=='P'){
                player->x=i;
                player->y=j;
            }
        }   
    }
    player->score=0;
    player->chances=3;
    player->height=h;
    player->width=w;
}

bool handle_movement_up(char** tab,player_t*player)
{
    if (tab[player->y-1][player->x]=='L'){
        return true;
    }
    else{
        return false;
    }
}

bool handle_movement_down(char** tab,player_t*player)
{
    if (tab[player->y+1][player->x]=='L'){
        return true;
    }
    else{
        return false;

    }
}
bool handle_movement_left(char** tab,player_t*player)
{
    if (tab[player->y][player->x-1]=='L'){
        return true;
    }
    else{
        return false;
    }
}
bool handle_movement_right(char** tab,player_t*player)
{
    if (tab[player->y][player->x+1]=='L'){
        return true;
    }
    else{
        return false;
    }
}

void movement(char** tab,player_t *player,char deplacement){   
        switch (deplacement)
        {
        case 'z':
            if(handle_movement_up(tab,player)){
                player->y--;
            }
            break;
        case 's':
            if(handle_movement_down(tab,player)){
                player->y++;
            }
            break;
        case 'd':
            if(handle_movement_right(tab,player)){
                player->x++;
            }
            break;
        case 'q':
            if(handle_movement_left(tab,player)){
                player->x--;
            }
            break;
        }
}
