#include "fonctions.h"
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void generer_board(char tab[MSIZE][MSIZE]){
	// on cree notre tableau

	//on remplit le tableau de ' ' pour que les portes et les deplacements de la balle soient bien visibles
	for (int i=0; i<MSIZE; i++){
		for(int j=0; j<MSIZE; j++){
			tab[i][j] = ' ';
		}
	}

	//creation du nombre de portes voulu et fixe par N_PORTES
	for (int i = 1; i <= N_PORTES; i++){
		crea_porte(tab,i);
	}

}
