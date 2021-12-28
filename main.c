#include "graphics.h"


int main()
{
    int nbl = 0,nbc = 0;
    char** map =lire_map("ressources/maze_map.txt");//lire le fichier
    taille_map("ressources/maze_map.txt",&nbl,&nbc);
    player_t*player = init_player(0,2);//initialisation du joueur
    SDL_Window* fenetre; // Déclaration de la fenêtre
    walls_t* walls=allocation_Walls();
    SDL_Renderer* ecran;
    //initialisation du renderer et la fenetre
    init_sdl(&fenetre,&ecran,SCREENW,SCREENH);
    // Charger l’images
    apply_texture(walls,ecran);
    SDL_Event event;
    // Boucle principale
    while(!player->gameover){
        handle_events(&event,player,map);
        gamrover(player,map,nbc,nbl);
        SDL_RenderClear(ecran);
        affichage_bricks(ecran,walls,map,nbc,nbl);
        SDL_RenderCopy(ecran,walls->texture_joueur,&(player->DestR),&(player->Src)); 
        SDL_RenderPresent(ecran);
        SDL_UpdateWindowSurface(fenetre);
    }

    // Libérer de la mémoire
    SDL_DestroyRenderer(ecran);
    desallouer_tab_2D(map,nbl);
    free_player(player);
    clean_walls(walls);
    // Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}