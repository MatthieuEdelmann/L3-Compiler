#include <stdio.h>
#include "analyseurLexical.c"
#include "analyseurSyntaxique.c"
//#include "tableDesIdentificateurs.c"
//#include "analyseurSemantique.c"
#include "test.c"
#include "generationInterpretation.c"

int main() {
    INITIALISER();
    ANASYNT();
    TERMINER();
    AFFICHE_TABLE_IDENT();
    //CREER_FICHIER_CODE();
    INTERPRETER();
}



 