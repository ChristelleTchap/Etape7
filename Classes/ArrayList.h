#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
//#include "Iterateur.h"
using namespace std;

template<class T>struct Cellule 
{
    T donnee;
    Cellule<T>* suivante;
};

template<class T>class Iterateur; 

template<class T>class ArrayList
 
{
private:
    Cellule<T>* pTete;

public:
    
    ArrayList();
    ~ArrayList();
    ArrayList(const ArrayList& autreListe);
    bool estVide() const;
    int getNombreElements() const;
    void Affiche() const;
    void insereElement(const T& val);
    T& getElement(int ind) const;
    T retireElement(int ind);

     ArrayList& operator=(const ArrayList& autreListe);

     friend class Iterateur<T>;

};

#endif 

    

    
    