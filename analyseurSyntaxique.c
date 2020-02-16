#include "analyseurSyntaxique.h"
#include "analyseurLexical.h"


void ANASYNT(){
    UNILEX = ANALEX();
    if(PROG()){
        printf("Le programme source est syntaxiquement correct");
    }
    else ERREUR(0); //erreur syntaxique
}

bool PROG(){
    // PRGRAMME ident ;
    //DECL_CONST 
    //DECL_VAR
    // BLOC
    if (UNILEX == motcle){// PROGRAMME 
        UNILEX = ANALEX();
        if (UNILEX  == ident){ //IDENT 
            UNILEX = ANALEX();
            if (UNILEX == ptvirg){  // point virgule 
                LIRE_CAR();// \n
                //DECL_CONST 
                //DECL_VAR
                if(BLOC()){
                    return true;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

bool INSTRUCTION(){
    // AFFECTATION | LECTURE | ECRITURE | BLOC 
    if (AFFECTATION() || LECTURE() || ECRITURE() || BLOC() ) {
        return true;
    }
    else return false;
}

bool ECRITURE(){
    return false;
}

bool LECTURE(){
    return true;
}

bool AFFECTATION(){
    return false;
/*    if (UNILEX == ident){
        UNILEX = ANALEX();
        if (UNILEX = aff){
            UNILEX = ANALEX();
            if(EXP()){
                return true;
            }
            else return false;
           
        }
        else return false; // erreur syntaxique dnas une instruction d'affectation 
    }
    else{
        return false;// erreur syntaxique dans une instruction d'affectation 
    }*/
}

bool OP_BIN(){
    if (UNILEX == plus || UNILEX == moins || UNILEX == mult || UNILEX == divi){
        return true;
    }
    else return false;
}

bool BLOC(){
    //DEBUT 
    //INSTRUCTION
    //...
    //FIN
    UNILEX = ANALEX();
    if (UNILEX != motcle){//  DEBUT 
        // printf("%c",CARLU);
        LIRE_CAR();
        //  printf("%c",CARLU);
        UNILEX = ANALEX();
        if (INSTRUCTION()){// INSTRUCTION
            LIRE_CAR();
            UNILEX = ANALEX();
            if (UNILEX != motcle){ // FIN
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}