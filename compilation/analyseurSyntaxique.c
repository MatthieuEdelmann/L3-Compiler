#include "analyseurSyntaxique.h"
#include "analyseurLexical.h"
#include "tableDesIdentificateurs.h"
#include "generationInterpretation.h"

void ANASYNT(){
    UNILEX = ANALEX();
    if(PROG()){
        printf("Le programme source est syntaxiquement correct\n"); 
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
    if ((UNILEX == motcle ) && (strcmp(CHAINE, "PROGRAMME") == 0)){// PROGRAMME
        printf(" PROGRAMME ");
        UNILEX = ANALEX();
        if (UNILEX  == ident){ //IDENT
            printf(" IDENT ");
            UNILEX = ANALEX();
            if (UNILEX == ptvirg){  // point virgule
                printf(" ;\n ");
                LIRE_CAR();// \n
                UNILEX = ANALEX();
                DECL_CONST();
                DECL_VAR();
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

/******************************
*FONCTION:DECL_CONST()
*   CONST a ='chane',b ='ass';
*   CONST a ='chane';
********************************/
bool DECL_CONST(){ 
    bool non_fin;
    char* nom_constante = (char * )malloc (40);
    int i=0;
    if ((UNILEX == motcle ) && (strcmp(CHAINE, "CONST") == 0)){
        printf("DECL_CONST --> ");
        UNILEX = ANALEX();
        non_fin = true;
        while(non_fin == true){
        if (UNILEX == ident){
            printf(" IDENT --> ");       
            printf(" %s",CHAINE);
            //nom_constante=CHAINE; 
            strcpy(nom_constante,CHAINE);
            if (CHERCHER(nom_constante) == -1){
                UNILEX = ANALEX();
                if (UNILEX == eg){
                    printf(" = ");
                    UNILEX = ANALEX();
                    if (UNILEX == ent || UNILEX == ch){
                        if (UNILEX == ent ){
                            printf("%d",NOMBRE);
                            int indice_insertion =INSERER(nom_constante,constante);
                            TABLE_SYMBOLES[indice_insertion-1].contenu = NOMBRE;
                            TABLE_SYMBOLES[indice_insertion-1].type = 0;
                         }
                        if (UNILEX == ch ){
                            printf("%s",CHAINE);
                            int indice_insertion =INSERER(nom_constante,constante);
                            TABLE_SYMBOLES[indice_insertion-1].type = 1;
                            //printf(" ##%d",NB_CONST_CHAINE);
                            VAL_DE_CONST_CHAINE[NB_CONST_CHAINE] = (char * )malloc (40);
                            strcpy(VAL_DE_CONST_CHAINE[NB_CONST_CHAINE],CHAINE);
                            TABLE_SYMBOLES[indice_insertion-1].contenu = NB_CONST_CHAINE;
                            NB_CONST_CHAINE ++;
                        }
                            UNILEX = ANALEX();
                        
                                if ( UNILEX ==virg){
                                    printf(" , ");
                                    UNILEX = ANALEX();
                                }
                                else if (UNILEX == ptvirg){
                                    printf(" ; ");
                                    LIRE_CAR();
                                    UNILEX = ANALEX();
                                    return true;
                                    }
                                else return false;
                        
                      //  }
                        //else return false;
                    }
                    else return false;
                }
                else return false;
            }
            else
            {
                char err[] = "Déjà déclaré";
                strcpy(MESSAGE_ERREUR,err);
                ERREUR(6);
                return false;
            }
        }
        else return false;
          }//end while
    }
    else return false; //erreur syntaxique dans la declaration des constantes mot clé CONST attendu
}

/******************************
*FONCTION:DECL_VAR()
*   VAR nb_;
*   VAR nb ,a ;
********************************/
bool DECL_VAR(){
    bool fin = false,erreur=false;
    char* nom_constante;
    if ((UNILEX == motcle ) && (strcmp(CHAINE, "VAR") == 0)){
        printf(" \n DECL_VAR  --> ");
        printf(" VAR ");
        UNILEX = ANALEX();
        while (fin ==false){
            if (UNILEX  == ident){ //IDENT
                printf(" IDENT -> ");
                printf("%s ",CHAINE);
                nom_constante=CHAINE; 
                if (CHERCHER(CHAINE) == -1){
                    //adresse de la variable 
                    int index=  INSERER(nom_constante,variable);
                    TABLE_SYMBOLES[index-1].type =0;
                    TABLE_SYMBOLES[index-1].contenu = 0;
                    //TABLE_SYMBOLES[index-1].adrv = 
                    DERNIERE_ADRESSE_VAR_GLOB ++;
                }
                else{
                    char err[] = "identificateur déjà déclaré";
                    strcpy(MESSAGE_ERREUR,err);
                    printf("%s",MESSAGE_ERREUR);
                    return false;
                }
                UNILEX = ANALEX();
                if (UNILEX == ptvirg){  // point virgule
                    printf(" ; \n");
                    LIRE_CAR();
                    UNILEX = ANALEX();
                    fin =true;
                }
                else if (UNILEX == virg){ // on boucle 
                    printf(" , ");
                    UNILEX = ANALEX();
                }
            }
            else erreur= true;
        }     
       if (erreur == true)   return false;
       return true;
    }
}

/******************************
*   FONCTION: BLOC()
*   Regarde que le programme est bien 
*   de la forme :
*
*
********************************/
bool BLOC(){
    printf(" BLOC \n");
    //DEBUT
    //INSTRUCTION
    //...
    //FIN
    bool fin = false,erreur;
    //UNILEX = ANALEX();
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
                    if (INSTRUCTION()){
                        UNILEX = ANALEX();
                    }
                    else return false;
                    
                }
                else if (UNILEX != ptvirg){
                    LIRE_CAR();
                    printf(" \n");
                    fin=true;
                }
            }
              
        //
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
*   
*   i := o__; 
********************************/
bool AFFECTATION(){
    if (UNILEX == ident){
        printf(" AFFECTATION --> ");
        if (CHERCHER(CHAINE) != -1){
            GENECODE_AFFECTATION_1();
            printf(" IDENT -> ");
           
            UNILEX = ANALEX();
            if (UNILEX == aff){
                printf("%s := ",CHAINE);
                UNILEX = ANALEX();
                if(EXP()){
                    GENECODE_AFFECTATION_2();
                    return true;
                }
                else return false;
            }
            else return false; // erreur syntaxique dnas une instruction d'affectation
        }
        else{
            char err[] = "Identificateur non déclaré ";
            strcpy(MESSAGE_ERREUR,err);
            ERREUR(6);
            return false;
        }
    }
    else return false; // erreur syntaxique dans une instruction d'affectation
}

/******************************
*FONCTION: LECTURE()
*   Fonction boolean 
*   LIRE (a )_
*   LECTURE (x ,y ,z )
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
                if (CHERCHER(CHAINE) != -1){
                    printf (" IDENT -> ");
                    printf("%s",CHAINE);
                    fin = false;
                    erreur = false;
                    while (fin == false){
                        //
                        GENECODE_LECTURE(CHAINE);
                        //ERREUR ici a re voir 
                        UNILEX = ANALEX();
                        if (UNILEX == virg){
                            printf(" , ");
                            UNILEX = ANALEX();
                            if (UNILEX == ident){
                                if (CHERCHER(CHAINE) != -1){
                                    printf("%s",CHAINE);
                                }
                                else{
                                    char err[] = "variable pas déclaré";
                                    strcpy(MESSAGE_ERREUR,err);
                                    ERREUR(6);
                                    return false;
                                }
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
                else
                {
                    char err[] = "variable pas déclaré";
                    strcpy(MESSAGE_ERREUR,err);
                    ERREUR(6);
                    return false;
                }
                
            }
            else return false;//erreur syntaxique dans instruction de lecture: 'ident' attendu
        }
        else return false;//erreur syntaxique dans instruction de lecture: '(' attendu
    }
    else return false;//erreur syntaxique dans instruction de lecture: mot clé 'LIRE' attendu
}

/******************************
*FONCTION: ECRITURE()
*   Fonction boolean 
*   ECRIRE (a )_
*   ECRIRE ('a')_
*   ECRIRE (a ,b )
*   ECRIRE ()_
*   ECRIRE ('XXXX',a )_
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
                    else {
                       // erreur = true;
                        fin = true;
                    }
                }
                else {
                    GENECODE_ECRITURE();
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
    //if (TERME() && SUITE_TERME() ){
    if (CHERCHER(CHAINE) != -1){
        if (TERME() && SUITE_TERME()){
            return true;
        }
        else return false;
    }
    else
    {
        char err[] = "Expression non déclaré";
        strcpy(MESSAGE_ERREUR,err);
        ERREUR(6);
        return false;
    }
    
}

/******************************
*FONCTION: SUITE_TERME()
*
*
********************************/
bool SUITE_TERME(){
    // add exp vide
    //  '  ' | OP_BIN EXP
  
    UNILEX = ANALEX(); 
    if ( CARLU == ';' || OP_BIN() && EXP()){
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
        GENECODE_TERME_ENTIER();
        printf(" %d ",NOMBRE);
        return true;
    }
    if (UNILEX == ident ){
        int index = CHERCHER(CHAINE);
        printf(" %s -----",TABLE_SYMBOLES[TABLE_INDEX[index]].nom);
        if( TABLE_SYMBOLES[TABLE_INDEX[index]].type == 0){
            printf(" IDENT -> ");
            GENECODE_TERME_ID(); 
            printf(" %s ",CHAINE); 
            return true;
        }
        else {
            char err[] = "Erreur de type ce n'est pas de type int ";
            strcpy(MESSAGE_ERREUR,err);
            ERREUR(6);
            return false;
        }
       
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
            GENECODE_OP_BIN(plus);
            return true;
            break;
        case moins:
            printf(" - ");
            GENECODE_OP_BIN(moins);
            return true;
            break;
        case mult:
            printf(" * ");
            GENECODE_OP_BIN(mult);
            return true;
            break;
        case divi:
            printf(" / ");
            GENECODE_OP_BIN(divi);
            return true;
            break;
        default:
            return false;
            break;
    }
}
