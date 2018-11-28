#include "fonctions.h"

#include <iostream>
using namespace std;

#include <vector>


vector<balle*> * initialiserPop(char tab[MSIZE][MSIZE]){

    vector<balle*> *population = new vector<balle*>();


    for (int i=0; i<N_POPULATION; i++) {
		balle nouvelleBalle = crea_balle(tab);
        population->push_back(*nouvelleBalle);
    }

}