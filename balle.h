//balle.h

#include "Vector2.h"
#include <vector>

#pragma once

class balle{
private:
    int x,y; //position du centre de la balle
    //remarque : en 2D la balle apparaitra comme un disque

	//liste des différentes positions prises par la balle au cours du temps
	vector<int> listeDirections; //création de cette liste à la création d'une balle -> son chemin est prédéterminé donc !

public:
    //accesseurs
    int getX() const;
    int getY() const;
    void setX(int _x);
    void setY(int _y);

    //constructeurs
    balle(); //constructeur par defaut
    balle(int _x, int _y, vector<int> _listeDirections); //constructeur complet
    //balle(balle const &b); //constructeur par recopie

    //destructeur
    ~balle();

    //fonctions
    void deplacement(char touche);


};
