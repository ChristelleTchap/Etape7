#ifndef IMAGENG_H			
#define IMAGENG_H

#include "Dimension.h"
#include "RGBException.h"


#include "Image.h"
#include <iostream>
#include <stdlib.h>

class MyQT;
using namespace std;

class ImageNG:public Image
{
	private:
		

		static const int L_MAX=400;
		static const int H_MAX=400;

		int matrice[L_MAX][H_MAX];


	public: 
		ImageNG(); //constructeur par defaut
		ImageNG(int id,const char* nom); //d'initialisation 
		ImageNG(const ImageNG& autreImage);// constructeur par copie
		ImageNG(int id,const char* nom,const Dimension& dim); //d'initialisation compple de dimension

		ImageNG(const char* nom);
//-----------------------------------------------------------
		//ImageNG(const char *nom); 
//----------------------------------------------------------------


		~ImageNG(); //destructeur
		
//--------------------------------------------------------------
		 
//-------------------------------------------------------------
        int getLuminance() const;
        int getMinimum() const;
        int getMaximum() const;
        float getContraste() const;


//------------------------------------------------------------

		void Affiche()const override;

//------------------------------------------------------------------
	int getPixel(int x,int y)const ;
	void setPixel(int x,int y,int val);
	void setBackground(int val);
	void Dessine() const override;
	void importFromFile(const char* fichier);
	void exportToFile(const char* fichier, const char* format)const override;

//-----------------------------------------------------------------------------------
	friend ostream& operator<<(ostream& os, const ImageNG& autreImage);
	ImageNG& operator=(const ImageNG& autreImage);
	ImageNG operator+(const int);
	friend ImageNG operator+(const int,const ImageNG&);
	ImageNG operator-(const int);
	friend ImageNG operator-(const int,const ImageNG&);
	ImageNG operator++();
	ImageNG operator++(int);
	ImageNG operator--();
	ImageNG operator--(int);
	ImageNG operator-(const ImageNG&);
        bool operator==(const ImageNG& imge2) ;
         bool operator<(const ImageNG& imge2) ;
        bool operator>(const ImageNG& imge2) ;
	
//---------------------------------------------------------------------
};
#endif


