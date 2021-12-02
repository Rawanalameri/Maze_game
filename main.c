#include "data.h"

int main()
{
    int nbl = 0;
    int nbc = 0;
    char** map =lire_map("ressources/maze_map.txt");
    taille_map("ressources/maze_map.txt",&nbl,&nbc);
    player_t*player = init_player(32,32);
    SDL_Window* fenetre; // Déclaration de la fenêtre
    bool terminer = false;

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
    //player->texture = charger_image("ressources/personnage1.bmp",ecran);
    
    int width;
    int height; 
    int widthP;
    int heightP;
    Uint32 format;
    int access;
    int accessP;
    Uint32 formatP;
    SDL_QueryTexture(sprite,&format,&access,&width,&height);
    //SDL_QueryTexture(player->texture,&formatP,&accessP,&widthP,&heightP);
    height=height/10;
    width=width/16;
    widthP=widthP/6;
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
			}
			if(event.key.keysym.sym == SDLK_RIGHT){
				movement(map,player,'d'); // fléche vers la droite
			}
			if(event.key.keysym.sym == SDLK_UP){
                movement(map,player,'z');// fléche vers le haut
			}
			if(event.key.keysym.sym == SDLK_DOWN){
                movement(map,player,'s');// fléche vers le bas
			}
		}
        
    }
        SDL_RenderClear(ecran);
        SDL_Rect DestR[160];
        SDL_Rect DestR_P[6];
        SDL_Rect Src;
        for (int i=0;i<nbl;i++){
            for (int j = 0; j< nbc; j++)
            {
                if(map[i][j]=='L'){
                    DestR[i].x=8*width;
                    DestR[i].y=3*height;
                    DestR[i].w=width;
                    DestR[i].h=height;
                    Src.x=width*j;
                    Src.y=height*i;
                    Src.w=width;
                    Src.h=height;
                    SDL_RenderCopy(ecran,sprite,&DestR[i],&Src);
                   
                }
                else if(map[i][j]=='#'){
                    DestR[i].x=9*width;
                    DestR[i].y=3*height;
                    DestR[i].w=width;
                    DestR[i].h=height;
                    Src.x=width*j;
                    Src.y=height*i;
                    Src.w=width;
                    Src.h=height;
                    SDL_RenderCopy(ecran,sprite,&DestR[i],&Src);
              
                }
                else if (map[i][j]=='S'){
                    DestR[i].x=13*width;
                    DestR[i].y=3*height;
                    DestR[i].w=width;
                    DestR[i].h=height;
                    Src.x=width*j;
                    Src.y=height*i;
                    Src.w=width;
                    Src.h=height;
                    SDL_RenderCopy(ecran,sprite,&DestR[i],&Src);
              
                }
            }
        }
        DestR_P[player->y].x=1*widthP;
        DestR_P[player->y].y=0;
        DestR_P[player->y].w=widthP;
        DestR_P[player->y].h=heightP;
        Src.x=widthP*player->x;
        Src.y=heightP*player->y;
        Src.w=widthP;
        Src.h=heightP;
        //SDL_RenderCopy(ecran,player->texture,&DestR_P[player->y],&Src); 
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