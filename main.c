#include <stdio.h>
#include "analyseurLexical.h"
#include "tableDesIdentificateurs.h"
#include "analyseurSyntaxique.h"


int main() {
     INITIALISER();
    ANASYNT();
    TERMINER();
    //TEST_ALL();
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
