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

//constructeurs
balle::balle(){
    x = 0;
    y = 0;
    listeDirections = vector<int>(0);
    score = 0;
}

balle::balle(int _x, int _y, vector<int> _listeDirections, int _score){
    x = _x;
    y = _y;
	listeDirections = _listeDirections;
    score = _score;
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
    Dans un premier temps, les deplacements seront geres par l'utilisateur.
    Il utilisera le clavier pour diriger la balle :
    1 = diagonale bas gauche, 3 = diagonale bas droite,
    7 = diagonale haut gauche, 9 = diagonale haut droite,
    2 = bas, 8 = haut, 4 = gauche, 6 = droite.

    Il faudra prendre en compte la presence de portes et le rayon de la balle --> a ecrire dans le main.
    */


    switch(touche){
    // On gère à chaque fois le cas où x ou y peut être négatif en le réinitialisant de l'autre côté du tableau.
    case 7:
        {
          if (x-1 < 0){
            x = MSIZE;
          }
          else{
            x = x-1;
          }
          if (y-1 < 0){
            y = MSIZE;
          }
          else{
            y = y-1;
          }
          break;
        }
    case 9:
        {
          if (x-1 < 0){
            x = MSIZE;
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
            y = MSIZE;
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
            x = MSIZE;
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
            y = MSIZE;
          }
          else{
            y = y-1;
          }
        }
    case 6:
         {
          y = (y+1)%MSIZE;
          break;
        }
    default :
		//on ne bouge pas
		x = x;
		y = y;
        cout << "Mauvaise touche !" << endl;

    }
}

void balle::updateScore(int deltaS){
	score += deltaS; //deltaS peut etre positif ou negatif
}
