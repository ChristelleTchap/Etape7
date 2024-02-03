#include <iostream>
#include <string.h>
#include <iostream>

#include "Dimension.h"


using namespace std;

//--------------------------------------------------------------------------------------------------
Dimension::Dimension()
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut de la Classe Dimension"<<endl;
	#endif
	setLargeur(400);
	setHauteur(300);
}

Dimension::Dimension(int l, int h)
{
	#ifdef DEBUG
	cout<<"Constructeur d'initialisation de la classe Dimension"<<endl;
	#endif

	setLargeur(l);
	setHauteur(h);
}

Dimension::Dimension(const Dimension& img)
{
	#ifdef DEBUG
	cout<<"Constructeur de copie de la Classe Dimension"<<endl;
	#endif

	setLargeur(img.getLargeur());
	setHauteur(img.getHauteur());
}

Dimension::~Dimension()
{
	#ifdef DEBUG
	cout<<"Destructeur de la Classe Dimension"<<endl;
	#endif
}


void Dimension::setLargeur(int l)
{
	if(l<0)
	{
		throw XYException("Dimension pas correct",'l');
	}
	else
	{
		largeur=l;
	}
}

void Dimension::setHauteur(int h)
{
	if(h<0)
	{
		throw XYException("Dimension pas correct",'h');
	}
	else
	{
		hauteur=h;
	}
}

int Dimension:: getLargeur()const
{ 
	return largeur;
}

int Dimension:: getHauteur()const
{ 
	return hauteur;
}

void Dimension::Affiche()const
{
    cout << "largeur=" << largeur<< endl;
    cout << "hauteur=" << hauteur<< endl;
}

// constantes statiques 
const Dimension Dimension::VGA(640, 480);
const Dimension Dimension::HD(1280, 720);
const Dimension Dimension::FULL_HD(1920, 1080);


//-------------------------------------------------------------------------------------------------------
    //Surcharge des operateurs << de Dimension
ostream& operator<<(ostream& os, const Dimension& autreImage)
{
	os << " Largeur " << autreImage.getLargeur();
	os << " Hauteur " << autreImage.getHauteur();
	return os;
}
 

 //-------------------------------------------------------------------------------------------------------
 // Surcharge des operateurs >> de Dimension

 istream& operator>>(istream& is, Dimension& autreImage)
 {
 	int lar,haut;

 	cout << "Largeur :"  <<endl;
 	is >> lar;
 	autreImage.setLargeur(lar);

 	cout << "Hauteur :" <<endl;
 	is >> haut;
 	autreImage.setHauteur(haut);
 	return is;

 }
 

//--------------------------------------------------------------------------------------------------------
 // Surcharge des operateurs == de la classe Dimension
  int Dimension::operator==(const Dimension dim)
  {
  	if(dim.getLargeur()== getLargeur()&& dim.getHauteur()==getHauteur())
  	{
  		return 1;
  	}
  	return 0;

  }


 //--------------------------------------------------------------------------------------------------------
// Surcharge des operateurs != de la classe Dimension
  int Dimension::operator!=(const Dimension dim)
  {
  	if(dim.getLargeur()!= getLargeur()||dim.getHauteur()!=getHauteur())
  	{
  		return 1;
  	}
  	return 0;

  }



//--------------------------------------------------------------------------------------------------