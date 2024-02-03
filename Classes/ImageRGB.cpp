#include "ImageRGB.h"
#include <iostream>
#include <string.h>

#include "MyQT.h"

using namespace std;

ImageRGB::ImageRGB():Image()
{
   #ifdef DEBUG
        cout << "Constructeur par defaut de ImageNG" << endl;
    #endif
    
     setBackground(Couleur::VERT); 
}

ImageRGB::ImageRGB(int id, const char* nom):Image(id,nom)
{
    #ifdef DEBUG
    cout << "Constructeur d'initialisation " << endl;
    #endif

       setBackground(Couleur::VERT); 

}
//------------------------------------------------------------
ImageRGB::ImageRGB(const char* nom):Image(-1,nom)
{
    
    setBackground(Couleur::VERT);
    importFromFile(nom);

}

ImageRGB::~ImageRGB()
{
    #ifdef DEBUG
    cout << "Destructeur" << endl;
    #endif
    
}

ImageRGB::ImageRGB(int id,const char* nom,const Dimension& dim):Image(id,nom,dim)
{
    #ifdef DEBUG
    cout<<"Constructeur d'initialisation complet de ImageNG"<<endl;
    #endif

    setBackground(Couleur::VERT);

};

ImageRGB::ImageRGB(const ImageRGB& autreImage):Image(autreImage.getId(),autreImage.getNom(),autreImage.getDimension())
{
    int i,j;

    #ifdef DEBUG
    cout<<"Constructeur de copie de ImageRGB"<<endl;
    #endif

/*-------------------------------------------------------------------------------------------*/
    for(i=0;i<dimension.getLargeur();i++)   // on fait la copie des pixels(boucles) d'une autre image vers l`objet de la classe actuelle 
    {
        for(j=0;j<dimension.getHauteur();j++)
        {
            setPixel(i,j,autreImage.getPixel(i,j));
        }

    }

};


/*------------------------------------------------------------------------------*/
//getteur pour pixel

Couleur ImageRGB::getPixel(int x,int y)const
{
    //verification de(x et y)>0 et inferieur a largeur et hauteur de dimension
    if(x<0 || x > dimension.getLargeur())
    {
         throw XYException("Largeur incorrecte",x);
    }
    else
    {
        if(y<0 || y>dimension.getHauteur())
        {
           throw XYException("Hauteur incorrecte",y);
        }
        else
        {
            return matrice[x][y];
        }
    }
 return Couleur();
}

//setteur pour pixel

void ImageRGB::setPixel(int x,int y,const Couleur& val)
{
    
    
    
        if(x<0 || x>dimension.getLargeur())
        {
            throw XYException("Largeur incorrecte",x);
        }
        else
        {
            if(y<0 || y>dimension.getHauteur())
            {
                 throw XYException("Hauteur incorrecte",y);
            }
            else
            {
                matrice[x][y]=val;
            }
        }
}


void ImageRGB::setBackground(const Couleur& val) // mets tout les pixels de l`image au niveau gris
{
    int i,j;

    
        for(i=0;i<dimension.getLargeur();i++) //La boucle continue tant que la valeur de i est < à la largeur de l'image obtenue 
                                                    //en appelant la méthode getLargeur() de l'objet retourné par getDimension()
        {
            for(j=0;j<dimension.getHauteur();j++)  // itère à travers les lignes de l'image en cours. Et renvoie la hauteur de l`image
            {
                matrice[i][j]=val;
            }
        }
    
}

// dessin dans une fenêtre graphique.

void ImageRGB::Dessine()const // appelle la méthode ViewImage() de la classe MyQT en lui passant *this en paramètre.
{
    MyQT::ViewImage(*this);
}

// Importation/Exportation d`une  image  vers des fichiers

void ImageRGB::importFromFile(const char* fichier)
{
    MyQT::ImportFromFile(*this, fichier);
}

void ImageRGB::exportToFile(const char* fichier, const char* format)const
{
    MyQT::ExportToFile(*this, fichier,format);
}

//-----------------------------------------------------------------------------------------------------
// calcul de la luminance



//-------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
      // surcharge de l`operateur '=' de la classe ImageNG

 ImageRGB& ImageRGB::operator=(const ImageRGB& autreImage) // La surcharge retourne une reference a l`objet
 {
    int i,j;
    setId(autreImage.getId());
    setNom(autreImage.getNom());

    //Copie de dimension
    setDimension(autreImage.getDimension());

    for(i=0;i<dimension.getLargeur();i++)
    {
        for(j=0;j<dimension.getHauteur();j++)
        {
            setPixel(i,j,autreImage.getPixel(i,j));
        }

    }
    return *this;

 }
 //---------------------------------------------------------------------------------------------
 ostream& operator<<(ostream& os, const ImageRGB& autreImage)
 {
    os <<" Identifiant: " << autreImage.getId();
    os <<" Nom: "<< autreImage.getNom();
    os <<" Dimension "<< autreImage.getDimension();
    
    return os;
 }

 //-----------------------------------------------------------------------------------------------------
 //   Opérateurs (ImageNG + int ) 
 
void ImageRGB::Affiche()const
{
    cout << "id=" << num << " nom=" << (pnom ? pnom : "N/A") << endl;
    dimension.Affiche();
    cout <<"Largeur"<<dimension.getLargeur()<<endl;
    cout <<"Hauteur"<<dimension.getHauteur()<<endl;
}
