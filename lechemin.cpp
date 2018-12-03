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
  int tour = 0;
  while(!fin_jeu){
    int touche;
    int x_old = courante.getX();
    int y_old = courante.getY();
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
      default:
        cout << "Mauvais déplacement" << endl;
        break;
    }

    //On met à jour le score à chaque tour de boucle du while.
    vector<int> depl = courante.getListeDirections();
    if(tour >= 1){
      //Si on effectue deux déplacements à droite consécutifs et qu'avant le déplacement la balle est entre deux montants de porte, on incrémente positivement le score.
      if((depl[tour] == 3 || depl[tour] == 6 || depl[tour] == 9) && (depl[tour-1] == 3 || depl[tour-1] == 6 || depl[tour-1] == 9) && (tab[x_old-1][y_old] == 'X') && (tab[x_old+1][y_old] == 'X')){
        courante.updateScore(10);
      }
      else{
        courante.updateScore(-1);
      }
    }
    tour += 1 ;
  }

  affichage(tab);

  return 0;
}
