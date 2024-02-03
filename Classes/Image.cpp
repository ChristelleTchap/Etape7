#include "Image.h"

Image :: Image()
{
	#ifdef DEBUG
	cout<<"Constructeur par defaut de Image"<<endl;
	#endif

	setId(-1);  // il n`y a pas de valeur dans id
	pnom=NULL;
	setNom("Image");


}

Image ::~Image()
{
	#ifdef DEBUG
	cout<<"Destructeur par defaut de Image"<<endl;
	#endif

	if(pnom!=NULL);
		free(pnom);

}

Image::Image(int id,const char* nom) //constructeur d'initialisation
{
	 #ifdef DEBUG
    cout << "Constructeur d'initialisation " << endl;
    #endif
    
    setId(id);   
    pnom=NULL;
    setNom(nom);
}


Image::Image(int id,const char* nom,const Dimension& dim)
{
	#ifdef DEBUG
    cout<<"Constructeur d'initialisation complet de Image"<<endl;
    #endif

    setId(id);
    pnom=NULL;

    setNom(nom);

    dimension.setLargeur(dim.getLargeur());
    dimension.setHauteur(dim.getHauteur());
 
}


/*Image::Image(const Image& autreImage)
{
	
	#ifdef DEBUG
    cout<<"Constructeur de copie de Image"<<endl;
    #endif

    pnom=NULL;
    setNom(autreImage.pnom);

    setId(autreImage.num);

    dimension.setLargeur(autreImage.dimension.getLargeur());
    dimension.setHauteur(autreImage.dimension.getHauteur());
}
*/
//----------------------------------------------------------------------------------------------

Image:: Image(const char *nom)
{
	#ifdef DEBUG
	cout<<"Nouveau Constructeur pour les images"<<endl;
	#endif

	setNom(nom);
	setId(0);

}

void Image:: setNom(const char* nom)
{

	if (nom != NULL) 
    {
        pnom = new char[strlen(nom) + 1];
        strcpy(pnom, nom);
    }
    else 
    {
        pnom = NULL;
    }
}

void Image::setId(int id)
{
	num=id;

}

void Image::setDimension(const Dimension& dim)
{

	dimension.setLargeur(dim.getLargeur());

	dimension.setHauteur(dim.getHauteur());
}

int Image::getId()const
{
	return num;

}

const char* Image::getNom()const
{
	return pnom;

}

Dimension Image::getDimension()const
{
	return dimension;

}

