#include <stdio.h>
#include "analyseurLexical.h"
#include "tableDesIdentificateurs.h"


int main() {
    /*
    INITIALISER();
    LIRE_CAR();
    ANALEX();
    TERMINER();
     */
    INITIALISER1();
    INSERER("ZEBI",variable);
    INSERER("SABER",constante);
    printf(" est a la position %d\n",CHERCHER("SABER"));
    AFFICHE_TABLE_IDENT();
    TERMINER1();


}
