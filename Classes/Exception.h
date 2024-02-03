#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string.h>
#include <string>


class Exception
{
 private:

     std:: string message;

 public:
     Exception();

     Exception(std::string message);
     
     virtual ~Exception();

     void setMessage(std::string m);
     std::string getMessage()const;

};

#endif