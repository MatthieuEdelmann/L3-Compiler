#include "analyseurSyntaxique.h"
#include "analyseurLexical.h"
#include "tableDesIdentificateurs.h"
#include "generationInterpretation.h" 


void GENECODE_AFFECTATION_1(){
  //  printf("coucou");
    P_CODE[CO] = 11;//EMPI
    P_CODE[CO+1] = TABLE_SYMBOLES[CHERCHER(CHAINE)].adrv;
    CO = CO + 2;
}

void GENECODE_AFFECTATION_2(){
    //printf("coucou");
    P_CODE[CO] = 5;//AFFE
    CO++ ;
}

void GENECODE_LECTURE(char mot){
   // printf("coucou");
    P_CODE[CO] = 11;//EMPI
    P_CODE[CO+1] = TABLE_SYMBOLES[CHERCHER(CHAINE)].adrv;
    P_CODE[CO+2] = 6;//LIRE
    CO = CO + 3;
}

void GENECODE_ECRITURE(){
    //printf("coucou");
    P_CODE[CO] = 7; //ECRL
    CO++;
}

void GENECODE_OP_BIN(T_UNILEX op){
    SOM_PILOP++;
    if (op == plus){
        PILOP[SOM_PILOP] = 0;//ADDI
       
    }
    else if (op == moins){
        PILOP[SOM_PILOP] = 4;//MOIN
    }
    else if (op == mult){
        PILOP[SOM_PILOP] = 2;//MULT
    }
    else
    {
        PILOP[SOM_PILOP] = 3;//DIVI
    }
    

}

void GENECODE_TERME_ENTIER(){
    P_CODE[CO] = 11;//EMPI
    P_CODE[CO+1] = NOMBRE;
    CO = CO + 2;
}

void GENECODE_TERME_ID(){
    P_CODE[CO] = 11;//EMPI
    P_CODE[CO+1] = TABLE_SYMBOLES[CHERCHER(CHAINE)].adrv;
    P_CODE[CO +2] = 12;//CONT
    CO = CO + 3;
}

void INTERPRETER(){
    /*while (P_CODE[CO] != NULL)
    {
        switch (P_CODE[CO])
        {
        case 'ADDI':
            PILEX[SOM_PILEX-1] = PILEX[SOM_PILEX-1]+PILEX[SOM_PILEX];
            SOM_PILEX = SOM_PILEX-1;
            CO = CO + 1;
            break;
        
        case 'SOUS':
            PILEX[SOM_PILEX-1] = PILEX[SOM_PILEX-1]-PILEX[SOM_PILEX];
            SOM_PILEX = SOM_PILEX-1;
            CO = CO + 1;
            break;

        case 'MULT':
            PILEX[SOM_PILEX-1] = PILEX[SOM_PILEX-1]*PILEX[SOM_PILEX];
            SOM_PILEX = SOM_PILEX-1;
            CO = CO + 1;
            break;
        
        case 'DIVI':
            if (PILEX[SOM_PILEX] == 0){
                ERREUR(7);
            }
            else
            {
                PILEX[SOM_PILEX-1] = PILEX[SOM_PILEX-1]/PILEX[SOM_PILEX];
                SOM_PILEX = SOM_PILEX-1;
                CO = CO + 1;
            }
            break;
        
        case 'MOIN':
            PILEX[SOM_PILEX] = -PILEX[SOM_PILEX];
            CO++;
            break;
        
        case 'AFFE':
            MEMVAR[PILEX[SOM_PILEX-1]] = PILEX[SOM_PILEX];
            CO++;
            break;
        
        case 'LIRE':
            printf("%s",MEMVAR[PILEX[SOM_PILEX]]);
            //a voir
            SOM_PILEX = SOM_PILEX-1;
            CO++;
            break;
        
        case 'ECRL':
            printf("\n");
            CO++;
            break;
        
        case 'ECRE':
            printf("%s",PILEX[SOM_PILEX]);
            SOM_PILEX = SOM_PILEX-1;
            CO++;
            break;

        case 'ECRC': 
            int i = 1;
            ch = CHERCHER(P_CODE[CO+i]);
            while (ch == FINC){
                printf("%c",ch);
                i++;
                ch = chr(P_CODE[CO+i]);
            }
            CO = CO + i + 1;
            break;
        
        case 'EMPI':
            SOM_PILEX = SOM_PILEX+1;
            PILEX[SOM_PILEX] = P_CODE[CO+1];
            CO = CO +2;
            break;

        case 'CONT':
            PILEX[SOM_PILEX] = MEMVAR[PILEX[SOM_PILEX]];
            CO++;
            break;
        default:
            ERREUR(7); // si le caractere n'est pas compris parmi eux alors on le connais
            break;
        }
    } */
}