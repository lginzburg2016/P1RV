#include "fonctions.h"
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void generer_board(char tab[MSIZE][MSIZE]){
  // on crée notre tableau

  //on remplit le tableau de 0;
  for (int i=0; i<MSIZE; i++){
    for(int j=0; j<MSIZE; j++){
      tab[i][j] = 'O';
    }
  }

  crea_porte(tab);
  crea_porte(tab);
}