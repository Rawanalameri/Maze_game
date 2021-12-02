#include "data.h"

base_t* init_base(player_t* player,int px,int py,int postx,int posty){
    base_t* base= malloc(sizeof(base_t));
    base->gameover=0;
    base->chances=3;
    base->player=player;
    base->wall=init_wall(px,py,postx,posty);
}
walls_t* init_wall(int px,int py,int postx,int posty){
    walls_t* walls= malloc(sizeof(walls_t));
    walls->bricks.w=BRICKW;
    walls->bricks.h=BRICKH;
    walls->bricks.x=BRICKW*postx;
    walls->bricks.y=BRICKH*posty;
    walls->Src.x=BRICKW*px;
    walls->Src.y=BRICKH*py;
    walls->Src.w=BRICKW;
    walls->Src.h=BRICKH;
}
//void gameOver(char** tab,int nbl,int nbc,base_t* base);
