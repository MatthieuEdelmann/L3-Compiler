#include "analyseurSyntaxique.h"
#include "analyseurLexical.h"


void ANASYNT(){
    UNILEX = ANALEX();
    if(PROG()){
        printf("Le programme source est syntaxiquement correct\n");
    }
    else ERREUR(0); //erreur syntaxique
}

bool PROG(){   
    // PRGRAMME ident ;
    //DECL_CONST 
    //DECL_VAR
    // BLOC
    if ((UNILEX == motcle ) && (strcmp(CHAINE, "PROGRAMME") == 0)){// PROGRAMME 
        printf(" PROGRAMME \n");
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
    if ((UNILEX == motcle) && (strcmp(CHAINE, "DEBUT") == 0)){//  DEBUT  
        printf(" DEBUT \n");
        UNILEX = ANALEX();//
        if (INSTRUCTION()){// INSTRUCTION
        // ajout de plusieurs instruction 
            if ((UNILEX == motcle) ){ // FIN
                printf(" FIN \n");
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
    printf (" -> ");
    if ( AFFECTATION() || ECRITURE() || LECTURE() || BLOC() ) {
       printf("  <- INSTRUCTION \n");
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
    else return false; // erreur syntaxique dans une instruction d'affectation 
}

bool LECTURE(){
    // bug il faut ecrire 
    // LIRE (a )_ 
    // LECTURE (nb)
    // LECTURE (x , y ,z)
    bool fin,erreur;
    if ((UNILEX  == motcle) && (strcmp(CHAINE, "LIRE") == 0)){ //LIRE  add && LIRE 
        UNILEX = ANALEX();
        if (UNILEX == parouv){     
            UNILEX = ANALEX();
            if (UNILEX == ident){
                UNILEX = ANALEX(); 
                fin = false;
                erreur = false;
               /* do { // debug la boucle 
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
               */ 
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
    //ECRIRE (a )_
    //ECRIRE ('a')_
    //ECRIRE ( )_
    // ecrire plusieurs
    bool fin,erreur;
    if ((UNILEX  == motcle ) && (strcmp(CHAINE, "ECRIRE") == 0)){ //ECRIRE  add && ECRIRE 
        UNILEX = ANALEX();
        if (UNILEX == parouv){
            UNILEX = ANALEX();
            erreur = false;
            if (ECR_EXP()){
                UNILEX = ANALEX();
                fin = false;
               // do{
                    if (UNILEX == virg){
                       UNILEX = ANALEX();// a 
                        
                      /*  erreur != ECR_EXP();
                        if (erreur){
                            fin = true;
                        }*/
                        
                         UNILEX = ANALEX(); // ) 
                         
                    } 
                    else fin = true;
              //  }while (fin == false);*/
            }
          //  if (erreur){return false;} //erreur syntaxique dans instruction d'ecriture: expression incorrecte
            if (UNILEX == parfer){
                UNILEX = ANALEX();
                printf(" ECRITURE ");
                return true;
            }
            else return false; //erreur syntaxique dnas instruction d'ecriture: ')' attendu 
        }
        else return false; //erreur syntaxique dans instruction d'ecriture: '(' attendu 
    }
    else return false; //erreur syntaxique dans instruction d'ecriture: mot clé 'ECRIRE' attendu 
}

bool ECR_EXP(){
    // EXP | 'ch'
    if ( UNILEX == ch || EXP() ){
       // UNILEX = ANALEX();
        return true;
    } 
    else return false;
}
   
bool EXP(){
    // TERME SUITE_TERME 
    if (TERME() && SUITE_TERME() ){
        return true;
    }
    else return false;
}

bool SUITE_TERME(){
    //  '  ' | TERME OP_BIN EXP
  //  if (TERME() && OP_BIN()){
        return true;
   // }
   // else return false;
}

bool TERME(){
    // ENT | IDENT | ( EXP ) | - TERME 
  //  if (UNILEX == ent || UNILEX == ident ){
        return true; 
   // }
    //else return false;
}

bool OP_BIN(){
    //if (UNILEX == plus || UNILEX == moins || UNILEX == mult || UNILEX == div){
        return true;
  //  }
  //  else return false;
}



