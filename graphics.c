#include "graphics.h"

walls_t* allocation_Walls(){
    walls_t* walls=malloc(sizeof(walls_t));
    return walls;
}

int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height)
{
    if (0 != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        fprintf(stderr, "Erreur initialisation de la SDL : %s", SDL_GetError());
        return -1;
    }
    if (0 != SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, window, renderer))
    {
        fprintf(stderr, "Erreur lors de la creation de l'image et du renderer : %s", SDL_GetError());
        return -1;
    }
    return 0;
}

SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer)
{
    SDL_Surface *img = NULL;
    SDL_Texture *texture = NULL;
    img = SDL_LoadBMP(nomfichier);
    if (NULL== img){
        fprintf(stderr,"Erreur dans le chargement image: %s", SDL_GetError());
        return NULL;
    }
    SDL_SetColorKey(img,SDL_TRUE, SDL_MapRGB(img->format,255,0,255));
    texture = SDL_CreateTextureFromSurface(renderer, img);
    // Libérer une surface
    SDL_FreeSurface(img);
    if (texture == NULL){
        fprintf(stderr,"Erreur dans le chargement image: %s", SDL_GetError());
        return NULL;
    }
    return texture;
}

void apply_texture(walls_t* walls,SDL_Renderer* ecran){
    walls->texture_joueur=charger_image("ressources/personnage.bmp",ecran);
    walls->texture_brick=charger_image("ressources/pavage.bmp",ecran);
}

void init_wall(walls_t* walls,int px,int py,int postx,int posty){
    walls->DestR.w=BRICKW;
    walls->DestR.h=BRICKH;
    walls->DestR.x=BRICKW*postx;
    walls->DestR.y=BRICKH*posty;
    walls->Src.x=BRICKW*px;
    walls->Src.y=BRICKH*py;
    walls->Src.w=BRICKW;
    walls->Src.h=BRICKH;
}

void affichage_bricks(SDL_Renderer* ecran,walls_t* walls,char** map,int nbc,int nbl){
    for (int i=0;i<nbl;i++){
        for (int j = 0; j< nbc; j++)
        {
            if(map[i][j]=='L'){
                init_wall(walls,j,i,11,0);
                SDL_RenderCopy(ecran,walls->texture_brick,&(walls->DestR),&(walls->Src));       
            }
            else if(map[i][j]=='#'){
                init_wall(walls,j,i,6,9);
                SDL_RenderCopy(ecran,walls->texture_brick,&(walls->DestR),&(walls->Src));              
            }
            else if (map[i][j]=='S'){
                init_wall(walls,j,i,5,2);
                SDL_RenderCopy(ecran,walls->texture_brick,&(walls->DestR),&(walls->Src));
            }
            else if (map[i][j]=='T'){
                init_wall(walls,j,i,0,7);
                SDL_RenderCopy(ecran,walls->texture_brick,&(walls->DestR),&(walls->Src));
            }
        }
    }
}

void affichage_joueur(player_t* player,walls_t* walls,SDL_Renderer* ecran){
    walls->DestR.h=PLAYERH;
    walls->DestR.w=PLAYERW;
    walls->DestR.x=PLAYERW*player->posc;
    walls->DestR.y=PLAYERH*player->posl;
    walls->Src.w=PLAYERW;
    walls->Src.h=PLAYERH;
    walls->Src.x=PLAYERW*player->x;
    walls->Src.y=PLAYERH*player->y;
    SDL_RenderCopy(ecran,walls->texture_joueur,&(walls->DestR),&(walls->Src)); 
}

void change_movement_player(player_t* player,walls_t* walls,int posc,int posl){
    player->posc=posc;
    player->posl=posl;
    walls->DestR.x=PLAYERW*player->posc;
    walls->DestR.y=PLAYERH*player->posl;
    walls->Src.x=PLAYERW*player->x;
    walls->Src.y=PLAYERH*player->y;
}



void handle_events(SDL_Event *event,walls_t* walls,player_t* player,char** map){
    while (SDL_PollEvent(event)){
        if (event->type ==SDL_QUIT){
            player->gameover=1;
        }
		//si une touche est appuyée
		if(event->type == SDL_KEYDOWN){
			if (event->key.keysym.sym==SDLK_ESCAPE){  //si on appui sur la touche Echap, on quitte le jeu.
				player->gameover=1;
			}
			if(event->key.keysym.sym == SDLK_LEFT){
				movement(map,player,'q'); // fléche vers la gauche
                change_movement_player(player,walls,1,1);
            }
			if(event->key.keysym.sym == SDLK_RIGHT){
				movement(map,player,'d'); // fléche vers la droite
                change_movement_player(player,walls,1,2);
            }
			if(event->key.keysym.sym == SDLK_UP){
                movement(map,player,'z');// fléche vers le haut
                change_movement_player(player,walls,1,3);
			}
			if(event->key.keysym.sym == SDLK_DOWN){
                movement(map,player,'s');// fléche vers le bas
                change_movement_player(player,walls,1,0);
            }
		}
        
    }
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


void clean_walls(walls_t* walls){
    SDL_DestroyTexture(walls->texture_joueur);
    SDL_DestroyTexture(walls->texture_brick);
    free(walls);
}
