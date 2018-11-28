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
    char touche;
    cout << "Deplacement ?" << endl;
    cin >> touche;
    switch (touche){
      case 27:
        fin_jeu = true;
        break;
      case 'A':
      case 'a':
      case 'Z':
      case 'z':
      case 'E':
      case 'e':
      case 'Q':
      case 'q':
      case 'S':
      case 's':
      case 'D':
      case 'd':
      case 'W':
      case 'w':
      case 'X':
      case 'x':
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
