#include <stdio.h>
#include "analyseurLexical.c"
#include "analyseurSyntaxique.c"
#include "test.c"

int main() {
    INITIALISER();
    ANASYNT();
    TERMINER();
    //TEST_ALL();
}
