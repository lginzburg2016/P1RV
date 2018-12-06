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
  int x_old, y_old, x, y, touche, passage_cour, ordre_porte;
  char value;
  courante.setScore(100);
  while(!fin_jeu){
    x_old = courante.getX();
    y_old = courante.getY();
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
        x = courante.getX();
        y = courante.getY();
        value = tab[x][y];
        switch (value){
            case 'X':
                courante.setX(x_old);
                courante.setY(y_old);
                cout << "Déplacement impossible car obstacle." << endl;
                break;
            case 'O':
                tab[x][y] = 'L';
                tab[x_old][y_old] = 'O';
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
              //Implementer blocage si ordre passage mauvais
				if ( ((int)value - 48) > (courante.getPassage() + 1) ){ //attention, en code ASCII, nombres commencent à 48 !
					x = x_old;
					y = y_old;
					cout << "ce n'est pas la bonne porte, il faut passer par la porte n° : " << courante.getPassage() + 1 << " d'abord" << endl;
				}else{
					tab[x][y] = 'L';
					tab[x_old][y_old] = 'O';
					courante.setPassage(courante.getPassage() + 1);
					//remarque : apres un passage, il n y aura plus de numero au centre de la porte
				}
              break;


        }
        affichage(tab);
        break;
      default:
        cout << "Mauvais déplacement" << endl;
        break;
    }

    //On met a jour le score a chaque tour de boucle du while.
    vector<int> depl = courante.getListeDirections();
    if(tour >= 1){
      //Si on effectue deux deplacements a droite consecutifs et qu avant le deplacement la balle est entre deux montants de porte, on incremente positivement le score.
      if((depl[tour] == 3 || depl[tour] == 6 || depl[tour] == 9) && (depl[tour-1] == 3 || depl[tour-1] == 6 || depl[tour-1] == 9) && (tab[x_old-1][y_old] == 'X') && (tab[x_old+1][y_old] == 'X')){
		//remarque : s il n y a plus de numero au centre de la porte, c est qu elle aura deja ete franchie et on ne compte pas de points a nouveau ! 
		  if (value!='O'){ //si ce n etait pas 'O' au centre de la porte, c etait un numero et donc on incremente le score
			courante.updateScore(10);
		  }
      }
      else{
        courante.updateScore(-1); //quand on passe un pas de temps on diminue le score
      }
    }
    cout << "Score : " << courante.getScore() << endl;
    tour += 1 ;
  }

  affichage(tab);

  return 0;

  // IDEE : CREATION PORTE AVEC UN CHIFFRE AU CENTRE, AJOUT ATTRIBUT A LA BALLE AVEC L'INDICE DE LA DERNIERE PORTE PASSEE
}
