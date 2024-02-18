#include <iostream>
#include <string>

using namespace std;

int max(int a, int b);

int main() 
{
    int a;
    int b; 

    cout << "Entrez un premier chiffre: ";
    cin >> a;

    cout << "Entrez un deuxième chiffre: ";
    cin >> b;

    // Appel de la fonction max et stockage du résultat dans une variable
    int resultatMax = max(a, b);

    cout << "La valeur max c'est : " << resultatMax << endl;

    return 0;
}

int max(int a, int b){
    int m;
    if (a > b)
        m = a;
    else
        m = b;
    return m;
}
