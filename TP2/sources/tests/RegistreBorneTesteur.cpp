/**
 * \file RegistreBorneTesteur.cpp
 * \brief Test unitaire de la classe RegistreBorne
 * \author Zied
 * \version 1.0 mise aux normes
 */

#include<gtest/gtest.h>
#include <stdlib.h>
#include <iostream>
#include "RegistreBorne.h"
#include "ContratException.h"
#include "BorneStationnement.h"
#include "BorneFontaine.h"

using namespace BorneQuebec ;

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */

class RegistreBorneTest : public ::testing::Test {
public:
    RegistreBorne registre{"RegistreTest"};

    void SetUp()  {
        registre.ajouteBorne(BorneStationnement(1, "100", "Boulevard Test", -73.5673, 45.5017, 250, "N"));
    }
};

/**
 * \brief Test du Constructeur()
 *     Cas valide: vérifier le Constructeur
 *     Cas invalide: nom est vide
 */
TEST_F(RegistreBorneTest, Constructeur) {
    EXPECT_EQ(registre.reqnomRegistreBorne(), "RegistreTest");
}

// cas invalide

TEST(RegistreBorne, Constructeurvide) {
  ASSERT_THROW(RegistreBorne RegistreBorne(""),PreconditionException)<<"ne doit pas etre vide" ;

}

/**
 * \brief Test de la méthode reqnomRegistreBorne()
 *     Cas valide: vérifier du nomRegistreBorne
 *     Cas invalide: aucun
 */
TEST_F(RegistreBorneTest, ReqNomRegistreBorne) {
    EXPECT_EQ(registre.reqnomRegistreBorne(), "RegistreTest");
}

/**
 * \brief Test de la méthode NombreDeBornes()
 *     Cas valide: vérifier le NombreDeBornes
 *     Cas invalide: aucun
 */
TEST_F(RegistreBorneTest, NombreDeBornes) {
    EXPECT_EQ(registre.NombreDeBornes(), 1);
}

/**
 * \brief Test de la méthode ajouteBorne()
 *     Cas valide: vérifier l'ajout DE LA Borne
 *     Cas invalide: aucun
 */
TEST_F(RegistreBorneTest, AjouteBorne) {
    registre.ajouteBorne(BorneStationnement(2, "200", "Avenue Test", -73.5678, 45.5022, 300, "S"));
    EXPECT_EQ(registre.NombreDeBornes(), 2);
}

/**
 * \brief Test de la méthode reqRegistreBorneFormate()
 *     Cas valide: vérifier le vérifier le retour des informations sur l’objet RegistreBorne formate
 *     Cas invalide: aucun
 */
TEST_F(RegistreBorneTest, ReqRegistreBorneFormate) {
    std::string expected = "Registre : RegistreTest\n";
    expected += "Borne de stationnement\n"
                "----------------------------------------------\n"
                "Identifiant de la borne : 1\n"
                "Voie publique : 100\n"
                "Nom topographique : Boulevard Test\n"
                "Latitude : 45.5017\n"
                "Longitude : -73.5673\n"
                "Numero de la borne : 250\n"
                "Cote de la rue : N\n"
                "\n----------------------------------------------\n";

    EXPECT_EQ(registre.reqRegistreBorneFormate(), expected);
}

/**
 * \brief Test de la méthode RegistreBorne()
 *     Cas valide: vérifier du RegistreBorne constructeur en copie (nom du registre + nbr de borne )
 *     Cas invalide: aucun
 */
TEST_F(RegistreBorneTest, ConstructeurDeCopie) {
    RegistreBorne copie{registre};
    ASSERT_EQ(copie.reqnomRegistreBorne(), registre.reqnomRegistreBorne());
    ASSERT_EQ(copie.NombreDeBornes(), registre.NombreDeBornes());
}

/**
 * \brief Test de la méthode operator= ()
 *     Cas valide: vérifier l'operateur = pour la copie (nom du registre + nbr de borne )
 *     Cas invalide: aucun
 */
TEST_F(RegistreBorneTest, OperateurAssignation) {
    RegistreBorne copie = registre;
    ASSERT_EQ(copie.reqnomRegistreBorne(), registre.reqnomRegistreBorne());
    ASSERT_EQ(copie.NombreDeBornes(), registre.NombreDeBornes());
}

/**
 * \brief Test de la méthode enleverPremiereLigne()
 *     Cas valide: vérifier le vérifier le retour des informations sur l’objet enleverPremiereLigne
 *     Cas invalide: aucun
 */
TEST_F(RegistreBorneTest, enleverPremiereLigne) {
    std::string expected = "Borne de stationnement\n";
    expected += "----------------------------------------------\n"
                "Identifiant de la borne : 1\n"
                "Voie publique : 100\n"
                "Nom topographique : Boulevard Test\n"
                "Latitude : 45.5017\n"
                "Longitude : -73.5673\n"
                "Numero de la borne : 250\n"
                "Cote de la rue : N\n"
                "\n----------------------------------------------\n";
std::string resultatFormate = registre.reqRegistreBorneFormate();
std::string resultatSansPremiereLigne = registre.enleverPremiereLigne(resultatFormate);


    ASSERT_EQ(resultatSansPremiereLigne, expected);
}
