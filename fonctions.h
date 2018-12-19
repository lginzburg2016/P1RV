//fonctions.h repertorie l'ensemble des fonctions

#pragma once

#define MSIZE 10 //taille du tableau
#define N_MOVES 1000 //nombre de mouvements permis pour une balle
#define N_GENERATIONS 10 //nombre de population que l'on teste (nombre de générations)
#define N_INDIVIDUS 10 //nombre d individus d une population
#define N_PORTES 3 //nombre de portes creees sur le tableau
#define VAL_SCORE 100 //score initial des balles

#include "balle.h"

void generer_board(char tab[MSIZE][MSIZE]);
void crea_porte(char tab[MSIZE][MSIZE], int numero);
balle crea_balle(char tab[MSIZE][MSIZE]);
void affichage(char tableau[MSIZE][MSIZE]);
