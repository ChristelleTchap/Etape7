#ifndef IMAGEB_H			
#define IMAGEB_H

#include "Dimension.h"


#include "Image.h"
#include <iostream>
#include <stdlib.h>

#include "Couleur.h"

class MyQT;

using namespace std;

class ImageB:public Image
{
	private:
		

		static const int L_MAX=500;
		static const int H_MAX=500;

		bool matrice[L_MAX][H_MAX];


	public: 
		ImageB(); //constructeur par defaut
		ImageB(int id,const char* nom); //d'initialisation 
		ImageB(const ImageB& autreImage);// constructeur par copie
		ImageB(int id,const char* nom,const Dimension& dim); //d'initialisation compple de dimension

		static Couleur couleurTrue;
		static Couleur couleurFalse;

//-----------------------------------------------------------
		

		~ImageB(); //destructeur
		


		void Affiche()const override;

//------------------------------------------------------------------
	bool getPixel(int x,int y)const ;
	void setPixel(int x,int y,bool val);
	void setBackground(bool val);
	void Dessine() const override;
	
	void exportToFile(const char* fichier, const char* format)const override;

//-----------------------------------------------------------------------------------
	friend ostream& operator<<(ostream& os, const ImageB& autreImage);
	ImageB& operator=(const ImageB& autreImage);
	
	
//---------------------------------------------------------------------
};
#endif


