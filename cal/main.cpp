#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

int calculator (string operation, int a, int b);

int
main ()
{
  int a, b;
  string operation;

  cout << "Entrez un chiffre ; ";
  cin >> a;
  cout << "Entre un autre chiffre";
  cin >> b;
  cin.ignore ();

  cout << "Entrez une operation (+,-,*,/)";
  getline (cin, operation);

  cout << "Résultat : " << calculator (operation, a, b) << endl;

  return 0;
}

int
claculator (string operation, int a, int b)
{
  if (operation == "+")
    return a + b;
  if (operation == "-")
    return a - b;
  if (operation == "*")
    return a * b;
  if (operation == "/")
    return a / b;
  return 0;
}
