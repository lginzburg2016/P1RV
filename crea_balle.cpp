#include "fonctions.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

balle crea_balle(char tab[MSIZE][MSIZE]){

  int score = 0;
  int m = rand()%10;
  cout << "Valeur de M : " << m << endl;
  int n = rand()%10;
  cout << "Valeur de N : " << n << endl;

  bool creation = false;
  while(!creation){
    m = rand()%10;
    cout << "Valeur de M : " << m << endl;
    n = rand()%10;
    cout << "Valeur de N : " << n << endl;

    if(tab[m][n] == 'O'){
      tab[m][n] = 'L';
      creation = true;
    }
  }
  int new_dep;
  vector<int> deplacements(0);
  for(int i=0; i<N_MOVES; i++){
    new_dep = rand()%9+1;
    deplacements.push_back(new_dep);
  }



  balle new_balle = balle(m,n,deplacements,score);
  //new_balle.setX(m);
  //new_balle.setY(n);
  return (new_balle);
}
