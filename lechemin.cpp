#include "fonctions.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <tgmath.h>
#include <chrono>
#include <thread>


using namespace std;



int main(){

	srand(time(NULL));

	//variables globales - initialisations
	char tab[MSIZE][MSIZE];
	char tab_ini[MSIZE][MSIZE];
	vector<balle> population;
	vector<balle> new_population;
	balle meilleureBalle; //stockera la meilleure balle d une population
	int maxEval = 0; //stockera la meilleure evaluation trouvee dans une population de balles (c est a dire le nombre de tours passes avant la fin du jeu)
	bool fin_jeu = false;
	int tour = 0;
	int x_old, y_old, x, y, touche, passage_cour, ordre_porte;
	char value;
	bool incrementation=false;
	vector<int> depl, depl_mute;
	int num_depl;
	int degre_mutation, num_balle;
	balle balle_mutee, vieille_balle, courante;

	//demande a l utilisateur quel degre de mutation appliquer pour l algorithme genetique
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
	for(int i = 0; i<N_INDIVIDUS; i++){
		//on stocke les balles pour ensuite recuperer la meilleure de la population :
		//selection par elitisme
		courante = crea_balle(tab);
		//on fixe le score initial de la balle a VAL_SCORE
		courante.setScore(VAL_SCORE);
		//ajout de la nouvelle balle dans le vecteur de population
		population.push_back(courante);
	}


	//POUR CHAQUE GENERATION...
	for(int i = 0; i < N_GENERATIONS; i++){

		//...ON TRAITE LA POPULATION COURANTE, (CHAQUE INDIVIDU)
		for(int j = 0; j < N_INDIVIDUS; j++){

			tour = 0;
			fin_jeu = false;
			courante = population[j];
			//on recupere la suite de deplacements a effectuer
			depl = courante.getListeDirections();

			//PARCOURS D'UNE BALLE
			while(!fin_jeu){
				//si on atteint le nombre maximal N_MOVES de deplacements autorises => fin du jeu !
				if (tour == N_MOVES){
					fin_jeu = true;
				}

				//on stocke la position courante de la balle, qui est amenee a etre modifiee
				x_old = courante.getX();
				y_old = courante.getY();

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
					//on deplace la balle
					courante.deplacement(touche);
					//recuperation des nouvelles coordonnees de la balle
					x = courante.getX();
					y = courante.getY();
					//on va regarder ce qu il y a dans la case du tableau avant de la modifier si possible
					value = tab[x][y];
					switch (value){
					//s il y a un montant de porte, on ne deplace pas la balle
					case 'X':
						//on reprend les anciennes coordonnees
						courante.setX(x_old);
						courante.setY(y_old);
						cout << "Deplacement impossible car obstacle." << endl;
						break;
					//si la case est vide, on peut y mettre la balle
					case ' ':
						tab[x][y] = 'O';
						tab[x_old][y_old] = ' ';
						break;
					//s il y a un numero, il s agit du centre d une porte !
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						//on bloque le passage si l ordre n est pas respecte et si on retourne en arriere (touches 1, 4 ou 7)
						if ( ((int)value - 48) > (courante.getPassage() + 1) || touche == 1 || touche == 4 || touche == 7){ //attention, en code ASCII, nombres commencent à 48 !
							courante.setX(x_old);
							courante.setY(y_old);
							cout << "Ce n est pas la bonne porte, il faut d abord passer par la porte : " << courante.getPassage() + 1 << endl;
							incrementation = false;
						}else{
							//on est ici dans le cas ou le numero de la porte respecte l ordre de passage
							/*si le prochain deplacement est un mauvais deplacement, on passe directement au tour suivant
							car sinon la valeur dans la porte passera à ' ' au lieu de garder sa valeur !
							C est a dire que quand le deplacement suivant est un 2 (vers le bas : montant porte), un 5 (sur place) ou un 8 (en haut : montant porte),
							on passe directement au tour suivant.
							*/
							while (depl[tour+1] == 2 || depl[tour+1] == 5 || depl[tour+1] == 8){
								tour += 1;
								courante.updateScore(-1);
							}

							//on fait entrer la balle dans la porte !
							tab[x][y] = 'O';

							//Si on ressort de la porte vers la gauche, on n incrémente pas et on laisse la case sur le chiffre
							if (touche == 1 || touche == 4 || touche == 7){
								tab[x_old][y_old] = value;
								cout << "valeur de la porte : " << (int)value - 48 << endl;
								incrementation = false;
							}
							//Si on traverse, on passe la porte à ' ', et on incrémente le score et l ordre de passage
							else{
								tab[x_old][y_old] = ' ';
								courante.setPassage(courante.getPassage() + 1);
								incrementation = true;
								cout << "incrementation : " << incrementation << endl;
							}
							//Apres un passage, il n y aura plus de numero au centre de la porte
						}
						break;
					}

					break;
				default:
					cout << "Mauvais deplacement" << endl;
					break;
				}

				affichage(tab);

				//On met a jour le score a chaque tour de boucle du while.
				if(tour >= 1){
					//Si on effectue deux deplacements a droite consecutifs et qu avant le deplacement la balle est entre deux montants de porte, on incremente positivement le score.
					if((depl[tour] == 3 || depl[tour] == 6 || depl[tour] == 9) && (depl[tour-1] == 3 || depl[tour-1] == 6 || depl[tour-1] == 9) && (tab[x_old-1][y_old] == 'X') && (tab[x_old+1][y_old] == 'X')){
						//remarque : s il n y a plus de numero au centre de la porte, c est qu elle aura deja ete franchie et on ne compte pas de points a nouveau !
						if (incrementation){ //si ce n etait pas ' ' au centre de la porte, c etait un numero et donc on incremente le score
							cout << "Porte franchie !!!!!!!!!!" << endl;
							courante.updateScore(10);
							incrementation = false;
						}
					}
					else{
						//quand on passe un pas de temps on diminue le score
						courante.updateScore(-1);
						//lorsque le score arrive a 0, le jeu est termine
						if (courante.getScore() <= 0){
							fin_jeu = true;
						}
					}
				}

				cout << "Score : " << courante.getScore() << endl;
				tour += 1 ;
				//ON CREE UN DELAI DE 100 MILLISECONDES ENTRE CHAQUE PAS DE TEMPS
				//permet un affichage plus lent des tableaux successifs
				//std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}


			//comparaison entre le nombre de tours pendant lesquelles une balle a survecu avec le max enregistre
			if (maxEval < tour){
				meilleureBalle = courante;
				maxEval = tour;
			}

			cout << "individu : " << j << endl; //pour relever le n° de l individu en cours

			//ON REINITIALISE LE BOARD
			for(int m=0; m<MSIZE; m++){
				for(int n=0; n<MSIZE; n++){
					tab[m][n] = tab_ini[m][n];
				}
			}
		}

		//quelques affichages pour faire un point sur la meilleure balle obtenue au sein d une population
		cout << "taille de la population : " << population.size() << endl;
		cout << "la meilleure balle a passe : " << meilleureBalle.getPassage() << " portes" << endl;
		cout << "elle a survecu pendant : " << maxEval << " tours" << endl;

		//ON VIDE LA VIEILLE POPULATION
		new_population.clear();

		//ON GARDE LA MEILLEURE BALLE DE LA POPULATION, ET ON FAIT MUTER LES AUTRES
		new_population.push_back(meilleureBalle);
		cout << "Selection et mutation en cours" << endl;

		//ON MUTE CHAQUE BALLE RESTANTE
		for(int k=0; k < N_INDIVIDUS-1; k++){
			vieille_balle = population[k];
			depl_mute = vieille_balle.getListeDirections();
			//ON PREND EN COMPTE LE DEGRE DE MUTATION (un certain pourcentage du nb total de déplacements)
			for(int l = 0; l < ceil(depl_mute.size()*(degre_mutation/100)) ; l++){
				num_depl = rand()%depl_mute.size();
				depl_mute[num_depl] = rand()%9+1;
			}
			//on fixe le vecteur de deplacement de la balle mutee avec le vecteur calcule ci avant
			balle_mutee.setListeDirections(depl_mute);
			//on fixe le score initial de la balle mutee a VAL_SCORE
			balle_mutee.setScore(VAL_SCORE);
			new_population.push_back(balle_mutee);
		}
		//ON MET A JOUR LA POPULATION ETUDIEE
		population = new_population;


		affichage(tab);
	}

	return 0;

}
