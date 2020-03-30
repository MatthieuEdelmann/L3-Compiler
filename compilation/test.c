//test file
#include "analyseurLexical.h"
#include <assert.h>

void TEST_INIT(){
    INITIALISER();  
    assert(NUM_LIGNE == 1);
}// TEST BON

void TEST_ENTIER_1(){
    CARLU = 51; // ASCII de 3
    ANALEX();
    assert(NOMBRE == 3);
}// TEST BON

void TEST_ALL(){
     TEST_INIT();
     TEST_ENTIER_1();
}