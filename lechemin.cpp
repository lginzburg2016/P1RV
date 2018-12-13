#include "fonctions.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>


using namespace std;

int main(){
  vector<balle> population;
  char tab[MSIZE][MSIZE];
  srand(time(NULL));
  generer_board(tab);
  for(i=0, i<N_POPULATION; i++){
    balle iste = crea_balle(tab);
    population.push_back(iste);
  }
  affichage(tab);
  bool fin_jeu = false;
  int tour = 0;
  int x_old, y_old, x, y, touche, passage_cour, ordre_porte;
  char value;
  bool incrementation=false;
  vector<int> depl;
  for(int i = 0, i < N_POPULATION; i++){
    fin_jeu = false;
    balle courante = population[tour];
    courante.setScore(100);
    depl = courante.getListeDirections();
    while(!fin_jeu){
      if (tour == N_MOVES){
        fin_jeu = true;
      }
      x_old = courante.getX();
      y_old = courante.getY();

      /*cout << "Continuer ? (y/n)" << endl;
      cin >> cont;
      switch(cont){
        case 'n':
          fin_jeu = true;
          break;
        case 'y':
          break;
      }*/

      //A chaque tour de boucle, on lit la valeur de déplacement suivante.
      touche = depl[tour];
      cout << touche << endl;
      switch (touche){
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
                //Blocage si ordre passage mauvais
  				          if ( ((int)value - 48) > (courante.getPassage() + 1) || touche == 1 || touche == 4 || touche == 7){ //attention, en code ASCII, nombres commencent à 48 !
  					          courante.setX(x_old);
  					          courante.setY(y_old);
  					          cout << "Ce n'est pas la bonne porte, il faut passer par la porte n° : " << courante.getPassage() + 1 << " d'abord" << endl;
                      incrementation = false;
  				          }else{
                      //Si on ressort de la porte vers la gauche, on n'incrémente pas et on laisse la case sur le chiffre
  					          tab[x][y] = 'L';
                      if (touche == 1 || touche == 4 || touche == 7){
                        tab[x_old][y_old] = value;
                        incrementation = false;
                      }
                      //Si on traverse, on passe la porte à O, et on incrémente le score + l'ordre de passage
                      else{
  					            tab[x_old][y_old] = 'O';
                        courante.setPassage(courante.getPassage() + 1);
                        incrementation = true;
                      }
  					//Apres un passage, il n y aura plus de numero au centre de la porte
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
      if(tour >= 1){
        //Si on effectue deux deplacements a droite consecutifs et qu avant le deplacement la balle est entre deux montants de porte, on incremente positivement le score.
        if((depl[tour] == 3 || depl[tour] == 6 || depl[tour] == 9) && (depl[tour-1] == 3 || depl[tour-1] == 6 || depl[tour-1] == 9) && (tab[x_old-1][y_old] == 'X') && (tab[x_old+1][y_old] == 'X')){
  		//remarque : s il n y a plus de numero au centre de la porte, c est qu elle aura deja ete franchie et on ne compte pas de points a nouveau !
          cout << "On a passé une porte, incrementation vaut " << incrementation << endl;
  		    if (incrementation){ //si ce n etait pas 'O' au centre de la porte, c etait un numero et donc on incremente le score
             cout << "Porte franchie !!!!!!!!!!" << endl;
             courante.updateScore(10);
             incrementation = false;
  		       }
        }
        else{
          courante.updateScore(-1); //quand on passe un pas de temps on diminue le score
          if (courante.getScore() == 0){
            fin_jeu = true;
          }
        }
      }
      cout << "Score : " << courante.getScore() << endl;
      tour += 1 ;
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

  }

  affichage(tab);

  return 0;

  // IDEE : CREATION PORTE AVEC UN CHIFFRE AU CENTRE, AJOUT ATTRIBUT A LA BALLE AVEC L'INDICE DE LA DERNIERE PORTE PASSEE
}
