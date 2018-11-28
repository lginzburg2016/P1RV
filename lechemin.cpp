#include "fonctions.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

int main(){

  char tab[MSIZE][MSIZE];
  srand(time(NULL));
  generer_board(tab);
  balle courante = crea_balle(tab);
  affichage(tab);
  bool fin_jeu = false;
  while(!fin_jeu){
    int touche;
    cout << "Deplacement ?" << endl;
    cin >> touche;
    switch (touche){
      case 27:
        fin_jeu = true;
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 6:
      case 7:
      case 8:
      case 9:
        int x_old = courante.getX();
        int y_old = courante.getY();
        courante.deplacement(touche);
        //MODIFIER LA MATRICE AVEC LETTRES
        int x = courante.getX();
        int y = courante.getY();
        char value = tab[x][y];
        switch (value){
            case 'L':
            case 'X':
                courante.setX(x_old);
                courante.setY(y_old);
                cout << "Déplacement impossible car obstacle." << endl;
                break;
            case 'O':
                tab[x][y] = 'L';
                tab[x_old][y_old] = 'O';
                break;
        }


        affichage(tab);
        break;
    }
  }

  affichage(tab);

  return 0;
}
