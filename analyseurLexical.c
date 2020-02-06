//
// Created by matet on 30/01/2020.
//
#include "analyseurLexical.h"

void ERREUR(int numeroErreur){
    switch (numeroErreur){
        case 1:
            printf("Erreur n°%d / Ligne n°%d : Fin de fichier atteinte ",numeroErreur, NUM_LIGNE);
            break;
        case 2:
            printf("Erreur n°%d / Ligne n°%d : L'entier lu depasse la taille maximale",numeroErreur, NUM_LIGNE);
            break;
        case 3:
            printf("Erreur n°%d / Ligne n°%d : La chaine de characteres depasse la longeur maximale",numeroErreur, NUM_LIGNE);
            break;
        case 4:
            printf("Erreur n°%d / Ligne n°%d : Caractère non valide ",numeroErreur, NUM_LIGNE);
            break;
    }
    exit(0);
}// TEST bon 

void LIRE_CAR(){
    if (SOURCE != NULL){
        CARLU = fgetc(SOURCE);
        if (CARLU == '\n') NUM_LIGNE++ ; //Fin de ligne
        if (CARLU == EOF) ERREUR(1); //Fin de fichier
    }
}// TEST bon

void SAUTER_SEPARATEURS() {
    bool flag = false;
    while (!flag) {
        LIRE_CAR();//
        while (CARLU == ' '  || CARLU == '\n') {
            LIRE_CAR();
        }
        if (CARLU == '{') {
            while (CARLU != '}') {
                LIRE_CAR();
            }
            LIRE_CAR();
        }
        flag = true;
    }
}// TEST bon


T_UNILEX RECO_ENTIER(){ 
    char* CHAINE= malloc(sizeof(CHAINE));
    while (((int)CARLU >= 48) && ((int)CARLU <= 57)) { 
       CHAINE = strcat(CHAINE,&CARLU);
        LIRE_CAR(SOURCE);
    }
    NOMBRE = atoi(CHAINE);
    if(NOMBRE>MAX_INT)  ERREUR(2); // a faire mieux
    return ent;
}// TEST bon 


T_UNILEX RECO_CHAINE(){
    int i =0;
    LIRE_CAR();
    while ((int)CARLU != 39){
        if (i  >= LONG_MAX_CHAINE) ERREUR(3);
        CHAINE[i] = CARLU; 
        LIRE_CAR();
        i++;
    }
    LIRE_CAR();// a voir
    return ch;
}//TEST bon 


T_UNILEX RECO_IDENT_OU_MOT_RESERVE(){
    int i = 0;
    while(((int)CARLU >= 48 && (int)CARLU <= 57) || ((int)CARLU >= 65 && (int)CARLU <= 90) || ((int)CARLU >= 97 && (int)CARLU <= 122) || CARLU == '_'){
        if (i < LONG_MAX_CHAINE) {
            if ((int)CARLU >= 97 && (int)CARLU <= 122) CARLU -= 32;{
                toupper(CARLU);
                CHAINE[i] = CARLU;
            }
        }
        LIRE_CAR();
        i++;
        if (EST_UN_MOT_RESERVE()){
            return motcle;
        } 
        else {
            return ident;
        }
    }
}

bool EST_UN_MOT_RESERVE(){
        int i = 0;
        while (i<NB_MOTS_RESERVES){
            if (CHAINE[0]==TABLE_MOTS_RESERVES[0][0]){// faux 
                return true;
            } 
            i++;
        }
        return false;       
}

T_UNILEX RECO_SYMB(){
    switch (CARLU)
    {
    case ';':
        LIRE_CAR();
        return ptvirg;
        break;
    case '.':
        LIRE_CAR();
        return point;
        break;
    case '=':
        LIRE_CAR();
        return eg;
        break;
    case '+':
        LIRE_CAR();
        return plus;
        break;
    case '-':
        LIRE_CAR();
        return moins;
        break;
    case '*':
        LIRE_CAR();
        return mult;
        break;
    case '/':
        LIRE_CAR();
        return divi;
        break;
    case '(':
        LIRE_CAR();
        return parouv;
        break;
    case ')':
        LIRE_CAR();
        return parfer;
        break;
    case '>':
        LIRE_CAR();
        if(CARLU == '=' )
            LIRE_CAR();
            return supe;
            break;
        if(CARLU != '='){
            LIRE_CAR();
            return sup;
            break;
        }
    case ':':
        LIRE_CAR();
        if(CARLU == '=' )
            LIRE_CAR();
            return aff;
            break;
        if (CARLU != '='){
            return deuxpts;
            break;
        }
    case '<':
        LIRE_CAR();
        if(CARLU == '=' )
            LIRE_CAR();
            return infe;
            break;
        if( CARLU == '>'){ 
            LIRE_CAR();
            return diff;
            break;
        }
        else
        {
            return inf;
            break;
        }
    default:
        ERREUR(4); // si le caractere n'est pas compris parmi eux alors on le connais
        break;
    }
}

void ANALEX(){
    if ((CARLU == ' ')|| (CARLU == '{')){
        SAUTER_SEPARATEURS();
    }
    else if (((int)CARLU >= 48) && ((int)CARLU <= 57)){ // un entier
        RECO_ENTIER();
    }
    else if ((int)CARLU == 39){ // une apostrphe
        RECO_CHAINE();
    }
    else if (((int)CARLU >= 65 && (int)CARLU <= 90) || ((int)CARLU >= 97 && (int)CARLU <= 122)){     //reco ident OU MOT CLE
        RECO_IDENT_OU_MOT_RESERVE();
    }
    else
        RECO_SYMB();
}

void INITIALISER(){
    NUM_LIGNE = 1;
    SOURCE = fopen("SOURCE.txt", "r");
   /* char TABLE_MOTS_RESERVES[NB_MOTS_RESERVES][9] = {{0},{0}}; // initialise le tableau avec des '0'
   INSERE_TABLE_RESERVES("PROGRAMME");
    INSERE_TABLE_RESERVES("DEBUT");
    INSERE_TABLE_RESERVES("FIN");
    INSERE_TABLE_RESERVES("CONST");
    INSERE_TABLE_RESERVES("VAR");
    INSERE_TABLE_RESERVES("ECRIRE");
    INSERE_TABLE_RESERVES("LIRE");
    TABLE_MOTS_RESERVES;*/
}


void TERMINER(){
    fclose(SOURCE);
}
