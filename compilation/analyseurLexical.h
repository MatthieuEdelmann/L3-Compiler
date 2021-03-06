//
// Created by matet on 30/01/2020.
//

#ifndef UNTITLED_ANALYSEURLEXICAL_H
#define UNTITLED_ANALYSEURLEXICAL_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define LONG_MAX_IDENT 20
#define LONG_MAX_CHAINE 50
#define NB_MOTS_RESERVES 7
#define MAX_INT 32767

typedef enum {motcle, ident, ent, ch, virg, ptvirg, point, deuxpts, parouv, parfer, inf, sup, eg, plus, moins, mult, divi, infe, supe, diff, aff} T_UNILEX;

FILE *SOURCE ;
char CARLU;
int NOMBRE;
char CHAINE[LONG_MAX_CHAINE];
int NUM_LIGNE;
char TABLE_MOTS_RESERVES[NB_MOTS_RESERVES][9];
int CONST=0;

void ERREUR(int numeroErreur);
void LIRE_CAR();
void SAUTER_SEPARATEURS();

T_UNILEX RECO_ENTIER();
T_UNILEX RECO_CHAINE();
T_UNILEX RECO_IDENT_OU_MOT_RESERVE();
T_UNILEX RECO_SYMB();
T_UNILEX ANALEX();
void INSERE_TABLE_RESERVES(char nouveauMot[]);
bool EST_UN_MOT_RESERVE();
void INITIALISER();
void TERMINER();
#endif //UNTITLED_ANALYSEURLEXICAL_H
