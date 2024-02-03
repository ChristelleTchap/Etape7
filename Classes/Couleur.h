#ifndef COULEUR_H
#define COULEUR_H
#include "RGBException.h"

#include <iostream>


using namespace std;

class Couleur
{
	private:

		int rouge, vert,bleu;


	public:

		static const Couleur ROUGE;
		static const Couleur VERT;
		static const Couleur BLEU;
		static const Couleur BLANC;
		static const Couleur NOIR;


		Couleur();
		~Couleur();
		Couleur(int r, int v, int b);

		void setRouge(int);
		void setVert(int);
		void setBleu(int);

		int getRouge()const;
		int getVert()const;
		int getBleu()const;


	friend ostream& operator<<(ostream& s, const Couleur& imge);
    Couleur& operator=(const Couleur& autre);

		void Affiche()const;


};
#endif
