#include "fonctions.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

balle crea_balle(char tab[MSIZE][MSIZE]){


  int m = rand()%10;
  cout << "Valeur de M : " << m << endl;
  int n = rand()%10;
  cout << "Valeur de N : " << n << endl;

  bool creation = false;
  while(!creation){
    int m = rand()%10;
    cout << "Valeur de M : " << m << endl;
    int n = rand()%10;
    cout << "Valeur de N : " << n << endl;

    if(tab[m][n] == 'O'){
      tab[m][n] = 'L';
      creation = true;
    }

    m = rand()%10;
    cout << "Valeur de M : " << m << endl;
    n = rand()%10;
    cout << "Valeur de N : " << n << endl;

  }

  balle new_balle = balle(m,n);
  //new_balle.setX(m);
  //new_balle.setY(n);
  return (new_balle);
}
