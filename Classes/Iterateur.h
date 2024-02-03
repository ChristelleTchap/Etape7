#ifndef ITERATEUR_H
#define ITERATEUR_H

#include "ArrayList.h"  

template<class T> class Iterateur 
{

public:

    Iterateur(ArrayList<T>& liste);

    void reset();
    bool end() const;
    void operator++(int);

    operator T() const;

    T& operator&() const;

private:

    Cellule<T> *ptCourant;
    ArrayList<T> &lis;


};

#endif  
