//fonctions.h repertorie l'ensemble des fonctions

#pragma once

#define MSIZE 10
#define N_MOVES 10000
#define N_POPULATION 100
#define N_PORTES 3
#include "balle.h"

void generer_board(char tab[MSIZE][MSIZE]);
void crea_porte(char tab[MSIZE][MSIZE], int numero);
balle crea_balle(char tab[MSIZE][MSIZE]);
void affichage(char tableau[MSIZE][MSIZE]);
