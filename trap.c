#include "trap.h"

trap_t* init_trap(trap_t trap1,trap_t trap2,trap_t trap3,trap_t trap4){
    trap_t* traps=malloc(4*sizeof(trap_t));
    traps[0]=trap1;
    traps[1]=trap2;
    traps[2]=trap3;
    traps[3]=trap4;
    return traps;
}

void showTrap(trap_t trap,player_t* player,SDL_Event* event){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* fenetre=SDL_CreateWindow("Trap",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,400,600,SDL_WINDOW_OPENGL);
    SDL_Renderer* renderer=SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    TTF_Font* font;
    init_ttf();
    font=load_font("ressources/only.ttf",14);
    bool end=false;
    const char* reponse_j;
    const char* r;
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    while(!end){
        apply_text(renderer,0,0,100,200,"trap.question",font);
        while (SDL_PollEvent(event))
        {  
            if (event->type ==SDL_QUIT){
                end=true;
            }
            if (event->type == SDL_KEYDOWN){
                if (event->key.keysym.sym==SDLK_ESCAPE){  //si on appui sur la touche Echap, on quitte le jeu.
				    end=true;
			    }
                if(event->key.keysym.sym==SDLK_KP_ENTER){
                    if(strcmp(reponse_j,trap.answer)==0){
                        player->score +=10;
                        end=true;
                    }else{
                        player->lives--;
                    }
                }
                else{
                    r= SDL_GetKeyName(event->key.keysym.sym);
                    reponse_j +=*r;
                    apply_text(renderer,0,201,100,200,reponse_j,font);
                }
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
    // Quitter SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    clean_font(font);
    SDL_Quit();
}