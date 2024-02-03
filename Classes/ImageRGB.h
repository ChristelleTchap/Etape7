#ifndef IMAGERGB_H			
#define IMAGERGB_H

#include "Dimension.h"

#include "Image.h"
#include <iostream>
#include <stdlib.h>

#include "Couleur.h"

using namespace std;

class MyQT;

class ImageRGB:public Image
{
	private:
		
		static const int L_MAX=400;
		static const int H_MAX=400;

		Couleur matrice[L_MAX][H_MAX];


	public: 
		ImageRGB(); //constructeur par defaut
		ImageRGB(int id,const char* nom); //d'initialisation 
		ImageRGB(const ImageRGB& autreImage);// constructeur par copie
		ImageRGB(int id,const char* nom,const Dimension& dim); //d'initialisation compple de dimension

		ImageRGB(const char* nom);
//-----------------------------------------------------------
		

		~ImageRGB() override; 
		
//--------------------------------------------------------------

		void Affiche()const override;

//------------------------------------------------------------------
	Couleur getPixel(int x,int y)const;
	void setPixel(int x,int y,const Couleur& val);
	void setBackground(const Couleur& val);
	void Dessine() const override;
	void importFromFile(const char* fichier);
	void exportToFile(const char* fichier, const char* format)const override;

//-----------------------------------------------------------------------------------
	friend ostream& operator<<(ostream& os, const ImageRGB& autreImage);
	ImageRGB& operator=(const ImageRGB& autreImage);
	
	
//---------------------------------------------------------------------
};
#endif


