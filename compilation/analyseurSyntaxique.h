#ifndef UNTITLED_ANALYSEURSYNTAXIQUE_H
#define UNTITLED_ANALYSEURSYNTAXIQUE_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

T_UNILEX UNILEX;
char MESSAGE_ERREUR[50];
int NB_CONST_CHAINE = 0;
char* VAL_DE_CONST_CHAINE[50];//a voir
int* DERNIERE_ADRESSE_VAR_GLOB;

void ANASYNT();

bool PROG();
bool BLOC();
bool INSTRUCTION();
bool AFFECTATION();
bool LECTURE();
bool ECRITURE();
bool ECR_EXP();
bool EXP();
bool SUITE_TERME();
bool TERME();
bool OP_BIN();
bool DEFINIR_CONSTANTE(char nom, T_UNILEX ul);
bool DECL_CONST();
bool DECL_VAR();
#endif