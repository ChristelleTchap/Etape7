#include <iostream>
using namespace std;

#include "Iterateur.h"
#include "ArrayList.h"
#include "Couleur.h"

template<class T>
Iterateur<T>::Iterateur(ArrayList<T>& ptr) : lis(ptr) 
{
    ptCourant=lis.pTete;
}

template<class T>
void Iterateur<T>::reset() 
{
    ptCourant = lis.pTete;
}

template<class T>
bool Iterateur<T>::end() const 
{
    return ptCourant == nullptr;
}

template<class T>
void Iterateur<T>::operator++(int) 
{
    if (ptCourant != nullptr) 
    {
        ptCourant = ptCourant->suivante;
    }
}

template<class T>
Iterateur<T>::operator T() const
{
    if (ptCourant != nullptr) 
    {
        return ptCourant->donnee;
    } 
    else 
    {
    
    }
    
}

template<class T>
T& Iterateur<T>::operator&() const 
{
    if (ptCourant != nullptr) 
    {
        return ptCourant->donnee;
    }
     else 
     {
        
    }
}

template class Iterateur<int>;
template class Iterateur<Couleur>;