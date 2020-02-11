//
// Created by matet on 06/02/2020.
//

#include "tableDesIdentificateurs.h"

int CHERCHER(char nom[LONG_MAX_IDENT]){
    int cmpResult;
    bool trouve = false;
    int debut = 0;
    int fin = NB_IDENT - 1;
    int mil;
    while (!trouve && debut <= fin){
        mil = fin+debut/2;
        cmpResult = strcmp(nom, TABLE_SYMBOLES[TABLE_INDEX[mil]].nom);
        if(cmpResult == 0) trouve = true;
        else if (cmpResult == 1) debut = mil + 1;
        else fin = mil - 1;
    }
    if (trouve) return mil;
    else return -1;
}

int INSERER(char nom[LONG_MAX_IDENT], T_IDENT tIdent){
    if(NB_IDENT < NB_IDENT_MAX){
        int i = 0;
        int j = NB_IDENT - 1;
        int tmp;
        T_ENREG_IDENT newIdent;
        strcpy(newIdent.nom, nom);
        newIdent.tIdent = tIdent;
        TABLE_SYMBOLES[NB_IDENT] = newIdent;
        NB_IDENT++;
        // recherche du 1er nom superieur au newIdent.nom
        while (strcmp(nom, TABLE_SYMBOLES[TABLE_INDEX[i]].nom) != 1){
            i++;
        }
        //Decalage de données
        while(j > i) {
            TABLE_INDEX[j] = TABLE_INDEX[j + 1];
            j--;
        }
        //Attribution de la position du dernier Ident
        TABLE_INDEX[i] = NB_IDENT - 1;
    }
    return NB_IDENT - 1;
}

void AFFICHE_TABLE_IDENT(){
    printf("Affichage de la table d'indentificateurs =\n");
    for (int i = 0; i < NB_IDENT ; ++i) {
        printf("    %s\n",TABLE_SYMBOLES[TABLE_INDEX[i]].nom);
    }
}

void INITIALISER1(){
    NB_IDENT = 0;
    TABLE_SYMBOLES = malloc(NB_IDENT * sizeof(T_ENREG_IDENT));
    TABLE_INDEX = malloc(NB_IDENT * sizeof(int));
}

void TERMINER1(){
    free(TABLE_SYMBOLES);
}