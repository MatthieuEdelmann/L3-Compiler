//
// Created by matet on 06/02/2020.
//

#ifndef COMPILATION_EDEMANN_FLEGON_TABLEDESIDENTIFICATEURS_H
#define COMPILATION_EDEMANN_FLEGON_TABLEDESIDENTIFICATEURS_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LONG_MAX_IDENT 20
#define NB_IDENT_MAX 100

/*
typedef enum {variable, constante, tableau, parametre, type, procedure, fonction} T_IDENT;

// Enregistrement décrivant une entrée de la table des symboles
typedef struct {
    char nom[LONG_MAX_IDENT];  // Nom de l'identificateur*
    T_IDENT type;
    int contenu;
    //si type est une variable           alors le contenu est considere comme une addresse
    //            une constante          alors le contenu est considere comme une valeur
    //            un  tableau            alors le contenu est considere comme une dimension
    //            un  parametre          alors le contenu est considere comme un mode de passage
    //            une procedure/fonction alors le contenu est considere comme un nombre de parametre
    //T_IDENT typeDeSortie //le type de sortie est present lorsque le type est une fonction
} desc_identif;*/

typedef enum {variable, constante} T_IDENT;

typedef struct {
    char nom[LONG_MAX_IDENT];  // Nom de l'identificateur*
    T_IDENT tIdent;
    int contenu;
    //si type est une variable           alors le contenu est considere comme une addresse
    //            une constante          alors le contenu est considere comme une valeur
} T_ENREG_IDENT;



T_ENREG_IDENT TABLE_SYMBOLES[NB_IDENT_MAX];
int TABLE_INDEX[NB_IDENT_MAX];
int NB_IDENT;
//type P_T_ENREG_IDENT = ^T_ENREG_IDENT;

int CHERCHER(char nom[LONG_MAX_IDENT]);
int INSERER(char nom[LONG_MAX_IDENT], T_IDENT type);
void AFFICHE_TABLE_IDENT();




#endif //COMPILATION_EDEMANN_FLEGON_TABLEDESIDENTIFICATEURS_H
