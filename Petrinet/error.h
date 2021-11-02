#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class TypeMismatch : public exception
{
    string mess;

public:
    TypeMismatch()
    {
        mess = "TypeMismatch";
    }
    const char *what() const throw()
    {
        return mess.c_str();
    }
};
class InvalidDeclaration : public exception
{
    string mess;

public:
    InvalidDeclaration()
    {
        mess = "Undeclared State or Transition not found ";
    }
    const char *what() const throw()
    {
        return mess.c_str();
    }
};

#endif