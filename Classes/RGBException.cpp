#include "RGBException.h"

RGBException::RGBException():Exception()
{
	valeur=1;
}

RGBException::RGBException(const char* message,int val):Exception(message)
{
	valeur=val;
}

RGBException::~RGBException()
{

}

int RGBException::getValeur()const 
{
	return valeur;
}

void RGBException::setValeur(int val)
{
	valeur=val;
}