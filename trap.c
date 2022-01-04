#include "trap.h"

FontPosition_t initFontPosition(){
    FontPosition_t fontPos;
    for(int i=0;i<4;i++){
        fontPos.position[i].h=TRAPHT;
        fontPos.position[i].w=TRAPWT;
        if(i==0){
            fontPos.position[i].x =60;
            fontPos.position[i].y =30;  
        }else{
            fontPos.position[i].x =60;
            fontPos.position[i].y=30+fontPos.position[i].y; 
        }
    }
   //fontPos.font= TTF_OpenFont("ressources/arial.ttf",20);
   return fontPos;
}

SDL_Texture* createText(SDL_Renderer *renderer, TTF_Font *font, const char* text, SDL_Color color,SDL_Rect* position){
    SDL_Surface *text_img = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *text_tex = SDL_CreateTextureFromSurface(renderer, text_img);
    position->x=60;
    position->y=30;
    position->w=text_img->w;
    position->h=text_img->h;
    SDL_FreeSurface(text_img);
    return text_tex;
}
/*
void initialiser_text_surf(FontPosition_t fontPos,SDL_Renderer* renderer,trap_t trap){
    SDL_Color color_question={255,255,255,255};
    SDL_Color color_answer={255,0,255,0};
    fontPos.textSurfQ = TTF_RenderText_Solid(fontPos.font,trap.question,color_question);
    fontPos.textTextureQ= SDL_CreateTextureFromSurface(renderer,fontPos.textSurfQ);
    for (int i = 0; i < 3; i++)
    {
        fontPos.textSurfR[i] = TTF_RenderText_Solid(fontPos.font,trap.answers[i],color_answer);
        fontPos.textTextureR[i]= SDL_CreateTextureFromSurface(renderer,fontPos.textSurfR[i]); 
    }
}*/

trap_t* init_trap(trap_t trap1,trap_t trap2,trap_t trap3){
    trap_t* traps=malloc(4*sizeof(trap_t));
    traps[0]=trap1;
    traps[1]=trap2;
    traps[2]=trap3;
    return traps;
}

void showTrap(trap_t trap,player_t* player,SDL_Event* event){
    int px=0,py=0;
    //int px=fontPos.position[j+1].x,py=fontPos.position[j+1].y;
    //SDL_Surface* textSurfQ;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *fenetre=SDL_CreateWindow("Trap",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,400,600,SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer=SDL_CreateRenderer(fenetre,-1,0);
    TTF_Init();
    TTF_Font* font= TTF_OpenFont("ressources/arial.ttf",24);
    SDL_Color color={255,255,255,255};
    SDL_Rect* position;
    SDL_Rect*position1;
    SDL_Rect*position2;
    //textSurfQ = TTF_RenderText_Solid(font,trap.question,color);
    SDL_Texture* textTextureQ= createText(renderer,font,trap.question,color,position);
    SDL_Texture* textTextureR=createText(renderer,font,trap.answers,color,position1);
    SDL_Texture* textTextureR1=createText(renderer,font,trap.answers,color,position2);
    //SDL_FreeSurface(textSurfQ);
    //textSurfQ = TTF_RenderText_Solid(font,trap.answers,color);
    //SDL_Texture* textTextureR= SDL_CreateTextureFromSurface(renderer,textSurfQ);
    //SDL_FreeSurface(textSurfQ);
    TTF_CloseFont(font); 
    bool end=false;
    while(!end){
        while (SDL_PollEvent(event))
        {  
            if (event->type ==SDL_QUIT){
                end=true;
            }
            if (event->key.keysym.sym==SDLK_ESCAPE){  //si on appui sur la touche Echap, on quitte le jeu.
				end=true;
			}
            if (event->type== SDL_MOUSEBUTTONDOWN){
                if (event->button.state==SDL_PRESSED){
                    if(((event->button.x>=px) && (event->button.x<=( px +TRAPWT)))&&((event->button.y>=py)&&(event->button.y<=(py+TRAPHT)))){
                        player->score += 50;
                        end=true;
                    }else{
                        player->lives--;
                    }
                }
            }
                 
        }
        SDL_RenderCopy(renderer,textTextureQ,NULL,position);
        SDL_RenderCopy(renderer,textTextureR,NULL,position1);
        SDL_RenderCopy(renderer,textTextureR,NULL,position2);
        SDL_RenderPresent(renderer);
        SDL_UpdateWindowSurface(fenetre);
    }
    SDL_DestroyTexture(textTextureQ);
    SDL_DestroyTexture(textTextureR);
    SDL_DestroyTexture(textTextureR1);
    // Quitter SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);

    SDL_Quit();
    TTF_Quit();
}

void clean_trap(trap_t* trap){
    free(trap);
}
/*
void clean_FontPosition(FontPosition_t fontPos){
    SDL_FreeSurface(fontPos.textSurfQ);
    SDL_DestroyTexture(fontPos.textTextureQ);
    SDL_FreeSurface(fontPos.textSurfR);
    SDL_DestroyTexture(fontPos.textTextureR[i]);
    TTF_CloseFont(fontPos.font);
}*/
