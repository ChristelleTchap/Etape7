#include "Exception.h"

using namespace std;

Exception::Exception()
{
	#ifndef DEBUG
	cout<<"Constructeur par defaut de la classe Exception"<<endl;
	#endif
	setMessage("Exception sans nom");
}

Exception::Exception(std::string message)
{
	#ifdef DEBUG
	cout<<"Constructeur d'initialisation  de la classe Exception"<<endl;
	#endif
	setMessage(message);
}

Exception::~Exception()
{
	#ifdef DEBUG
	cout<<"Destructeur de la classe Exception"<<endl;
	#endif
}

std::string Exception::getMessage()const
{
	return message;
}

void Exception::setMessage(std::string m)
{
	message=m;
}