#include "map.h"

char** allouer_tab_2D(int n,int m){
    char** tab = malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        tab[i] = malloc(m*sizeof(char));
    }
    for (int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            tab[x][y]=' ';
        }
    }
    return tab;
}

void afficher_map(char** tab,int n,int m){
    for (int i=0;i<n;i++){
        for (int j = 0; j < m; j++)
        {
            printf("%c",tab[i][j]);
        }
        printf("\n");
    }
}

void desallouer_tab_2D(char** tab, int n){
    for(int i=0;i<n;i++){
        free(tab[i]);
    }
    free(tab);
}

void taille_map(const char* nomFichier, int* nbLig, int* nbCol){
    FILE *fichier;
    int nbl=0;
    int nbc=0;
    char s;
    int tmp;
    fichier =fopen(nomFichier,"r");
    if (fichier != NULL){
        while ((s= (char) fgetc(fichier))!=EOF){
            if (s =='\n'){
                if (nbl==0){
                   tmp=nbc;
                }
                else{
                    if(tmp<nbc){
                        tmp=nbc;
                    }
                }
                nbl++;
                nbc=0;
            }
            else{
                nbc++;
            }
        }
        fclose(fichier);
        *nbLig =nbl;
        *nbCol =tmp;
    }
    else{
        printf("le fichier est null");
    }
}

char** lire_map(const char* nomFichier){
    int nbl=0;
    int nbc=0;
    FILE *fichier = NULL;
    taille_map(nomFichier,&nbl,&nbc);
    char** tab = allouer_tab_2D(nbl,nbc);  
    fichier =fopen(nomFichier,"r");
    if (fichier != NULL){
        for (int i=0;i<nbl;i++){
            fscanf(fichier,"%s",tab[i]);
        }
    }
    fclose(fichier);
    return tab;  
}

char** modifier_caractere(char** tab,int n,int m,char ancien,char nouveau){
    for (int i=0;i<n;i++){
        for (int j = 0; j < m; j++)
        {
            if (tab[i][j]==ancien)
            {
                tab[i][j]=nouveau;
            }
        }  
    }
    return tab;
}
void ecrire_map(const char* nomFichier, char** tab,int n){
    FILE* fichier=NULL;

    fichier =fopen(nomFichier,"w");
    if(fichier!= NULL){
        for (int i = 0; i < n; i++){
            fprintf(fichier,"%s\n",tab[i]);
        }
    }
    else{
        printf("le fichier est null");
    }
    fclose(fichier);
}