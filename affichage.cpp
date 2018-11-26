#include "fonctions.h"
#include <iostream>


using namespace std;

void affichage(char tableau[MSIZE][MSIZE]){
  for(int i = 0; i<MSIZE; i++){
    for(int j=0; j<MSIZE; j++){
      cout << "\t" << tableau[i][j];
      }
    cout << endl;
    }
  }
