#include "ArrayList.h"
#include "Couleur.h"

#include <iostream>
using namespace std;

// Constructeur par défaut
template<class T> 
ArrayList<T>::ArrayList() : pTete(nullptr) {}

// Constructeur de copie
template<class T> 
ArrayList<T>::ArrayList(const ArrayList& autreListe): pTete(nullptr)
 {
     Cellule<T>* courAutreListe = autreListe.pTete;
    Cellule<T>* dernier = nullptr;

    while (courAutreListe != nullptr) 
    {
        Cellule<T>* newCellule = new Cellule<T>;
        {
            newCellule->donnee=courAutreListe->donnee;
            newCellule->suivante=nullptr;
        }
        
        if (dernier == nullptr) 
        {
            pTete = newCellule;
        } 
        else 
        {
            dernier->suivante = newCellule;
        }

        dernier = newCellule;
        courAutreListe = courAutreListe->suivante;
    }
    
 }

// Destructeur
template<class T> 
ArrayList<T>::~ArrayList() 
{
    Cellule<T>* cour = pTete;
    Cellule<T>* suivant = nullptr;

    while (cour != nullptr) 
    {
        suivant = cour->suivante;
        delete cour;
        cour = suivant;
    }

    pTete = nullptr;
}

// Méthode estVide
template<class T> 
bool ArrayList<T>::estVide() const 
{
    return pTete == nullptr;
}

// Méthode getNombreElements
template<class T> 
int ArrayList<T>::getNombreElements() const 
{
    int nbrElts= 0;
    Cellule<T>* cour = pTete;

    while (cour != nullptr) 
    {
        nbrElts++;
        cour = cour->suivante;
    }
     return nbrElts;
}

//Méthode affiche
template<class T> 
void ArrayList<T>::Affiche() const 
{
    Cellule<T>* cour = pTete;

    while (cour != nullptr) 
    {
        
        cout << cour->donnee << endl;

        cour = cour->suivante;
    }
      cout << endl;
}

// Méthode insereElement
template<class T>
void ArrayList<T>::insereElement(const T& val) 
{
    Cellule<T>* newCellule = new Cellule<T>;
    {
        newCellule->donnee=val;
        newCellule->suivante=nullptr;
    }

    if (pTete == nullptr) 
    {
        // Si la liste est vide, la nouvelle cellule devient la tête de la liste
        pTete = newCellule;
    } 
    else 
    {
        // Sinon, parcourir la liste pour trouver la dernière cellule et ajouter la nouvelle cellule à la fin
        Cellule<T>* cour = pTete;
        while (cour->suivante != nullptr) 
        {
            cour = cour->suivante;
        }
         cour->suivante = newCellule;
    }
}

// Méthode getElement
template<class T> 
T& ArrayList<T>::getElement(int ind) const 
{
    if (ind < 0) 
    {
        cout << "indice negatif " << endl;
    }

    Cellule<T>* cour = pTete;
    int i = 0; 
     while (cour != nullptr && i < ind) 
     {
        cour = cour->suivante;
        i++;
    }

    if (cour == nullptr) 
    {
      cout << "indice depasse la taille" << endl;  
    }

    return cour->donnee;


}

// Méthode retireElement
template<class T>
T ArrayList<T>::retireElement(int ind) 
{
    if (ind < 0) 
    {
        
    }

    Cellule<T>* cour = pTete;
    Cellule<T>* prec = nullptr;
    int i = 0;

    // Parcourir la liste jusqu'à l'indice ind
    while (cour != nullptr && i < ind) 
    {
        prec = cour;
        cour = cour->suivante;
        i++;
    }

    if (cour == nullptr) 
    {
        cout << "aucun element " << endl;
    }

    T valR = cour->donnee;

    if (prec == nullptr) 
    {
        pTete = cour->suivante; // Si l'élément à retirer est en tête de liste
    } 
    else 
    { 
        prec->suivante = cour->suivante;  // Sinon, ajuster le pointeur suivant du précédent pour exclure la cellule à retirer
    }

    // Supprimer la cellule
    delete cour;

    return valR;
}


// Opérateur =
template<class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& autreListe) 
{
    
        // Libérer la mémoire de la liste actuelle
        Cellule<T>* courant = pTete;
        Cellule<T>* suivant = nullptr;

        while (courant != nullptr) 
        {
            suivant = courant->suivante;
            delete courant;
            courant = suivant;
        }

        // Copier les éléments de l'autre liste
        courant = autreListe.pTete;
        Cellule<T>* dernier = nullptr;

        while (courant != nullptr) 
        {
            Cellule<T>* newCellule = new Cellule<T>;
            {
                newCellule->donnee=courant->donnee;
                newCellule->suivante=nullptr;
            }
            
            if (dernier == nullptr) 
            {
                pTete = newCellule;
            } 
            else 
            {
                dernier->suivante = newCellule;
            }

            dernier = newCellule;
            courant = courant->suivante;
        }

    return *this;
}
template class ArrayList<int>;
template class ArrayList<Couleur>;

