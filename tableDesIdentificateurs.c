//
// Created by matet on 06/02/2020.
//

#include "tableDesIdentificateurs.h"


int CHERCHER(char nom[LONG_MAX_IDENT]){
    int indice;

    return indice;
}

int INSERER(char nom[LONG_MAX_IDENT], TYPE type){
    int indice;

    return indice;
}

void AFFICHE_TABLE_IDENT(){

}

void INITIALISER(){
    hashTable = malloc(sizeof(struct HashTable));
    hashTable->taille = 0;
    hashTable->contenu = calloc((size_t)hashTable->taille, sizeof(desc_identif));
}

void TERMINER(){
    free(hashTable->contenu);
    free(hashTable);
}