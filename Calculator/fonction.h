
#ifndef FONCTION_H
#define FONCTION_H
#include <cmath>
#include <cstdlib>
#include <string>


long int calculator (std ::string operation, long int a , long int b)
{
  if (operation == "+")
    return a +b;
  if(operation == "-")
    return a - b;
  if (operation == "*")
    return a * b; 
  if ( operation == "/")
    return a /b;
}



#endif /* FONCTION_H */

