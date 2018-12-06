#include "fonctions.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void crea_porte(char tab[MSIZE][MSIZE], int numero){

  //on choisit une case aléatoire qui n'est ni dans la première ni dans la dernière colonne. Et qui est vide.

  int m = rand()%(MSIZE -1) + 1;
  cout << "Valeur de M : " << m << endl;
  int n = rand()%(MSIZE -1);
  cout << "Valeur de N : " << n << endl;
  while(tab[m][n] != 'O'){
    m = rand()%(MSIZE -1) + 1;
    cout << "Valeur de M : " << m << endl;
    n = rand()%(MSIZE -1);
    cout << "Valeur de N : " << m << endl;
  }

  bool crea_porte = false;
  //on choisit deux cases pour créer la porte, en vérifiant qu'elles rentrent toutes les deux dans la matrice.
  int m1, n1, direction;
  while(crea_porte == false){
    //On choisit la direction (haut ou bas) dans laquelle on place la porte.
    direction = rand()%2;
    switch(direction){
      case 0:
        m1 = m+2;
        n1 = n;
        break;
      case 1:
        m1 = m-2;
        n1 = n;
        break;
    }
    cout << "Valeur de M1 : " << m1 << endl;
    cout << "Valeur de N1 : " << n1 << endl;
    if ((m1 > 0) && (m1 < MSIZE) && (n1 > 0) && (n1 < MSIZE) && ( (tab[m-1][n] == 'X') || (tab[m+1][n] == 'X') ) && ( (tab[m][n-1] == 'X') || (tab[m][n+1] == 'X') ) ){ //on ne veut pas des portes collees ou imbriquees !
      //Si on peut placer la porte, c'est bon.
      tab[m][n] = 'X';
      tab[m1][n1] = 'X';
	  cout << "numero de porte : " <<  (char)numero << endl;
	  tab[(m+m1)/2][n] = (char)numero; //indique l ordre de passage de la porte, l inscrit au milieu des montants de la porte
      crea_porte = true;
      cout << "Porte créée." << endl;
    }
    else{
      //Sinon, on change les valeurs de m et n pour modifier la position de la porte.
      m = rand()%8 + 1;
      cout << "Valeur de M : " << m << endl;
      n = rand()%10;
      cout << "Valeur de N : " << n << endl;
      while(tab[m][n] != 'O'){
        m = rand()%8 + 1;
        cout << "Valeur de M : " << m << endl;
        n = rand()%10;
        cout << "Valeur de N : " << m << endl;
      }
    }
  }
}
