#include "fonctions.h"

#include <iostream>
using namespace std;

#include <vector>

vector<balle*> * initialiserPop(int n){
    vector<balle*> *population = new vector<balle*>();
    for (int i=0; i<n; i++) {
        int x = rand()%n;
        int y = rand()%n;
        population->push_back(new balle(x,y));
    }
    return population;
}