//balle.h

#include <vector>

#pragma once

using namespace std;

class balle{
private:
	int x,y;//coordonnees de la balle 

	//liste des differentes positions prises par la balle au cours du temps
	vector<int> listeDirections; //creation de cette liste a la creation d une balle -> son chemin est predetermine donc !
	int score;
	int passage; //dernier numero de porte franchie par la balle

public:
	//accesseurs
	//getters
	int getX() const;
	int getY() const;
	vector<int> getListeDirections() const;
	int getScore() const;
	int getPassage() const;
	//setters
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
