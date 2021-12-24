#include "player.h"

player_t* init_player(int posc,int posl){
    player_t* player= malloc(sizeof(player_t));
    player->x=1;
    player->y=1;   
    player->score=0;
    player->height=PLAYERH;
    player->width=PLAYERW;
    player->DestR.h=PLAYERH;
    player->DestR.w=PLAYERW;
    player->DestR.x=PLAYERW*posc;
    player->DestR.y=PLAYERH*posl;
    player->Src.w=PLAYERW;
    player->Src.h=PLAYERH;
    player->Src.x=PLAYERW*player->x;
    player->Src.y=PLAYERH*player->y;
    player->lives=3;
    player->gameover=0;
    return player;
}

void change_movement_player(player_t* player,int posc,int posl){
    player->DestR.h=PLAYERH;
    player->DestR.w=PLAYERW;
    player->DestR.x=PLAYERW*posc;
    player->DestR.y=PLAYERH*posl;
    player->Src.w=PLAYERW;
    player->Src.h=PLAYERH;
    player->Src.x=PLAYERW*player->x;
    player->Src.y=PLAYERH*player->y;
}


void gamrover(player_t* player,char** tab, int nbc,int nbl){
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
}

bool handle_movement_up(char** tab,player_t*player)
{
    if (tab[player->y-1][player->x]=='L'|| tab[player->y-1][player->x]=='S'){
        return true;
    }
    else{
        return false;
    }
}

bool handle_movement_down(char** tab,player_t*player)
{
    if (tab[player->y+1][player->x]=='L'|| tab[player->y+1][player->x]=='S'){
        return true;
    }
    else{
        return false;

    }
}
bool handle_movement_left(char** tab,player_t*player)
{
    if (tab[player->y][player->x-1]=='L'|| tab[player->y][player->x-1]=='S'){
        return true;
    }
    else{
        return false;
    }
}
bool handle_movement_right(char** tab,player_t*player)
{
    if (tab[player->y][player->x+1]=='L'||tab[player->y][player->x+1]=='S'){
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

void free_player(player_t* player){
    free(player);
}
