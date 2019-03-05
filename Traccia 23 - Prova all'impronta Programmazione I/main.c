//
//  main.c
//  Traccia 23 - Prova all'impronta Programmazione I
//
//  Created by Roberto Vecchio on 19/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 30
#define MAX_SURNAME_LEN 30
#define MAX_EXAM_NAME 100
#define MAX_N_EXAM 21

typedef struct studente{
    char name[MAX_NAME_LEN];
    char surname[MAX_SURNAME_LEN];
    int matricola;
}struct_studente;

typedef struct esame{
    char name[MAX_EXAM_NAME];
    int cfu;
    int voto;
}struct_esame;

typedef struct libretto{
    struct_studente strudente;
    struct_esame *esami;
}struct_libretto;


struct_studente stud = {
    "Roberto","Vecchio",124001871
};

struct_esame esam[] = {
    {"matematica 1", 9, 25},
    {"matematica 2", 9, 26},
    {"architettura", 12, 30},
    {"programmazione 1", 12,30},
    {"programmazione 2", 12,30},
    {"programmazione 3", 12,30},
    {"inglese", 6,27}
};

struct_libretto returnLib(struct_studente);

int main(int argc, const char * argv[]) {
    int i;
    
    struct_libretto librett = returnLib(stud);
    printf("NOME = %s \nCOGNOME = %s \nMATRICOLA = %d", librett.strudente.name, librett.strudente.surname, librett.strudente.matricola);
    printf("\nLISTA ESAMI SOSTENUTI : \n\n");
    for (i = 0; i < 21 &&  librett.esami[i].voto != 0 ; i++) {
        printf("ESAME = %s,  CFU = %d,  VOTO = %d\n", librett.esami[i].name, librett.esami[i].cfu, librett.esami[i].voto);
    }
    return 0;
}


struct_libretto returnLib(struct_studente studente){
    
    struct_libretto libr = {
        studente,esam
    };
    
    return libr;
}
