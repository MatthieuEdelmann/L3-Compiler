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
    if ((UNILEX == motcle ) ){// PROGRAMME 
        printf("PROGRAMME");
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

bool DECL_CONST(){
    return true;
}

bool DECL_VAR(){
    return true;
}

bool BLOC(){
    //DEBUT 
    //INSTRUCTION
    //...
    //FIN
    UNILEX = ANALEX();
    if (UNILEX == motcle){//  DEBUT  
        printf(" DEBUT ");
        UNILEX = ANALEX();//
        if (INSTRUCTION()){// INSTRUCTION
            if (UNILEX == motcle){ // FIN
                printf(" FIN ");
                return true;
            }
            else return false;
        } 
        else return false;
    }
    else return false;
}

bool INSTRUCTION(){
    // AFFECTATION | LECTURE | ECRITURE | BLOC 
    if (AFFECTATION() || ECRITURE() || LECTURE() || BLOC() ) {
       printf(" INSTRUCTION ");
        return true; 
    }
    else return false;
}

bool AFFECTATION(){
    if (UNILEX == ident){ 
        UNILEX = ANALEX();
        if (UNILEX == aff){ 
            UNILEX = ANALEX();
            if(EXP()){
                printf(" AFFECTATION ");
                return true;
            }
            else return false;  
        }
        else return false; // erreur syntaxique dnas une instruction d'affectation 
    }
    else{
        return false;// erreur syntaxique dans une instruction d'affectation 
    }
}

bool LECTURE(){
    // bug il faut ecrire 
    // LIRE (a )_ 
    // LECTURE (nb)
    // LECTURE (x , y ,z)
    bool fin,erreur;
    if (UNILEX  == motcle ){ //LIRE  add && LIRE 
        UNILEX = ANALEX();
        if (UNILEX == parouv){
       
            UNILEX = ANALEX();
            if (UNILEX == ident){
                UNILEX = ANALEX(); 
                fin = false;
                erreur = false;
                do { // debug la boucle 
                    if (UNILEX == virg){
                        fin = false;
                        printf("%c",CARLU);
                        UNILEX = ANALEX(); 
                        if(UNILEX == ident){
                            printf("%c",CARLU);
                            UNILEX = ANALEX();
                        }
                        else {
                            fin = true;
                            erreur = true;
                        }
                    }
                    else fin = true;
                } while (fin == false);
                
                if (UNILEX == parfer){
                    UNILEX = ANALEX();
                    printf(" LIRE ");
                    return true; 
                }
                else return false;//erreur syntaxique dans instruction de lecture: ')' attendu 
            }
            else return false;//erreur syntaxique dans instruction de lecture: 'ident' attendu 
        }
        else return false;//erreur syntaxique dans instruction de lecture: '(' attendu 
   }
    else return false;//erreur syntaxique dans instruction de lecture: mot clé 'LIRE' attendu
}

bool ECRITURE(){
    return false;
}

bool ECR_EXP(){
    return true;
}

bool EXP(){
    return true;
}

bool SUITE_TERME(){
    return true;
}

bool TERME(){
    if (UNILEX == ent || UNILEX == ident ){
        return true; 
    }
    else return false;
}

bool OP_BIN(){
    if (UNILEX == plus || UNILEX == moins || UNILEX == mult || UNILEX == div){
        return true;
    }
    else return false;
}



