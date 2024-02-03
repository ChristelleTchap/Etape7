#ifndef XYEXCEPTION_H
#define XYEXCEPTION_H

#include "Exception.h"

class XYException:public Exception 
{

   private:
   	char coordonnee;

   public:
   	XYException();
   	XYException(const char* message,char coord);
   	XYException(const XYException& cp);
   	~XYException();

   	char getCoordonnee()const;
   	void setCoordonnee(char coordonne);

};
#endif