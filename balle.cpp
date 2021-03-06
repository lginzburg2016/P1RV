//balle.cpp

#include "fonctions.h"
#include <iostream>
using namespace std;

//getters
int balle::getX() const{
	return x;
}

int balle::getY() const{
	return y;
}

vector<int> balle::getListeDirections() const{
	return listeDirections;
}

int balle::getScore() const{
	return score;
}

int balle::getPassage() const{
	return passage;
}

//setters
void balle::setX(int _x){
	x = _x;
}

void balle::setY(int _y){
	y = _y;
}

void balle::setListeDirections(vector<int> _listeDirections){
	listeDirections = _listeDirections;
}

void balle::setScore(int _score){
	score = _score;
}

void balle::setPassage(int _passage){
	passage = _passage;
}

//constructeurs
balle::balle(){
	x = 0;
	y = 0;
	listeDirections = vector<int>(0);
	score = 0;
	passage = 0;
}

balle::balle(int _x, int _y, vector<int> _listeDirections, int _score, int _passage){
	x = _x;
	y = _y;
	listeDirections = _listeDirections;
	score = _score;
	passage = _passage;
}

/*balle::balle(balle const &b){
x = b.x;
y = b.y;
}*/

//destructeur
balle::~balle(){}

//deplacement
void balle::deplacement(int touche){
	/*
	Le vecteur listeDirections permet d automatiser les deplacements.
	Il peut contenir les nombres suivants :
	1 = diagonale bas gauche, 3 = diagonale bas droite,
	7 = diagonale haut gauche, 9 = diagonale haut droite,
	2 = bas, 8 = haut, 4 = gauche, 6 = droite
	et 5 = ne bouge pas.
	*/

	switch(touche){
		// On gère à chaque fois le cas où x ou y peut être négatif en le réinitialisant de l'autre côté du tableau.
	case 7:
		{
			if (x-1 < 0){
				x = MSIZE-1;
			}
			else{
				x = x-1;
			}
			if (y-1 < 0){
				y = MSIZE-1;
			}
			else{
				y = y-1;
			}
			break;
		}
	case 9:
		{
			if (x-1 < 0){
				x = MSIZE-1;
			}
			else{
				x = x-1;
			}
			y = (y+1)%MSIZE;
			break;
		}
	case 1:
		{
			x = (x+1)%MSIZE;
			if (y-1 < 0){
				y = MSIZE-1;
			}
			else{
				y = y-1;
			}
			break;
		}
	case 3:
		{
			x = (x+1)%MSIZE;
			y = (y+1)%MSIZE;
			break;
		}
	case 8:
		{
			if (x-1 < 0){
				x = MSIZE-1;
			}
			else{
				x = x-1;
			}
			break;
		}
	case 2:
		{
			x = (x+1)%MSIZE;
			break;
		}
	case 4:
		{
			if (y-1 < 0){
				y = MSIZE-1;
			}
			else{
				y = y-1;
			}
			break;
		}
	case 6:
		{
			y = (y+1)%MSIZE;
			break;
		}
	default :
		//on ne bouge pas
		//sert notamment pour la touche 5 qui implique aucun deplacement donc est consideree comme mauvaise
		cout << "Mauvaise touche !" << endl;
		break;

	}
}

void balle::updateScore(int deltaS){
	score += deltaS; //deltaS peut etre positif ou negatif
}
