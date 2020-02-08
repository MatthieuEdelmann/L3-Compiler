//
// Created by matet on 06/02/2020.
//

#include "tableDesIdentificateurs.h"

int CHERCHER(char nom[LONG_MAX_IDENT]){
    int cmpResult;
    bool trouve = false;
    int debut = 0;
    int fin = NB_SYMBOLE - 1;
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
    int i = 0;
    int cmpResult;
    NB_SYMBOLE++;
    T_ENREG_IDENT newIdent;
    strcpy(newIdent.nom, nom);
    newIdent.tIdent = tIdent;
    while (cmpResult != 1){ //a finir
        cmpResult = strcmp(nom, TABLE_SYMBOLES[TABLE_INDEX[i]].nom);
        i++;
    }


    TABLE_SYMBOLES[NB_SYMBOLE - 1] = newIdent;
    return NB_SYMBOLE - 1;
}

void AFFICHE_TABLE_IDENT(){
    printf("Affichage de la table d'indentificateurs =\n");
    for (int i = 0; i < NB_SYMBOLE ; ++i) {
        printf("    %s\n",TABLE_SYMBOLES[TABLE_INDEX[i]]);
    }
}

void INITIALISER(){
    int TABLE_INDEX[NB_IDENT_MAX];
    NB_SYMBOLE = 0;
    TABLE_SYMBOLES = malloc(NB_SYMBOLE * sizeof(T_ENREG_IDENT));

   /* hashTable = malloc(sizeof(struct HashTable));
    hashTable->taille = 0;
    hashTable->contenu = calloc((size_t)hashTable->taille, sizeof(desc_identif));*/
}

void TERMINER(){
    free(TABLE_SYMBOLES);
}