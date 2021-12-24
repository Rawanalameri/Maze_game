#include "data.h"

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
    return walls;
}