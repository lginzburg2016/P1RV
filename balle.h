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
  int passage;

public:
    //accesseurs
    int getX() const;
    int getY() const;
    vector<int> getListeDirections() const;
    int getScore() const;
    int getPassage() const;

    void setX(int _x);
    void setY(int _y);
    void setListeDirections(vector<int> _listeDirections);
    void setScore(int _score);
    void setPassage(int _passage);


    //constructeurs
    balle(); //constructeur par defaut
    balle(int _x, int _y, vector<int> _listeDirections, int _score, int _passage); //constructeur complet
    //balle(balle const &b); //constructeur par recopie, a priori pas utile

    //destructeur
    ~balle();

    //fonctions
    void deplacement(int touche);
    void updateScore(int deltaS);


};
