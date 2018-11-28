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

    case 7:
        {
            x = (x-1)%MSIZE;
            y = (y-1)%MSIZE;
            break;
        }
    case 9:
        {
            x = (x-1)%MSIZE;
            y = (y+1)%MSIZE;
            break;
        }
    case 1:
        {
            x = (x+1)%MSIZE;
            y = (y-1)%MSIZE;
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
            x = (x-1)%MSIZE;
            break;
        }
    case 2:
        {
            x = (x+1)%MSIZE;
            break;
        }
    case 4:
        {
            y = (y-1)%MSIZE;
            break;
        }
    case 6:
         {
            y = (y+1)%MSIZE;
            break;
        }
    default :
        cout << "Mauvaise touche !" << endl;

    }
}

void balle::updateScore(){
  int new_score = balle.getScore();
  int x = balle.getX();
  int y = balle.getY();

  new_score -= 100;

}
