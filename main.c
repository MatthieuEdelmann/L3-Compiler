#include <stdio.h>
#include "analyseurLexical.h"
#include "tableDesIdentificateurs.h"
#include "analyseurSyntaxique.h"

void INITIALISER();
void TERMINER();

int main() {
    INITIALISER_ANALEX();
    INITIALISER_TABLE_IDENT();
    ANASYNT();
    AFFICHE_TABLE_IDENT();
    TERMINER_ANALEX();
    TERMINER_TABLE_IDENT();
}


//TEST IDENT
/*

INSERER("TYERR",variable);
INSERER("ABDO",variable);
INSERER("AZ",constante);
INSERER("FAROUK",variable);
INSERER("ASAM",variable);
INSERER("SABER",constante);
printf(" est a la position %d\n",CHERCHER("SABER"));

*/