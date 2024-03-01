#include <iostream>

using namespace std;

class Date {
private:
    static bool estBissextile(int annee) {
        return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
    }

public:
    static bool estValide(int jour, int mois, int annee) {
        if (mois < 1 || mois > 12) return false;
        
        switch (mois) {
            case 2:
                if (estBissextile(annee)) {
                    return jour >= 1 && jour <= 29;
                } else {
                    return jour >= 1 && jour <= 28;
                }
            case 4:
            case 6:
            case 9:
            case 11:
                return jour >= 1 && jour <= 30;
            default:
                return jour >= 1 && jour <= 31;
        }
    }
};

int main() {
    int jour, mois, annee;
    
    cout << "Entrez une date (jour mois annee) : ";
    cin >> jour >> mois >> annee;
    
    if (Date::estValide(jour, mois, annee)) {
        cout << "La date est valide." << endl;
    } else {
        cout << "La date est invalide." << endl;
    }
    
    return 0;
}
