#include "ImageNG.h"
#include <iostream>
#include <string.h>

#include "MyQT.h"

using namespace std;

ImageNG::ImageNG():Image()
{
   #ifdef DEBUG
        cout << "Constructeur par defaut de ImageNG" << endl;
    #endif
    
   // num= 1;
   //  // nom = NULL;
   //  pnom = new char[20];
   //  strcpy(pnom, "ImageNG sans nom");
     setBackground(1); 
}

ImageNG::ImageNG(int id, const char* nom):Image(id,nom)
{
    #ifdef DEBUG
    cout << "Constructeur d'initialisation " << endl;
    #endif
    
    //num = id;
       setBackground(1); 

}
//------------------------------------------------------------
ImageNG::ImageNG(const char* nom):Image(-1,nom)
{
    // num =2024;
    // if (nom != NULL) 
    // {
    //     pnom = new char[strlen(nom) + 1];
    //     strcpy(pnom, nom);
    // }
    // else 
    // {
    //     pnom = NULL;
    // }
    setBackground(1);
    importFromFile(nom);

}

ImageNG::~ImageNG()
{
    #ifdef DEBUG
    cout << "Destructeur" << endl;
    #endif
    // if (pnom != NULL) 
    // {
    //     delete[] pnom;
    // }
}

ImageNG::ImageNG(int id,const char* nom,const Dimension& dim):Image(id,nom,dim)
{
    #ifdef DEBUG
    cout<<"Constructeur d'initialisation complet de ImageNG"<<endl;
    #endif

    // setId(id);
    // pnom=NULL;

    // setNom(nom);

    // dimension.setLargeur(dim.getLargeur());
    // dimension.setHauteur(dim.getHauteur());
    setBackground(0);

};

ImageNG::ImageNG(const ImageNG& autreImage):Image(autreImage.getId(),autreImage.getNom(),autreImage.getDimension())
{
    int i,j;

    #ifdef DEBUG
    cout<<"Constructeur de copie de ImageNG"<<endl;
    #endif

    // pnom=NULL;
    // setNom(autreImage.pnom);

    // setId(autreImage.num);

    // dimension.setLargeur(autreImage.dimension.getLargeur());
    // dimension.setHauteur(autreImage.dimension.getHauteur());

/*-------------------------------------------------------------------------------------------*/
    for(i=0;i<dimension.getLargeur();i++)   // on fait la copie des pixels(boucles) d'une autre image vers l`objet de la classe actuelle 
    {
        for(j=0;j<dimension.getHauteur();j++)
        {
            setPixel(i,j,autreImage.getPixel(i,j));
        }

    }

};

// //  get et set pour id
//     int ImageNG::getId() const
//     {
//         return num;
//     }
    
//     void ImageNG:: setId(int id) 
//     {
//         num = id;
//     }

// // get et set pour nom
//     const char*ImageNG:: getNom() const 
//     {
//         return pnom;
//     }
    
    // void ImageNG::setNom(const char* nom) 
    // {
    //     if(pnom!=NULL)
    //         delete[] pnom;
    //     pnom = new char[strlen(nom) + 1];
    //     strcpy(pnom, nom);
    // }   

    // void ImageNG::setDimension(const Dimension& dim)
    // {
    //     //dimension=dim

    // dimension.setLargeur(dim.getLargeur());

    // dimension.setHauteur(dim.getHauteur());
    // }

// Dimension ImageNG::getDimension()const
// {
//     return dimension;

// }


/*------------------------------------------------------------------------------*/
//getteur pour pixel

int ImageNG::getPixel(int x,int y)const 
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
 return -1;
}

//setteur pour pixel

