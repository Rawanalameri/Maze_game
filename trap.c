#include "trap.h"


SDL_Texture* createText(SDL_Renderer *renderer, TTF_Font *font,trap_t trap, SDL_Color color,SDL_Rect* position,int y,int i){
    SDL_Surface *text_img = TTF_RenderText_Solid(font,trap.text[i], color);
    SDL_Texture *text_tex = SDL_CreateTextureFromSurface(renderer, text_img);
    position->x=60;
    position->y=30+y;
    position->w=text_img->w;
    position->h=text_img->h;
    SDL_FreeSurface(text_img);
    return text_tex;
}

trap_t* init_trap(trap_t trap1,trap_t trap2,trap_t trap3){
    trap_t* traps=malloc(4*sizeof(trap_t));
    traps[0]=trap1;
    traps[1]=trap2;
    traps[2]=trap3;
    return traps;
}

void showTrap(trap_t trap,player_t* player,SDL_Event* event,int j){
    int y=30;
    int px,py;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *fenetre=SDL_CreateWindow("Trap",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,400,400,SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer=SDL_CreateRenderer(fenetre,-1,0);
    TTF_Init();
    TTF_Font* font= TTF_OpenFont("ressources/arial.ttf",20);
    SDL_Color color={255,255,255,255};
    SDL_Rect position[4];
    SDL_Texture* textTextureQ[4];
    SDL_Texture* bg=charger_image("ressources/bg_trap.bmp",renderer);
    for(int i=0;i<4;i++){
        textTextureQ[i]= createText(renderer,font,trap,color,&position[i],(i+1)*y,i);
    }
    TTF_CloseFont(font);
    player->lose=0; 
    while(!player->lose){
        SDL_RenderCopy(renderer,bg,NULL,NULL);
        while (SDL_PollEvent(event))
        {  
            if (event->type ==SDL_QUIT){
                player->lose=1;
            }
            if (event->key.keysym.sym==SDLK_ESCAPE){  //si on appui sur la touche Echap, on quitte le jeu.
                player->lose=1;
			}
            if (event->type== SDL_MOUSEBUTTONDOWN){
                if (event->button.state==SDL_PRESSED){
                    px=position[j+1].x;
                    py=position[j+1].y;
                    if((event->button.x>=px) && (event->button.x<=( px +position[j+1].w))){
                        if((event->button.y>=py)&&(event->button.y<=(py+position[j+1].h))){
                            player->score += 50;
                            player->lose=1;
                        }else{
                            player->lives -=1;
                        }
                    }else{
                        player->lives -=1;
                    }
                }
            }
            if (player->lives==0){
                player->lose=1;
            }
                 
        }
        for(int i=0;i<4;i++){
            SDL_RenderCopy(renderer,textTextureQ[i],NULL,&position[i]);
        }
        SDL_RenderPresent(renderer);
        SDL_UpdateWindowSurface(fenetre);
    }
    for (int i=0;i<4;i++){
        SDL_DestroyTexture(textTextureQ[i]);
    }
    // Quitter SDL
    SDL_DestroyTexture(bg);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    TTF_Quit();
}

void clean_trap(trap_t* trap){
    free(trap);
}