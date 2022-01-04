#include "trap.h"


int main()
{
    trap_t trap1= {{"The capital of Yemen:","Sanaa","Riyadh","Aden"}};
    trap_t trap2= {{"Light bulb inventor:","Edison","Tesla","Stern"}};
    trap_t trap3={{"Origin of the frensh language:","Frisian","Peninsula","Latin"}};
    trap_t* traps=init_trap(trap1,trap2,trap3);
    int nbl = 0,nbc = 0,i=0;
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
        gameover(player,map,nbc,nbl);
        if (map[player->y][player->x]=='T'){
            showTrap(traps[i],player,&event,i);
            map[player->y][player->x]='L';
            i++;
        }
        handle_events(&event,walls,player,map);
        SDL_RenderClear(ecran);
        affichage_bricks(ecran,walls,map,nbc,nbl);
        affichage_joueur(player,walls,ecran);
        SDL_RenderPresent(ecran);
        SDL_UpdateWindowSurface(fenetre);
    }
    // Libérer de la mémoire
    SDL_DestroyRenderer(ecran);
    desallouer_tab_2D(map,nbl);
    free_player(player);
    clean_walls(walls);
    clean_trap(traps);
    // Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}