void ImageNG::setPixel(int x,int y,int val)
{
    if(val>255 || val<0)
    {
        throw RGBException("couleur incorrecte",val);
    }
    else
    {
        if(x<0 || x>dimension.getLargeur())
        {
           throw XYException("Largeur incorrecte",y);
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
}


void ImageNG::setBackground(int val) // mets tout les pixels de l`image au niveau gris
{
    int i,j;

    if(val<0 || val>255) 
    {
        throw RGBException("La couleur incorrect",val);
    }
    else
    {
        for(i=0;i<dimension.getLargeur();i++) //La boucle continue tant que la valeur de i est < à la largeur de l'image obtenue 
                                                    //en appelant la méthode getLargeur() de l'objet retourné par getDimension()
        {
            for(j=0;j<dimension.getHauteur();j++)  // itère à travers les lignes de l'image en cours. Et renvoie la hauteur de l`image
            {
                matrice[i][j]=val;
            }
        }
    }
}

// dessin dans une fenêtre graphique.

void ImageNG::Dessine()const // appelle la méthode ViewImage() de la classe MyQT en lui passant *this en paramètre.
{
    MyQT::ViewImage(*this);
}

// Importation/Exportation d`une  image  vers des fichiers

void ImageNG::importFromFile(const char* fichier)
{
    MyQT::ImportFromFile(*this, fichier);
}

void ImageNG::exportToFile(const char* fichier, const char* format)const
{
    MyQT::ExportToFile(*this, fichier,format);
}

//-----------------------------------------------------------------------------------------------------
// calcul de la luminance

int ImageNG::getLuminance()const
{
    int som=0,x,y;
    //calcul de la valeur moyenne
    for(x=0;x<dimension.getLargeur();x++)
    {
        for(y=0;y<dimension.getHauteur();y++)
        {
            som=som+getPixel(x,y);

        }
        
    }
     return som / (dimension.getLargeur()*dimension.getHauteur()); //valeur moy de tout les niveau gris
}

//--------------------------------------------------------------------------------------------------------
// retourne le minimum de niveau gris

int ImageNG::getMinimum()const 
{
    int mini,x,y,nivG;
    if(dimension.getLargeur()<= 0 || dimension.getHauteur()<= 0)
    {
        return 0;
    }
     mini = getPixel(0,0);
     for(x=0;x<dimension.getLargeur();x++) // verifie les dimensionsde l'image
     {
        for(y=0;y<dimension.getHauteur();y++)
        {
            nivG=getPixel(x,y);

            if(nivG<mini) 
            {
                mini=nivG; //stocke la valeur minimale de niveau gris
            }

        }

     }
     return mini; // stocke la valeur minimal
}

//-------------------------------------------------------------------------------------------------------
int ImageNG::getMaximum()const
{
    int max,x,y,nivG;
    if(dimension.getLargeur()<= 0 || dimension.getHauteur()<= 0)
    {
        return 0;
    }

     max = getPixel(0,0);
     for(x=0;x<dimension.getLargeur();x++) // verifie les dimensionsde l'image
     {
        for(y=0;y<dimension.getHauteur();y++)
        {
            nivG=getPixel(x,y);

            if(nivG>max) 
            {
                max=nivG; //stocke la valeur ,max de niveau gris
            }

        }

     }
     return max; // stocke la valeur minimal

}

//----------------------------------------------------------------------------------------------------------
float ImageNG::getContraste()const
{
    int min = getMinimum();
    int max = getMaximum();
    float resultat;

    if((min+max) == 0)
    {
        return 0.0;
    }
    resultat= (max - min);

    return resultat/(max + min);
    // on fait un casting pour calculer le contraste.
}

//-------------------------------------------------------------------------------------------------------
      // surcharge de l`operateur '=' de la classe ImageNG

 ImageNG& ImageNG::operator=(const ImageNG& autreImage) // La surcharge retourne une reference a l`objet
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
 ostream& operator<<(ostream& os, const ImageNG& autreImage)
 {
    os <<" Identifiant: " << autreImage.getId();
    os <<" Nom: "<< autreImage.getNom();
    os <<" Dimension "<< autreImage.getDimension();
    os <<" Luminance "<< autreImage.getLuminance();
    os <<" Contraste "<< autreImage.getLuminance();
    return os;
 }

 //-----------------------------------------------------------------------------------------------------
 //   Opérateurs (ImageNG + int ) 
 ImageNG ImageNG::operator+(const int val)
 {
    ImageNG newImg(*this);// la copie qu'on modifie
    int i,j,som=0;
    
    for(i=0;i<dimension.getLargeur();i++) // dimension est la dimension de l'image courant(this)
    {
        for(j=0;j<dimension.getHauteur();j++)
        {
            som= getPixel(i,j)+val;
            if(som>255)
            {
                newImg.setPixel(i,j,255);
            }
            else
            {
               newImg.setPixel(i,j,som); 
            }
        }

    }
    return newImg;


 }

 //---------------------------------------------------
 // operateur (int + ImageNG)
ImageNG operator+( int val,const ImageNG& img)
{
    ImageNG newImg2(img);//copie la 1ere image
    int i,j,som=0;
    
    for(i=0;i<img.getDimension().getLargeur();i++) 
    {
        for(j=0;j<img.getDimension().getLargeur();j++)
        {
            som= img.getPixel(i,j)+val;
            if(som>255)
            {
                newImg2.setPixel(i,j,255);
            }
            else
            {
               newImg2.setPixel(i,j,som); 
            }
        }

    }
    return newImg2;


 }

 //   Opérateurs (ImageNG  int ) 
 ImageNG ImageNG::operator-( int val)
 {
    ImageNG newImg(*this);// la copie qu'on modifie
    int i,j,som=0;
    
    for(i=0;i<dimension.getLargeur();i++) // dimension est la dimension de l'image courant(this)
    {
        for(j=0;j<dimension.getHauteur();j++)
        {
            som= getPixel(i,j)-val;
            if(som<0)
            {
                newImg.setPixel(i,j,0);
            }
            else
            {
               newImg.setPixel(i,j,som); 
            }
        }

    }
    return newImg;


 }

 //---------------------------------------------------
 // operateur (int - ImageNG)
ImageNG operator-( int val,const ImageNG& img)
{
    ImageNG newImg2(img);//copie la 1ere image
    int i,j,som=0;
    
    for(i=0;i<img.getDimension().getLargeur();i++) 
    {
        for(j=0;j<img.getDimension().getLargeur();j++)
        {
            som= img.getPixel(i,j)-val;
            if(som<0)
            {
                newImg2.setPixel(i,j,0);
            }
            else
            {
               newImg2.setPixel(i,j,som); 
            }
        }

    }
    return newImg2;


 }
  

 //--------------------------------------------------------------------------------------------------------
   // Surcharge des operateurs pres ++ de la classe ImageNG
ImageNG ImageNG::operator++(){
    (*this)=(*this)+20;
    return (*this);
}

//--------------------------------------------------------------------------------------------------------
// post ++
ImageNG ImageNG:: operator++(int){
    ImageNG temp(*this); //copie l`ancienne valeur
    (*this)=(*this)+20;
    return temp;
}

 //--------------------------------------------------------------------------------------------------------
 // Surcharge des operateurs -- de la classe ImageNG
ImageNG ImageNG::operator--(){
    (*this)=(*this)-20;
    return (*this);
}

//--------------------------------------------------------------------------------------------------------
// post ++
ImageNG ImageNG:: operator--(int){
    ImageNG temp(*this); //copie l`ancienne valeur
    (*this)=(*this)-20;
    return temp;
}

 //--------------------------------------------------------------------------------------------------------
 // Surcharge des operateurs (ImageNG - ImageNG) de la classe ImageNG
    ImageNG ImageNG::operator-(const ImageNG& imge) 
    {
        int i,j,som=0;
        
        //ImageNG imge(*this);

        ImageNG imgtemp(*this);

        cout<<"imge"<<imge.getDimension()<< endl;
        

        cout<<"imgtemp"<<imgtemp.getDimension()<<endl; 
        
        if(imgtemp.getDimension()==imge.getDimension())
        {
            for(i=0;i<dimension.getLargeur();i++) // dimension est la dimension de l'image courant(this)
            {
                for(j=0;j<dimension.getHauteur();j++)
                {
                    som= imgtemp.getPixel(i,j)-imge.getPixel(i,j);
                    if(som<0)
                    {
                        imgtemp.setPixel(i,j,0);
                    }
                    else
                    {
                       imgtemp.setPixel(i,j,som); 
                    }
                }

             }
        }
        else
        {
            cout<<"operateur de soustraction, dimensions différentes"<<endl;
           throw XYException("Exception : operator- dimensions différentes",'h'); 
        }
        return imgtemp;
    }

 //--------------------------------------------------------------------------------------------------------
 //  Surcharge des opérateurs de comparaison de deux images pixel à pixel : (< >)

 //--------------------------------------------------------------------------------------------------------
//Surcharge des opérateurs de comparaison de deux images pixel à pixel(==)
    // int ImageNG::operator==(const ImageNG& imge2)
    // {
    //     int i=0,j=0,tr=0;
    //     if(imge2.getDimension()==getDimension())
    //     {
    //         tr=1;   
    //         while(i<getDimension().getLargeur()&&tr==1)
    //         {
    //             while(j<getDimension().getHauteur()&&tr==1)
    //             {
    //                 if(getPixel(i,j)!=imge2.getPixel(i,j))
    //                 {
    //                     tr=0;
    //                 }
    //             }
    //         }
    //     }
    //     return tr;

    // }
    //-----------------------------------------------------------------------------------
    bool ImageNG::operator==(const ImageNG& imge2)
     {
        int i,j;

        if(this->getDimension()==imge2.getDimension())
        {

            // Comparaison des pixels
            for (i = 0; i < dimension.getLargeur(); i++) 
            {
                for (j = 0; j < dimension.getHauteur(); j++) 
                {
                    if (matrice[i][j] != imge2.matrice[i][j]) 
                    {
                        return false;  // Si un pixel de l'image1 n'est pas strictement inférieur à celui de l'image2, retourne faux
                    }
                }
            }
            return true;  // Tous les pixels sont strictement inférieurs
           }

        else
        {
            throw XYException("ImageNG pas correct",'h');
        }

    }

 //----------------------------------------------------------------------------------------------
 //Surcharge des opérateurs de comparaison de deux images pixel à pixel(<)
  bool ImageNG::operator<(const ImageNG& imge2)

  {
    int i,j;

        if(this->getDimension()==imge2.getDimension())
        {
    
            for (i = 0; i < dimension.getLargeur(); i++) 
            {
                for (j = 0; j < dimension.getHauteur(); j++) 
                {
                    if (matrice[i][j] >= imge2.matrice[i][j]) 
                    {
                        return false;  // Si un pixel de l'image1 n'est pas strictement inférieur à celui de l'image2, retourne faux
                    }
                }
            }
            return true;  // Tous les pixels sont strictement inférieurs
       }
       else
       {
        throw XYException("Image pas correct",'h');
       }
    }
  


//----------------------------------------------------------------------------------------------
 //Surcharge des opérateurs de comparaison de deux images pixel à pixel(>)
bool ImageNG::operator>(const ImageNG& imge2) 
{
    int i,j;

    if(this->getDimension()==imge2.getDimension())
    {
        for (i = 0; i < dimension.getLargeur(); i++) 
        {
            for (j = 0; j < dimension.getHauteur(); j++) 
            {
                if (matrice[i][j] <= imge2.matrice[i][j]) 
                {
                    return false; 
                }
            }
        }
        return true;  
    }
    else
       {
        throw XYException("Image pas correct",'i');
       }



}
    
   



 //---------------------------------------------------------------------------------------------------------

void ImageNG::Affiche()const
{
    cout << "id=" << num << " nom=" << (pnom ? pnom : "N/A") << endl;
    dimension.Affiche();
    cout <<"Largeur"<<dimension.getLargeur()<<endl;
    cout <<"Hauteur"<<dimension.getHauteur()<<endl;
}
