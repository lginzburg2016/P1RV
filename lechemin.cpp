#include "fonctions.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <tgmath.h>
//#include <chrono>
//#include <thread>


using namespace std;



int main(){

	srand(time(NULL));

	//variables globales - initialisations
	char tab[MSIZE][MSIZE];
  char tab_ini[MSIZE][MSIZE];
	vector<balle> population;
  vector<balle> new_population;
	balle meilleureBalle = crea_balle(tab); //stockera la meilleure balle d une population
	int maxEval = 0; //stockera la meilleure evaluation trouvee dans une population de balles (c est a dire le nombre de tours passes avant la fin du jeu)
	bool fin_jeu = false;
	int tour = 0;
	int x_old, y_old, x, y, touche, passage_cour, ordre_porte;
	char value;
	bool incrementation=false;
	vector<int> depl, depl_mute;
  int num_depl;
  int degre_mutation, num_balle;
  balle balle_mutee, vieille_balle;

  cout << "Quel pourcentage de mutation souhaitez-vous appliquer aux populations ? Entre 0 et 100" << endl;
  cin >> degre_mutation;
	//generation de la matrice contenant les portes a passer
	generer_board(tab);

  // ON STOCKE LE TABLEAU INITIAL
  for(int m=0; m<MSIZE; m++){
    for(int n=0; n<MSIZE; n++){
      tab_ini[m][n] = tab[m][n];
    }
  }

	affichage(tab);

  //INITIALISATION DE LA POPULATION

  balle courante = crea_balle(tab);
  //on stocke les balles pour ensuite recuperer la meilleure de la population : selection par elitisme
  population.push_back(courante);
  courante.setScore(100);
  depl = courante.getListeDirections();

  for(int i = 0; i < N_POPULATION; i++){
    //ON TRAITE LA POPULATION COURANTE
  	for(int j = 0; j < N_INDIVIDUS; j++){

  		tour = 0;

  		fin_jeu = false;
  		courante = population[j];
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

  			//A chaque tour de boucle, on lit la valeur de deplacement suivante.
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
  					cout << "Deplacement impossible car obstacle." << endl;
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
  						cout << "Ce n est pas la bonne porte, il faut d abord passer par la porte : " << courante.getPassage() + 1 << endl;
  						incrementation = false;
  					}else{
  						tab[x][y] = 'L';
                          /*si le prochain deplacement est un mauvais deplacement, on passe directement au tour suivant
                          car sinon la valeur dans la porte passera à O au lieu de garder sa valeur !
                          */


  						//Si on ressort de la porte vers la gauche, on n incrémente pas et on laisse la case sur le chiffre
  						if (touche == 1 || touche == 4 || touche == 7){
  							tab[x_old][y_old] = value;
                              cout << "valeur de la porte : " << (int)value - 48 << endl;
  							incrementation = false;
  						}
  						//Si on traverse, on passe la porte à O, et on incrémente le score + l'ordre de passage
  						else{
  							tab[x_old][y_old] = 'O';
  							courante.setPassage(courante.getPassage() + 1);
  							incrementation = true;
                              cout << "incrementation : " << incrementation << endl;
  						}
  						//Apres un passage, il n y aura plus de numero au centre de la porte
  					}
  					break;
  				}
  				affichage(tab);
  				break;
  			default:
  				cout << "Mauvais deplacement" << endl;
  				break;
  			}

  			//On met a jour le score a chaque tour de boucle du while.
  			if(tour >= 1){
  				//Si on effectue deux deplacements a droite consecutifs et qu avant le deplacement la balle est entre deux montants de porte, on incremente positivement le score.
  				if((depl[tour] == 3 || depl[tour] == 6 || depl[tour] == 9) && (depl[tour-1] == 3 || depl[tour-1] == 6 || depl[tour-1] == 9) && (tab[x_old-1][y_old] == 'X') && (tab[x_old+1][y_old] == 'X')){
  					//remarque : s il n y a plus de numero au centre de la porte, c est qu elle aura deja ete franchie et on ne compte pas de points a nouveau !
  					cout << "On a passe une porte, incrementation vaut " << incrementation << endl;
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
  			//std::this_thread::sleep_for(std::chrono::milliseconds(100));
  		}


  		//comparaison entre le nombre de tours pendant lesquelles une balle a survecu avec le max enregistre
  		if (maxEval < tour){
  			meilleureBalle = courante;
  			maxEval = tour;
  		}

  		cout << "individu : " << i << endl; //pour relever le n° de l individu en cours
  	}

    //ON GARDE LA MEILLEURE BALLE DE LA POPULATION, ET ON FAIT MUTER LES AUTRES

    new_population.push_back(meilleureBalle);
    //ON MUTE CHAQUE BALLE
    for(int k=0; k< population.size()-1; k++){
      vieille_balle = population[k];
      depl_mute = vieille_balle.getListeDirections();
      //ON PREND EN COMPTE LE DEGRE DE MUTATION (un certain pourcentage du nb total de déplacements)
      for(int l=0; l< floor(depl_mute.size()*(degre_mutation/100)) ; l++){
        num_depl = rand()%depl_mute.size();
        depl_mute[num_depl] = rand()%9+1;
      }
      balle_mutee.setListeDirections(depl_mute);
      new_population.push_back(balle_mutee);
    }
    population = new_population;


  }

	affichage(tab);
    cout << "taille de la population : " << population.size() << endl;
    cout << "la meilleure balle a passe : " << meilleureBalle.getPassage() << " portes" << endl;
    cout << "elle a survecu pendant : " << tour << " tours" << endl;

	return 0;

}
