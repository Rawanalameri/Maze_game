#include "data.h"

int main()
{
    int nbl = 0;
    int nbc = 0;
    char** map =lire_map("ressources/maze_map.txt");
    taille_map("ressources/maze_map.txt",&nbl,&nbc);
    player_t*player = init_player(1,1);
    SDL_Window* fenetre; // Déclaration de la fenêtre
    walls_t* walls;
    bool terminer=false;
    if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    // Créer la fenêtre
    fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 700, 700, SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    

    SDL_Renderer* ecran;
    ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    // Charger l’images
    SDL_Texture* sprite= charger_image("ressources/pavage.bmp",ecran);
    player->texture= charger_image("ressources/personnage.bmp",ecran);
        SDL_Event event;
    // Boucle principale
    while(!terminer){
        while (SDL_PollEvent(&event)){
        if (event.type ==SDL_QUIT){
            terminer = true;
        }
        
		//si une touche est appuyée
		if(event.type == SDL_KEYDOWN){
			if (event.key.keysym.sym==SDLK_ESCAPE){  //si on appui sur la touche Echap, on quitte le jeu.
				terminer= true;
			}
			if(event.key.keysym.sym == SDLK_LEFT){
				movement(map,player,'q'); // fléche vers la gauche
                change_movement_player(player,1,1);
            }
			if(event.key.keysym.sym == SDLK_RIGHT){
				movement(map,player,'d'); // fléche vers la droite
                change_movement_player(player,1,2);
            }
			if(event.key.keysym.sym == SDLK_UP){
                movement(map,player,'z');// fléche vers le haut
                change_movement_player(player,1,3);
			}
			if(event.key.keysym.sym == SDLK_DOWN){
                movement(map,player,'s');// fléche vers le bas
                change_movement_player(player,1,0);
            }
		}
        
    }
        SDL_RenderClear(ecran);
        for (int i=0;i<nbl;i++){
            for (int j = 0; j< nbc; j++)
            {
                if(map[i][j]=='L'){
                    walls=init_wall(j,i,9,3);
                    SDL_RenderCopy(ecran,sprite,&(walls->bricks),&(walls->Src));
                   
                }
                else if(map[i][j]=='#'){
                    walls=init_wall(j,i,10,3);
                    SDL_RenderCopy(ecran,sprite,&(walls->bricks),&(walls->Src));              
                }
                else if (map[i][j]=='S'){
                    walls=init_wall(j,i,13,3);
                    SDL_RenderCopy(ecran,sprite,&(walls->bricks),&(walls->Src));
                }
            }
        }
        SDL_RenderCopy(ecran,player->texture,&(player->DestR),&(player->Src)); 
        SDL_RenderPresent(ecran);
        SDL_UpdateWindowSurface(fenetre);
    }

    // Libérer de la mémoire
    SDL_DestroyRenderer(ecran);
    SDL_DestroyTexture(sprite);
    desallouer_tab_2D(map,nbl);
    free_player(player);
    // Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}