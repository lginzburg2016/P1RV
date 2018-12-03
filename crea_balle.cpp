#include "fonctions.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

balle crea_balle(char tab[MSIZE][MSIZE]){

  int score = 0;

  /*
  //creation aleatoire des balles 
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
  */

  //creation de balle sur la 1ere colonne, au milieu 
  int m = (int) MSIZE/2; //conversion forcee en entier !
  int n = 0;
  tab[m][n] = 'L';

  //construction du vecteur de deplacements
  int new_dep;
  vector<int> deplacements(0);
  for(int i=0; i<N_MOVES; i++){
    new_dep = rand()%9+1; //on aura possiblement le nombre 5 qui implique aucun deplacement, lors de l evolution des populations il devrait donc disparaitre
    deplacements.push_back(new_dep);
  }



  balle new_balle = balle(m,n,deplacements,score);
  //new_balle.setX(m);
  //new_balle.setY(n);
  return (new_balle);
}
