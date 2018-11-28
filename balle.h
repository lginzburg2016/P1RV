//balle.h

#include <vector>

#pragma once

using namespace std;

class balle{
private:
  int x,y; //position du centre de la balle
  //remarque : en 2D la balle apparaitra comme un disque

	//liste des diff�rentes positions prises par la balle au cours du temps
	vector<int> listeDirections; //cr�ation de cette liste � la cr�ation d'une balle -> son chemin est pr�d�termin� donc !
  int score;
public:
    //accesseurs
    int getX() const;
    int getY() const;
    vector<int> getListeDirections() const;
    int getScore() const;

    void setX(int _x);
    void setY(int _y);
    void setListeDirections(vector<int> _listeDirections);
    void setScore(int _score);


    //constructeurs
    balle(); //constructeur par defaut
    balle(int _x, int _y, vector<int> _listeDirections, int _score); //constructeur complet
    //balle(balle const &b); //constructeur par recopie

    //destructeur
    ~balle();

    //fonctions
    void deplacement(int touche);
    void updateScore();


};
