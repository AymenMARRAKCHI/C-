#include <iostream>
#include <cmath>
#include <string>

#include "fonction.h"

using namespace std;



int main()
{
  long int a,b;
  string operation;
  
  cout << "Veullez entre un chiffre :  ";
  cin >> a;
  cout << "Veuillez entrez un autre chiffre : ";
  cin >> b;
  cout << "Entre une operation ( +,-,*,/) : ";
  cin >> operation;
  
  cout << " resultat : " << calculator(operation,a,b) << endl;
  cout << "Fin du programme ! "<< endl;
  return 0 ;
}

