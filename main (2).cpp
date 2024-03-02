#include <iostream>
#include <cmath>

using namespace std;

bool validationPositif(int a)
{
    if (a < 0)
        return false;
    else
        return true;
}

bool validationNegatif(int a)
{
    if (a > 0)
        return false;
    else
        return true;
}

int main()
{
    int choice;
    int a;
    cout << "Bonjour ! Voulez-vous vérifier si votre chiffre est positif ou négatif ?" << endl;
    cout << "1. Positif\n2. Négatif" << endl;
    cin >> choice;
    
    if (choice == 1 || choice == 2)
    {
        cout << "Veuillez entrer un chiffre : ";
        cin >> a;
        
        if (choice == 1)
        {
            cout << "Le chiffre est positif : " <<  validationPositif(a) << endl;
        }
        else if (choice == 2)
        {
            cout << "Le chiffre est négatif : " << boolalpha << validationNegatif(a) << endl;
        }
    }
    else
    {
        cout << "Choix invalide !" << endl;
    }

    return 0;
}
