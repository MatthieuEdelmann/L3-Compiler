#ifndef UNTITLED_ANALYSEURSYNTAXIQUE_H
#define UNTITLED_ANALYSEURSYNTAXIQUE_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "analyseurLexical.h"

T_UNILEX UNILEX;
void ANASYNT();

bool PROG();
bool DECL_CONST();
bool DECL_VAR();
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

#endif //COMPILATION_EDEMANN_FLEGON_ANALYSEURSYNTAXIQUE_H
