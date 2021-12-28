#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>


char** allouer_tab_2D(int n,int m);
void afficher_map(char** tab,int n,int m);
void desallouer_tab_2D(char** tab,int n);
void taille_map(const char* nomFichier, int* nbLig, int* nbCol);
char** lire_map(const char* nomFichier);
char** modifier_caractere(char** tab,int n,int m,char ancien,char nouveau);
void ecrire_map(const char* nomFichier, char** tab,int n);
#endif