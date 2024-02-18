#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main ()
{
  string name;
  int age;
  string program;
  string choice;

  cout << "Bonjour! \nPour l'inscription à un de nos programmes, nous avons besoin de quelques coordonnées" << endl;

  cout << "Quel est votre nom : ";
  getline (cin, name);

  // Gestion de l'âge avec vérification de la validité de l'entrée
  cout << "Quel est votre âge : ";
  while (!(cin >> age) || cin.peek () != '\n')
    {
      cout << "Veuillez entrer un nombre entier pour l'âge : ";
      cin.clear ();
      cin.ignore (numeric_limits<streamsize>::max (), '\n');
    }

  // Gestion du choix de programme avec vérification de la validité de l'entrée
  cout << "Quel est le numéro du programme que vous voulez suivre : " << endl;
  cout << " 1 - Art \n 2 - Biologie \n 3 - Informatique \n 4 - Droit \n 5 - Politique" << endl;
  cout << "Votre choix (entre 1 et 5): ";

  while (!(cin >> choice) || (choice.length () != 1 || choice[0] < '1' || choice[0] > '5'))
    {
      cout << "Choix invalide. Veuillez choisir un numéro entre 1 et 5 : ";
      cin.clear ();
      cin.ignore (numeric_limits<streamsize>::max (), '\n');
    }

  // Conversion du choix en entier
  int choix = stoi (choice);

  // Attribution du programme choisi
  switch (choix)
    {
    case 1:
      program = "Art";
      break;
    case 2:
      program = "Biologie";
      break;
    case 3:
      program = "Informatique";
      break;
    case 4:
      program = "Droit";
      break;
    case 5:
      program = "Politique";
      break;
    }


  // Gestion de la confirmation avec vérification de la validité de l'entrée
  do
    {
      cout << "Cela vous coûtera 12 000 $ pour le programm : " << program << endl;
      cout << "Etes-vous sûr de votre choix ? \n - Oui \n - Non \n choix : ";
      cin >> choice;

      if (choice != "Oui" && choice != "Non")
        {
          cout << "Réponse invalide. Veuillez répondre avec 'Oui' ou 'Non'." << endl;
        }
    }
  while (choice != "Oui" && choice != "Non");

  if (choice == "Oui")
    {
      cout << "Voici le résumé de votre inscription : " << endl;
      cout << " --------------------------------------------------------------------------" << endl;
      cout << "Nom : " << name << " | Age: " << age << " | Programme: " << program << endl;
      cout << " --------------------------------------------------------------------------";
    }
  else
    {
      cout << "Votre inscription a échoué !" << endl;
      return 1; // Quitter le programme avec un code d'erreur
    }

  return 0;
}
