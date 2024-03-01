#include <iostream> 
#include <string>

using namespace std;

class Personne {
    private : 
    string nom;
    int age;
    
    public :
    Personne(const string &nom, int age)
    {
        this -> nom = nom;
        this -> age = age;
    }
    string reqNom () { return nom; }
    
    int reqAge() { return age;}
    
    void asgNom(string m_nom)
    {
        nom = m_nom;
    }
    
    void asgAge ( int m_age)
    {
        age = m_age;
    }
    
    
};

int main ()
{
    Personne p1("Alice", 30);
    cout << "Nom : " << p1.reqNom() << endl;
    cout << "Age : " << p1.reqAge() << endl;
    
    p1.asgNom ("Bob"); p1.asgAge(25);
    cout << "Nouveau nom : " << p1.reqNom() << endl;
    cout << "Nouvel age : " << p1.reqAge() << endl;
    return 0;
    
    
}
