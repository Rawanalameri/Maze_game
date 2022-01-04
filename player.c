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
    player->lose=0;
    return player;
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
