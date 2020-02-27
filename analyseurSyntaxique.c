#include "analyseurSyntaxique.h"
#include "analyseurLexical.h"
#include "tableDesIdentificateurs.h"


void ANASYNT(){
    UNILEX = ANALEX();
    if(PROG()){
        printf("Le programme source est syntaxiquement correct\n");
          AFFICHE_TABLE_IDENT();
          char mot[10] = "Z";
          printf("\n  Le mot -> %s <- est à l'index n°%d \n", mot,CHERCHER(mot));
    }
    else ERREUR(0); //erreur syntaxique
}

/******************************
*   FONCTION: PROG()
*   Regarde que le programme est bien 
*   de la forme 
*
*   PROGRAMME ident;
*   BLOC
*
********************************/
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

/******************************
*   FONCTION: BLOC()
*   Regarde que le programme est bien 
*   de la forme :
*
*   DEBUT
*   INSTRUCTION
*   FIN
*
*   ou 
*
*   DEBUT
*   INSTRUCTION;
*   INSTRCTION;
*   ...
*   INSTRUCTION
*   FIN
*
********************************/
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

/******************************
*FONCTION: INSTRUCTION()
*   Regarde que le programme est bien 
*   une affectiation ou une ecriture ou une lecture 
*   ou un bloc. Si l'une de ses fonctions retourne vrai 
*   alors INSTRUCTION() va retourner vrai.
*   Si aucune des fontions ne retourne vrai, alors
*   INSTRUCTION() retourne faux.
*   AFFECTATION | LECTURE | ECRITURE | BLOC
*
********************************/
bool INSTRUCTION(){
    printf (" INSTRUCTION  -->");
    if ( AFFECTATION() || ECRITURE() || LECTURE() || BLOC() ) {
        return true;
    }
    else return false;
}

/******************************
*FONCTION: AFFECTATION()
*   Cette fonction boolean va affecter à un identifiant 
*   une expression. Pour vérifier cela 
*   On regarde que la premiere valeur est bien de
*   type ident suivie d'une affectation cad ':='.
*   Puis on appel la fonction EXP() qui si elle est vrai 
*   fait retourner vrai à AFFECTATION() sinon faux.
*   ident := x_
*
********************************/
bool AFFECTATION(){
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

/******************************
*FONCTION: LECTURE()
*   Fonction boolean 
*   bug il faut ecrire
*   LIRE (a )_
*   LECTURE (x , y ,z)
*
********************************/
bool LECTURE(){
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

/******************************
*FONCTION: LECTURE()
*   Fonction boolean 
*   ECRIRE (a )_
*   ECRIRE ('a')_
*   ECRIRE (a ,b )
*   ECRIRE ( )_
*
********************************/
bool ECRITURE(){
    bool fin,erreur;
    if ((UNILEX  == motcle ) && (strcmp(CHAINE, "ECRIRE") == 0)){ //ECRIRE  add && ECRIRE
        printf(" ECRITURE --> ");
        printf(" ECRIRE ");
        UNILEX = ANALEX();
        if (UNILEX == parouv){
            printf(" ( ");
            UNILEX = ANALEX();
            erreur = false;
            while(fin == false){
                if (ECR_EXP()){
                    printf("%s",CHAINE);
                    UNILEX = ANALEX();
                    fin = false;
                    if (UNILEX == virg){
                        printf(" , ");
                        UNILEX = ANALEX();
                    }
                    else fin = true;
                }
                else {
                    erreur = true;
                    fin = true;
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


/******************************
*FONCTION: ECR_EXP()
*
*
********************************/
bool ECR_EXP(){
    // EXP | 'ch'
    if ( UNILEX == ch ){
        printf(" CH -> ");
        return true;
    }
    else if (UNILEX == ident)
    {
        printf(" IDENT -> ");
        return true;
    }
    else return false;
}

/******************************
*FONCTION: EXP()
*
*
********************************/
bool EXP(){
    printf(" EXP --> ");
    // TERME SUITE_TERME
    if (TERME() ){
        //if (TERME() && SUITE_TERME() ){
        return true;
    }
    else return false;
}

/******************************
*FONCTION: SUITE_TERME()
*
*
********************************/
bool SUITE_TERME(){
    // add exp vide
    //  '  ' | OP_BIN EXP
    printf("%c 1",CARLU);
    UNILEX = ANALEX();

    if ( OP_BIN() && EXP() ){

        return true;
    }
    else return false;
}

/******************************
*FONCTION: TERME()
*
*
********************************/
bool TERME(){
    printf(" TERME --> ");
    // ENT | IDENT | ( EXP ) | - TERME
    UNILEX = ANALEX();
    if (UNILEX == ent ){
        UNILEX = ANALEX();
        printf(" ENT -> ");
        printf(" '%d' ",NOMBRE);
        return true;
    }
    if (UNILEX == ident ){
        printf(" IDENT -> ");
        printf(" '%s' ",CHAINE);
        return true;
    }
    else return false;
}

/******************************
*FONCTION: OP_BIN()
*
*
********************************/
bool OP_BIN(){
    printf(" OP_BIN -> ");
    switch (UNILEX)
    {
        case plus:
            printf(" + ");
            return true;
            break;
        case moins:
            printf(" - ");
            return true;
            break;
        case mult:
            printf(" * ");
            return true;
            break;
        case divi:
            printf(" / ");
            return true;
            break;
        default:
            return false;
            break;
    }
}
