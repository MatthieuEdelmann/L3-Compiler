//
// Created by matet on 06/02/2020.
//

#ifndef COMPILATION_EDEMANN_FLEGON_TABLEDESIDENTIFICATEURS_H
#define COMPILATION_EDEMANN_FLEGON_TABLEDESIDENTIFICATEURS_H
#define LONG_MAX_IDENT 20

typedef enum {variable, constante, tableau, parametre, type, procedure, fonction} TYPE;

// Enregistrement décrivant une entrée de la table des symboles
typedef struct {
    char nom[LONG_MAX_IDENT];  // Nom de l'identificateur*
    TYPE type;
    int contenu;
    //si type est une variable           alors le contenu est considere comme une addresse
    //            une constante          alors le contenu est considere comme une valeur
    //            un  tableau            alors le contenu est considere comme une dimension
    //            un  parametre         alors le contenu est considere comme un mode de passage
    //            une procedure/fonction alors le contenu est considere comme un nombre de parametre
    TYPE typeDeSortie //le type de sortie est present lorsque le type est une fonction
} desc_identif;


int CHERCHER(char nom[LONG_MAX_IDENT]);
int INSERER(char nom[LONG_MAX_IDENT], TYPE type);
void AFFICHE_TABLE_IDENT();


#endif //COMPILATION_EDEMANN_FLEGON_TABLEDESIDENTIFICATEURS_H
