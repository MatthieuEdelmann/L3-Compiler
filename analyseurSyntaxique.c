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
    printf(" PROG \n");
    // PRGRAMME ident ;
    //DECL_CONST 
    //DECL_VAR
    // BLOC
    if ((UNILEX == motcle ) && (strcmp(CHAINE, "PROGRAMME") == 0)){// PROGRAMME 
        printf(" PROGRAMME ");
        UNILEX = ANALEX();
        if (UNILEX  == ident){ //IDENT 
            printf(" IDENT ");
            UNILEX = ANALEX();
            if (UNILEX == ptvirg){  // point virgule  
                printf(" ; ");
                LIRE_CAR();// \n
                //DECL_CONST 
                //DECL_VAR
                if(BLOC()){
                   // UNILEX = ANALEX();
                    //if (UNILEX == point){  // point
                      //  printf(" . \n");
                        return true;
                   // }
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
    printf("BLOC \n");
    //DEBUT 
    //INSTRUCTION
    //...
    //FIN
    bool fin = false,erreur;
    UNILEX = ANALEX();
    if ((UNILEX == motcle) && (strcmp(CHAINE, "DEBUT") == 0)){//  DEBUT  
        printf(" DEBUT \n");
        UNILEX = ANALEX();//
        if (INSTRUCTION()){// INSTRUCTION
            UNILEX = ANALEX();
            while (fin == false){    
                if (UNILEX == ptvirg){
                    printf(" ; \n");
                    LIRE_CAR();
                    UNILEX = ANALEX();
                    INSTRUCTION();
                    UNILEX = ANALEX();
                }
                else {  
                    LIRE_CAR();
                    printf(" \n");
                    fin=true;
                }
            }
            UNILEX = ANALEX();        
            if ((UNILEX == motcle) && (strcmp(CHAINE, "FIN") == 0) ){ // FIN  
                printf(" FIN  "); 
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
    printf (" INSTRUCTION  -->");
    if ( AFFECTATION() || ECRITURE() || LECTURE() || BLOC() ) {     
        return true; 
    }
    else return false;
}

bool AFFECTATION(){   
    // ident := x_ 
    if (UNILEX == ident){ 
        printf(" AFFECTATION --> ");
        printf(" IDENT -> ");
        UNILEX = ANALEX(); 
        if (UNILEX == aff){  
            printf("%s := ",CHAINE);
            UNILEX = ANALEX();
            if(EXP()){             
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
    // LECTURE (x , y ,z)
    bool fin,erreur;
    if ((UNILEX  == motcle) && (strcmp(CHAINE, "LIRE") == 0)){ //LIRE  add && LIRE 
        printf(" LECTURE --> ");
        printf("LIRE ");
        UNILEX = ANALEX();
        if (UNILEX == parouv){     
            printf(" ( ");
            UNILEX = ANALEX();
            if (UNILEX == ident){
                printf (" IDENT -> ");
                printf("%s",CHAINE);
                fin = false;
                erreur = false;
                while (fin == false){
                    UNILEX = ANALEX();
                    if (UNILEX == virg){
                        printf(" , ");
                        UNILEX = ANALEX();
                        if (UNILEX == ident){
                          printf("%s",CHAINE);
                        }
                        else {
                            printf("erreur pas ident");
                            fin = true;
                            erreur = true ;
                        }
                    }
                    else fin = true;
                }
                if (UNILEX == parfer){
                    printf(" ) ");
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
    //ECRIRE (a ,b )
    //ECRIRE ( )_
    // ecrire plusieurs
    bool fin,erreur;
    if ((UNILEX  == motcle ) && (strcmp(CHAINE, "ECRIRE") == 0)){ //ECRIRE  add && ECRIRE 
        printf(" ECRITURE --> ");
        printf(" ECRIRE ");
        UNILEX = ANALEX();
        if (UNILEX == parouv){
            printf(" ( ");
            UNILEX = ANALEX();
            erreur = false;
            if (ECR_EXP()){ 
                printf("%s",CHAINE);
                UNILEX = ANALEX();
                fin = false;
               while(fin == false){
                    if (UNILEX == virg){
                         printf(" , ");
                        UNILEX = ANALEX();
                        printf(" %s ",CHAINE);
                        if (UNILEX == ident){
                            UNILEX = ANALEX(); 
                        }                    
                        else{
                            erreur = true;
                            fin = true;
                        } 
                    } 
                    else fin = true;
               }
            }
            if (erreur == true ){return false;} //erreur syntaxique dans instruction d'ecriture: expression incorrecte
            if (UNILEX == parfer){
                 printf(" ) ");
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
    if ( UNILEX == ch ){
        //UNILEX = ANALEX();
        return true;
    } 
    //else return false;
}
   
bool EXP(){
    printf(" EXP \n");
     UNILEX = ANALEX();
    // TERME SUITE_TERME 
    if (TERME() && SUITE_TERME() ){
        return true;
    }
    else return false;
}

bool SUITE_TERME(){
    //  '  ' | OP_BIN EXP
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
