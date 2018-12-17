//fonctions.h repertorie l'ensemble des fonctions

#pragma once

#define MSIZE 10
#define N_MOVES 1000
#define N_GENERATIONS 5 //Nombre de population que l'on teste (nombre de générations)
#define N_INDIVIDUS 5
#define N_PORTES 3
#define VAL_SCORE 100
#include "balle.h"

void generer_board(char tab[MSIZE][MSIZE]);
void crea_porte(char tab[MSIZE][MSIZE], int numero);
balle crea_balle(char tab[MSIZE][MSIZE]);
void affichage(char tableau[MSIZE][MSIZE]);
