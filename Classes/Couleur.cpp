#include "Couleur.h"



Couleur:: Couleur()
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut de ImageRGB"<<endl;
	#endif

	setRouge(255);
	setVert(255);
	setBleu(255);

}


Couleur::~Couleur()
{
	#ifdef DEBUG
	cout<<"Destructeur par defaut de la classe Couleur"<<endl;
	#endif
}



Couleur:: Couleur(int r,int v,int b)
{
	#ifdef DEBUG
	cout<<"Constructeur d'initialisation  de la classe Couleur"<<endl;
	#endif

	setRouge(r);
	setVert(v);
	setBleu(b);
}

const Couleur Couleur::ROUGE(255,0,0);
const Couleur Couleur::VERT(0,255,0);
const Couleur Couleur::BLEU(0,0,255);
const Couleur Couleur::BLANC(255,255,255);
const Couleur Couleur::NOIR(0,0,0);

void Couleur::setRouge(int r)
{
	if(r <=255 && r >=0)
	{
		rouge =r;
	}
	else
	{
		throw RGBException("La couleur doit etre compris entre 0 et 255",r);
	}
	
}

void Couleur::setVert(int v)
{
	if(v <=255 && v >=0)
	{
		vert =v;
	}
	else
	{
		throw RGBException("La couleur doit etre compris entre 0 et 255",v);
	}
	
}

void Couleur::setBleu(int b)
{
	if(b <=255 && b >=0)
	{
		bleu =b;
	}
	else
	{
		throw RGBException("La couleur doit etre compris entre 0 et 255",b);
	}
	
}

int Couleur::getRouge()const
{
	return rouge;
}

int Couleur::getVert()const
{
	return vert;
}

int Couleur::getBleu()const
{
	return bleu;
}



ostream& operator<<(ostream& s, const Couleur& c)
{
	s << "Rouge : "<<  c.rouge << "	vert : "<<  c.vert <<"	Bleu : "<<  c.bleu<<endl;

	return s;
}

void Couleur::Affiche()const
{
	cout << "Rouge : " <<getRouge() << "	vert : "	<<getVert() <<"	Bleu : "<<getBleu()<<endl<<endl;
}

Couleur& Couleur::operator=(const Couleur& autre)
{
	this->setRouge(autre.getRouge());
	this->setBleu(autre.getBleu());
	this->setVert(autre.getVert());
	return *this;

}