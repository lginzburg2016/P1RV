//balle.cpp

#include "fonctions.h"
#include <iostream>
using namespace std;

//accesseurs
int balle::getX() const{
    return x;
}

int balle::getY() const{
    return y;
}

void balle::setX(int _x){
    x = _x;
}

void balle::setY(int _y){
    y = _y;
}

//constructeurs
balle::balle(){
    x = 0;
    y = 0;
}

balle::balle(int _x, int _y){
    x = _x;
    y = _y;
}

/*balle::balle(balle const &b){
    x = b.x;
    y = b.y;
}*/

//destructeur
balle::~balle(){}

//deplacement
void balle::deplacement(char touche){
    /*
    Dans un premier temps, les deplacements seront geres par l'utilisateur.
    Il utilisera le clavier pour diriger la balle :
    W = diagonale bas gauche, X = diagonale bas droite,
    A = diagonale haut gauche, E = diagonale haut droite,
    S = bas, Z = haut, Q = gauche, D = droite.

    Il faudra prendre en compte la presence de portes et le rayon de la balle --> a ecrire dans le main.
    */


    switch(touche){

    case 'A':
    case 'a':
        {
            x = (x-1)%MSIZE;
            y = (y-1)%MSIZE;
            break;
        }
    case 'E':
    case 'e':
        {
            x = (x-1)%MSIZE;
            y = (y+1)%MSIZE;
            break;
        }
    case 'W':
    case 'w':
        {
            x = (x+1)%MSIZE;
            y = (y-1)%MSIZE;
            break;
        }
    case 'X':
    case 'x':
        {
            x = (x+1)%MSIZE;
            y = (y+1)%MSIZE;
            break;
        }
    case 'Z':
    case 'z':
        {
            x = (x-1)%MSIZE;
            break;
        }
    case 'S':
    case 's':
        {
            x = (x+1)%MSIZE;
            break;
        }
    case 'Q':
    case 'q':
        {
            y = (y-1)%MSIZE;
            break;
        }
    case 'D':
    case 'd':
        {
            y = (y+1)%MSIZE;
            break;
        }
    default :
        cout << "Mauvaise touche !" << endl;

    }


void balle::majPositions(){
	listePositions.push_back(Vector2(x,y));
}

}
