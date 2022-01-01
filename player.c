#include "player.h"

player_t* init_player(int posc,int posl){
    player_t* player= malloc(sizeof(player_t));
    player->x=1;
    player->y=1;   
    player->score=0;
    player->posc=posc;
    player->posl=posl;
    player->lives=3;
    player->gameover=0;
    return player;
}


void gameover(player_t* player,char** tab, int nbc,int nbl){
    for (int i = 0; i<nbl ; i++)
    {
        for (int j = 0; j<nbc; j++)
        {
           if(tab[i][j]=='S'){
               if(player->x==j&& player->y==i){
                   player->gameover=1;
               }
           }
        }
    }
    if (player->lives==0){
        player->gameover=1;
    }
}

bool handle_movement_up(char** tab,player_t*player)
{
    if (tab[player->y-1][player->x]=='L'|| tab[player->y-1][player->x]=='S' || tab[player->y-1][player->x]=='T'){
        return true;
    }
    else{
        return false;
    }
}

bool handle_movement_down(char** tab,player_t*player)
{
    if (tab[player->y+1][player->x]=='L'|| tab[player->y+1][player->x]=='S'|| tab[player->y+1][player->x]=='T'){
        return true;
    }
    else{
        return false;

    }
}
bool handle_movement_left(char** tab,player_t*player)
{
    if (tab[player->y][player->x-1]=='L'|| tab[player->y][player->x-1]=='S'||tab[player->y][player->x-1]=='T'){
        return true;
    }
    else{
        return false;
    }
}
bool handle_movement_right(char** tab,player_t*player)
{
    if (tab[player->y][player->x+1]=='L'||tab[player->y][player->x+1]=='S'||tab[player->y][player->x+1]=='T'){
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
                player->y -= SPEED;
            }
            break;
        case 's':
            if(handle_movement_down(tab,player)){
                player->y+=SPEED;
            }
            break;
        case 'd':
            if(handle_movement_right(tab,player)){
                player->x+=SPEED;
            }
            break;
        case 'q':
            if(handle_movement_left(tab,player)){
                player->x-=SPEED;
            }
            break;
        }
}

void free_player(player_t* player){
    free(player);
}
