
#ifndef DIMENSION_H
#define DIMENSION_H

#include "XYException.h"

#include <iostream>
using namespace std;


class Dimension 
{
private:
    int largeur;
    int hauteur;

public:
    Dimension(); 
    Dimension(int l, int h) ;
    Dimension(const Dimension& img); 

    ~Dimension();

    void setLargeur(int l);

    void setHauteur(int h);

    int getLargeur()const;
    
    int getHauteur()const;

    void Affiche()const;

    static const Dimension VGA;
    static const Dimension HD;
    static const Dimension FULL_HD;
//-----------------------------------------------------------------------------

friend ostream& operator<<(ostream& os, const Dimension& autreImage);
friend istream& operator>>(istream& is, Dimension& autreImage);

 int operator==(const Dimension dim);
 int operator!=(const Dimension dim);

};

#endif



