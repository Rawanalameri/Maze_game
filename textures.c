#include "textures.h"

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
