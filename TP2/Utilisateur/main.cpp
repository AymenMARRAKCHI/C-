/**
 * \file main.cpp
 * \brief Implantation du programme minimaliste
 * \author Zied
 * \version 1.0 mise aux normes
 */

#include "ContratException.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include <string>
#include "Borne.h"
#include "Borne.cpp"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include "RegistreBorne.h"
#include "validationFormat.h"
#include <cctype>
#include <limits>

using namespace BorneQuebec ;

int main() {
  
    //Création du registre des bornes
    //Ce registre contiendra toutes les bornes enregistrées pendant l'exécution du programme.
    RegistreBorne registre("bornes de l'agglomération de la ville de Québec");

    // Enregistrement d'une borne fontaine
    std::cout << "Enregistrement d’une borne fontaine :" << std::endl;
    
    // Les variables nécessaires pour la saisie des informations de la borne fontaine
    int idBorne;
    double longitude, latitude;
    std::string idVoie, nomTopo,  villef, arrondissementf;

    // Enregistrement de l'identifiant de la borne
    do {
        std::cout << "Entrez l'identifiant de la borne valide: ";
        std::cin >> idBorne;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (idBorne <= 0);

    // Enregistrement de l'identifiant de la Voie Publique
    do {
        std::cout << "Entrez l'identifiant de la Voie Publique de la borne valide: ";
        std::getline(std::cin, idVoie);
    } while (!(BorneFontaine::estNumeriqueOuVide (idVoie))); 
    
    // Enregistrement du nom topographique
    do {
        std::cout << "Entrez le nom topographique valide: ";
        std::getline(std::cin, nomTopo);
    } while (nomTopo.empty());

    // Longitude et latitude
    std::cout << "Entrez la longitude: ";
    std::cin >> longitude;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Entrez la latitude: ";
    std::cin >> latitude;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Enregistrement de la ville
    std::cout << "Entrez le nom de la ville : ";
    std::getline(std::cin, villef);

    // Enregistrement de l'arrondissement
    do {
        std::cout << "Entrez le nom de l'arrondissement : ";
        std::getline(std::cin, arrondissementf);
    } while (villef == "Québec" && arrondissementf.empty());

    // Création et enregistrement de la borne fontaine
    std::unique_ptr<BorneFontaine> borneFontaine = std::make_unique<BorneFontaine>(idBorne, idVoie, nomTopo, longitude, latitude, villef, arrondissementf);
    registre.ajouteBorne(*borneFontaine);

    // Enregistrement d'une borne de stationnement
    std::cout << std::endl <<"Enregistrement d’une borne de stationnement :" << std::endl;
    
    // Les variables nécessaires pour la saisie des informations de la borne de stationnement
    int numBornes;
    std::string coteRues;

    /// Enregistrement de l'identifiant de la borne
    do {
        std::cout << "Entrez l'identifiant de la borne valide: ";
        std::cin >> idBorne;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (idBorne <= 0);

    // Enregistrement de l'identifiant de la Voie Publique
    do {
        std::cout << "Entrez l'identifiant de la Voie Publique de la borne valide: ";
        std::getline(std::cin, idVoie);
    } while (!(BorneFontaine::estNumeriqueOuVide (idVoie))); 
    
    // Enregistrement du nom topographique
    do {
        std::cout << "Entrez le nom topographique valide: ";
        std::getline(std::cin, nomTopo);
    } while (nomTopo.empty());

    // Longitude et latitude
    std::cout << "Entrez la longitude: ";
    std::cin >> longitude;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Entrez la latitude: ";
    std::cin >> latitude;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    do {
        std::cout << "Entrez le numéro de la borne de stationnement: ";
        std::cin >> numBornes;
    } while (numBornes < 1 || numBornes > 9999);
    
  do {
        std::cout << "Entrez le cote de la rue (N, S, E, O) :";
        std::cin >> coteRues;
    } while (!(util::validePointCardinal (coteRues)));

    // Création et enregistrement de la borne de stationnement
    std::unique_ptr<BorneStationnement> borneStationnement = std::make_unique<BorneStationnement>(idBorne, idVoie, nomTopo, longitude, latitude, numBornes, coteRues);
    registre.ajouteBorne(*borneStationnement);
 
    // Affichage du contenu du registre
    std::cout << std::endl <<"Contenu du registre :"  << std::endl;
    std::cout << std::endl <<"Registre : " << registre.reqnomRegistreBorne () << std::endl << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::string resultatFormate = registre.reqRegistreBorneFormate();
    std::string resultatSansPremiereLigne = registre.enleverPremiereLigne(resultatFormate);
    std::cout << resultatSansPremiereLigne << std::endl;
        
    return 0;
}

