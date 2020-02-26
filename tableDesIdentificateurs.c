//
// Created by matet on 06/02/2020.
//

#include "tableDesIdentificateurs.h"

/******************************
 * FONCTION: CHERCHER(char nom[LONG_MAX_IDENT])
 * -------------------------------
 * cherche le mot entré en parametre via une
 * recherche dicothomique.
 *
 * RETOURNE: la position TABLE_INDEX du
 * mot recherche.
 * si mot non trouve alors -1.
********************************/
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

/******************************
 * FONCTION: INSERER(char nom[LONG_MAX_IDENT], T_IDENT tIdent)
 * -------------------------------
 * crée un nouveau objet de type T_ENREG_IDENT.
 * renseigne cet objet d'un nom et tIdent.
 * l'ajoute dans TABLE_SYMBOLES a la derniere position vide.
 * le positionne dans TABLE_INDEX de maniere triee.
 *
 * RETOURNE: la position TABLE_INDEX du
 * T_ENREG_IDENT ajouté.
********************************/
int INSERER(char nom[LONG_MAX_IDENT], T_IDENT tIdent){
    int i, j = NB_IDENT - 1, tmp, tmp2, positionFinale;

    if(NB_IDENT < NB_IDENT_MAX){
        T_ENREG_IDENT newIdent;
        strcpy(newIdent.nom, nom);
        newIdent.tIdent = tIdent;
        TABLE_SYMBOLES[NB_IDENT] = newIdent;
        NB_IDENT++;
        for (i = 0; i < NB_IDENT - 1; ++i) {
            if(strcmp(nom,TABLE_SYMBOLES[TABLE_INDEX[i]].nom) != 1) break;
        }
        positionFinale = i;
        tmp = TABLE_INDEX[i];
        TABLE_INDEX[i] = NB_IDENT-1;
        i++;
        while(i < NB_IDENT - 1){
            tmp2 =  TABLE_INDEX[i];
            TABLE_INDEX[i] = tmp;
            tmp = tmp2;
            i++;
        }
    }
    return positionFinale;
}


/******************************
 * FONCTION: AFFICHE_TABLE_IDENT()
 * -------------------------------
 * affichage de la table d'indentificateurs
 * triee selon les positions de TABLE_INDEX.
********************************/
void AFFICHE_TABLE_IDENT(){
    printf("AFFICHAGE: table d'indentificateurs =\n");
    printf("-------------------------------------");
    for (int i = 0; i < NB_IDENT ; ++i) {
        printf("%s\n ", TABLE_SYMBOLES[TABLE_INDEX[i]].nom);
        printf("= %d, ",TABLE_SYMBOLES[TABLE_INDEX[i]].contenu);
        if(TABLE_SYMBOLES[TABLE_INDEX[i]].tIdent == variable){
            printf("%s\n: ", "Variable.");
        } else{
            printf("%s\n: ", "Constante.");
        }
    }
}
/******************************
 * TEST a SUPPRIMER plus tard
********************************/
void AFFICHE_TABLE_IDENT_test(){
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

void INITIALISER_TABLE_IDENT() {
    NB_IDENT = 0;
}

void TERMINER_TABLE_IDENT() {
    //free(TABLE_SYMBOLES);
    //free(TABLE_INDEX);
    //  malloc non nécessaire selon le prof
}