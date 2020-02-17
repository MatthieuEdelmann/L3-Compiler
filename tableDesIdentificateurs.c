//
// Created by matet on 06/02/2020.
//

#include "tableDesIdentificateurs.h"

int CHERCHER(char nom[LONG_MAX_IDENT]){
    //Recherche Dichotomique
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
        //init
        int i;
        int j = NB_IDENT - 1;
        int tmp, tmp2;
        //ajout du nouveau identificateur
        T_ENREG_IDENT newIdent;
        strcpy(newIdent.nom, nom);
        newIdent.tIdent = tIdent;
        TABLE_SYMBOLES[NB_IDENT] = newIdent;
        NB_IDENT++;
        for (i = 0; i < NB_IDENT - 1; ++i) {
            if(strcmp(nom,TABLE_SYMBOLES[TABLE_INDEX[i]].nom) != 1) break;
        }
        tmp = TABLE_INDEX[i];
        TABLE_INDEX[i] = NB_IDENT-1;
        i++;
        while(i < NB_IDENT - 1){
            tmp2 =  TABLE_INDEX[i];
            TABLE_INDEX[i] = tmp;
            tmp = tmp2;
            i++;
        }
        //AFFICHE_TABLE_IDENT();
    }
    return NB_IDENT - 1;
}



void AFFICHE_TABLE_IDENT(){
    printf("Affichage de la table d'indentificateurs =\n");
    for (int i = 0; i < NB_IDENT ; ++i) {
        printf("index[%d]:%d", i, TABLE_INDEX[i]);
        printf("   -> %s\n", TABLE_SYMBOLES[TABLE_INDEX[i]].nom);
    }
    printf("Affichage de la table d'indentificateurs brut =\n");
    for (int i = 0; i < NB_IDENT ; ++i) {
        printf("   - %s\n",TABLE_SYMBOLES[i].nom);
    }
}

