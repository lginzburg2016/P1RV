#include "fonctions.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

balle crea_balle(char tab[MSIZE][MSIZE]){

	//initialisation du score de la balle 
	int score = 0;
	//initialisation du numero de la derniere porte passee (ici aucune porte encore passee !)
	int passage = 0;

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

		if(tab[m][n] == ' '){
			tab[m][n] = 'O';
			creation = true;
		}
	}
	*/

	//creation des balles au meme endroit pour pouvoir comparer les individus de maniere fiable
	//creation de balle sur la 1ere colonne, au milieu 
	int m = (int) MSIZE/2; //conversion forcee en entier !
	int n = 0;
	tab[m][n] = 'O'; //la lettre O caracterise une balle

	//construction du vecteur de deplacements
	int new_dep;
	vector<int> deplacements(0);
	//on remplit aleatoirement le vecteur des deplacements avec autant de nombres qu il y a de mouvements autorises
	for(int i=0; i<N_MOVES; i++){
		new_dep = rand()%9+1; //on aura possiblement le nombre 5 qui implique aucun deplacement, lors de l evolution des populations il devrait donc disparaitre
		deplacements.push_back(new_dep);
	}


	//creation de la balle a partir des parametres fixes ci avant
	balle new_balle = balle(m,n,deplacements,score,passage);
	return (new_balle);
}
