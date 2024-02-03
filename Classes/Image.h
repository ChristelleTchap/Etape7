#ifndef IMAGE_H
#define IMAGE_H
#include "Dimension.h"

#include <cstring>



class Image
{
protected:
	int num;
	char *pnom;
	Dimension dimension;
public:
	virtual void Affiche()const =0;  // virtuelle pure 
	virtual void Dessine()const =0;
	virtual void exportToFile(const char* fichier,const char* format)const =0;

	Image();	//Constructeur par defaut
	virtual ~Image(); //Destructeur par defaut

	//Image(); //constructeur par defaut
		Image(int id,const char* nom); //d'initialisation 
		
		Image(int id,const char* nom,const Dimension& dim); //d'initialisation complet de dimension

		Image(const char* nom);

	//Image(const char *nom); //new constructeur 

	void setId(int id);
		 void setNom(const char* nom);

		 void setDimension(const Dimension& dim);
		 Dimension getDimension()const;
		 
		 int getId() const;
		 const char* getNom() const;

};

 
#endif


