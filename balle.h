//balle.h

#pragma once

class balle{
private:
    int x,y; //position du centre de la balle
    //remarque : en 2D la balle apparaitra comme un disque

public:
    //accesseurs
    int getX() const;
    int getY() const;
    void setX(int _x);
    void setY(int _y);

    //constructeurs
    balle(); //constructeur par defaut
    balle(int _x, int _y); //constructeur complet
    //balle(balle const &b); //constructeur par recopie

    //destructeur
    ~balle();

    //fonctions
    void deplacement(char touche);

};
