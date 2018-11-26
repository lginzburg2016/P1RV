//fonctions.h repertorie l'ensemble des fonctions

#pragma once

#define MSIZE 10
#include "balle.h"

void generer_board(char tab[MSIZE][MSIZE]);
void crea_porte(char tab[MSIZE][MSIZE]);
balle crea_balle(char tab[MSIZE][MSIZE]);
void affichage(char tableau[MSIZE][MSIZE]);
