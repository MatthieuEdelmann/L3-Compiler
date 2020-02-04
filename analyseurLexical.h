//
// Created by matet on 30/01/2020.
//

#ifndef UNTITLED_ANALYSEURLEXICAL_H
#define UNTITLED_ANALYSEURLEXICAL_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LONG_MAX_IDENT 20
#define LONG_MAX_CHAINE 50
#define NB_MOTS_RESERVES 7
#define MAX_INT 32767

typedef enum {motcle, ident, ent, ch, virg, ptvirg, point, deuxpts, parouv, parfer, inf, sup, eg, plus, moins, mult, divi, infe, supe, diff, aff} T_UNILEX;

FILE *SOURCE;
char CARLU;
int NOMBRE;
char CHAINE[LONG_MAX_CHAINE];
int NUM_LIGNE;
char TABLE_MOTS_RESERVES[NB_MOTS_RESERVES][9];

void ERREUR(int numeroErreur);
void LIRE_CAR( FILE *SOURCE);



#endif //UNTITLED_ANALYSEURLEXICAL_H