#ifndef UNTITLED_GENERATIONINTERPRETATION_H
#define UNTITLED_GENERATIONINTERPRETATION_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "analyseurLexical.h"

char MEMVAR [50];

int P_CODE[80];
int CO = 0;

int PILEX[50];
int SOM_PILEX;

T_UNILEX PILOP[50];
int SOM_PILOP = 0;
 

void INTERPRETER(); 
void GENECODE_AFFECTATION_1();
void GENECODE_AFFECTATION_2();

void GENECODE_LECTURE(char mot);

void GENECODE_OP_BIN(T_UNILEX op);

#endif