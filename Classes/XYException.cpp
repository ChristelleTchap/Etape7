#include "XYException.h"

using namespace std;

XYException::XYException():Exception()
{
	coordonnee=' ';
}

XYException::XYException(const char* message,char coord):Exception(message)
{
	coordonnee=coord;

}

XYException::XYException(const XYException& cp):Exception(cp.getMessage())
{
	coordonnee=cp.getCoordonnee();

}

XYException::~XYException()
{

}

char XYException::getCoordonnee()const
{
	return coordonnee;
}

void XYException::setCoordonnee(char coord)
{
	coordonnee=coord;
}
