#include "ImageB.h"
#include <iostream>
#include <string.h>


#include "MyQT.h"

using namespace std;

 Couleur ImageB::couleurTrue(255,255,255);

 Couleur ImageB::couleurFalse(0,0,0);

ImageB::ImageB():Image()
{
   #ifdef DEBUG
        cout << "Constructeur par defaut de ImageNG" << endl;
    #endif
    
     setBackground(false); 
}

ImageB::ImageB(int id, const char* nom):Image(id,nom)
{
    #ifdef DEBUG
    cout << "Constructeur d'initialisation " << endl;
    #endif

       setBackground(false); 

}
//------------------------------------------------------------


ImageB::~ImageB()
{
    #ifdef DEBUG
    cout << "Destructeur" << endl;
    #endif
    
}

ImageB::ImageB(int id,const char* nom,const Dimension& dim):Image(id,nom,dim)
{
    #ifdef DEBUG
    cout<<"Constructeur d'initialisation complet de ImageNG"<<endl;
    #endif

    setBackground(false);

};

ImageB::ImageB(const ImageB& autreImage):Image(autreImage.getId(),autreImage.getNom(),autreImage.getDimension())
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

bool ImageB::getPixel(int x,int y)const 
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
 return 0 ;
}

//setteur pour pixel

void ImageB::setPixel(int x,int y,bool val)
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


void ImageB::setBackground(bool val) // mets tout les pixels de l`image au niveau gris
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

void ImageB::Dessine()const // appelle la méthode ViewImage() de la classe MyQT en lui passant *this en paramètre.
{
    MyQT::ViewImage(*this);
}

// Importation/Exportation d`une  image  vers des fichiers


void ImageB::exportToFile(const char* fichier, const char* format)const
{
    MyQT::ExportToFile(*this, fichier,format);
}

//-----------------------------------------------------------------------------------------------------
// calcul de la luminance



//-------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
      // surcharge de l`operateur '=' de la classe ImageNG

 ImageB& ImageB::operator=(const ImageB& autreImage) // La surcharge retourne une reference a l`objet
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
 ostream& operator<<(ostream& os, const ImageB& autreImage)
 {
    os <<" Identifiant: " << autreImage.getId();
    os <<" Nom: "<< autreImage.getNom();
    os <<" Dimension "<< autreImage.getDimension();
    
    return os;
 }

 //-----------------------------------------------------------------------------------------------------
 //   Opérateurs (ImageNG + int ) 
 
void ImageB::Affiche()const
{
    cout << "id=" << num << " nom=" << (pnom ? pnom : "N/A") << endl;
    dimension.Affiche();
    cout <<"Largeur"<<dimension.getLargeur()<<endl;
    cout <<"Hauteur"<<dimension.getHauteur()<<endl;
}
