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
    SDL_Window *fenetre1=SDL_CreateWindow("Trap",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,400,600,SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer1=SDL_CreateRenderer(fenetre1,-1,0);
    TTF_Init();
    TTF_Font* font= TTF_OpenFont("ressources/arial.ttf",20);
    SDL_Color color={255,255,255,255};
    SDL_Surface* textSurf;
    textSurf = TTF_RenderText_Solid(font,trap.question,color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer1,textSurf);
    SDL_Rect textRect ={30,30,textSurf->w,textSurf->h};
    SDL_FreeSurface(textSurf);
    TTF_CloseFont(font);
    bool end=false;
    const char* reponse_j;
    const char* r;
    //SDL_SetRenderDrawColor(renderer1,0,0,225,225);
    while(!end){
      //  apply_text(renderer1,0,0,100,200,trap.question,font);
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
                   textSurf = TTF_RenderText_Solid(font,reponse_j,color);
               
          
                }
                       
            }
            
                 
        }

        SDL_RenderCopy(renderer1,textTexture,NULL, &textRect);
        SDL_RenderPresent(renderer1);
        SDL_UpdateWindowSurface(fenetre1);
    }
    // Quitter SDL
    SDL_DestroyRenderer(renderer1);
    SDL_DestroyWindow(fenetre1);

    SDL_Quit();
    TTF_Quit();
}