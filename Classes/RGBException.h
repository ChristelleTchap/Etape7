#ifndef RGBEXCEPTION_H
#define RGBEXCEPTION_H

#include "Exception.h"  


class RGBException : public Exception 
{
    private:

        int valeur;  

     public:
        RGBException();
        RGBException(const char* message,int valeur);
        ~RGBException();

        int getValeur()const ;
        void setValeur(int val);

};
#endif