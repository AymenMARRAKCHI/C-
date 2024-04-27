/**
 * \file 
 * \brief Test unitaire de la classe de base BorneFontaine
 * \author Aymen Marrakchi
 * \version 0.1
 * \date
 */
#include <cstdlib>
#include <gtest/gtest.h>
#include <iostream>
#include "BorneFontaine.h"
#include "ContratException.h"
using namespace std;
using namespace bornesQuebec;

/**
* \brief Test du constructeur
* Cas valides : Création d'un objet BorneFontaine et vérification de l'assignation de tous les attributs
*                           Cas invalides :
 *                          Ville vide 
 *                          ville  et arrondissement Vide 
 *                          arrondissement vide
 *                          Cas Valuide:
 *
 */
TEST (BorneFontaine, constructeur)
{
  BorneFontaine BorneFontainetest(1, "123", "NomTopographique", 45.5017, -73.5673, "Québec", "Arrondissement");
  ASSERT_EQ (1, BorneFontainetest.reqIdentifiant ());
  ASSERT_EQ ("123", BorneFontainetest.reqIdentifiantVoiePublique  ());
  ASSERT_EQ ("NomTopographique", BorneFontainetest.reqNomTopographique  ());
  ASSERT_EQ (45.5017, BorneFontainetest.reqLongitude  ());
  ASSERT_EQ (-73.5673, BorneFontainetest.reqLatitude  ());
  ASSERT_EQ ("Québec", BorneFontainetest.reqVille ());
  ASSERT_EQ ("Arrondissement", BorneFontainetest.reqArrondissement  ());
  
}
//Cas invalide

TEST(BorneFontaine, ConstructeurCasinvalide)
{
    ASSERT_THROW(BorneFontaine BorneFontainetest(1, "123", "NomTopographique", 45.5017, -73.5673, "Québec", ""),PreconditionException) << "arrondissement vide et ville == Québec";
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UneBorneFontaine: public ::testing::Test
{
public:
	UneBorneFontaine() :
		f_BorneFontaine(1, "123", "NomTopographique", 45.5017, -73.5673, "Québec", "Arrondissement")
	{}
	;
	BorneFontaine f_BorneFontaine;
};

/**
 * \brief Test de la méthode reqVille()
 *     Cas valide: vérifier le nom de la Ville
 *     Cas invalide: aucun
 */
TEST_F(UneBorneFontaine, reqVille)
{
	ASSERT_EQ("Québec",f_BorneFontaine.reqVille ());
}

/**
 * \brief Test de la méthode reqArrondissement()
 *     Cas valide: vérifier le nom de l'Arrondissement
 *     Cas invalide: aucun
 */
TEST_F(UneBorneFontaine, reqArrondissement)
{
	ASSERT_EQ("Arrondissement",f_BorneFontaine.reqArrondissement ());
}


/**
 * \brief Test de la méthode clone()
 *     Cas valide: Vérifie que le clone n'est pas null, une instance distincte et les informations du clone correspondent à l'original
 *     Cas invalide: aucun
 */
TEST(BorneFontaine, Clone) {
    BorneFontaine original(123, "100", "Boulevard de l'Indépendance", 45.5017, -73.5673, "Montréal", "Plateau-Mont-Royal");
    std::unique_ptr<bornesQuebec::Borne> clone = original.clone();

    ASSERT_TRUE(clone != nullptr);

    EXPECT_NE(&original, clone.get());

    BorneFontaine* clonedBorne = dynamic_cast<BorneFontaine*>(clone.get());
    ASSERT_TRUE(clonedBorne != nullptr);
    
    EXPECT_EQ(original.reqIdentifiant(), clone->reqIdentifiant());
    EXPECT_EQ(original.reqIdentifiantVoiePublique(), clone->reqIdentifiantVoiePublique());
    EXPECT_EQ(original.reqNomTopographique(), clone->reqNomTopographique());
    EXPECT_EQ(original.reqLongitude(), clone->reqLongitude());
    EXPECT_EQ(original.reqLatitude(), clone->reqLatitude());
    EXPECT_EQ(clonedBorne->reqVille(), original.reqVille());
    EXPECT_EQ(clonedBorne->reqArrondissement(), original.reqArrondissement());
}

/**
 * \test Test de la méthode std::string reqBorneFormate();
 * 		Cas valide: vérifier le retour des informations sur l’objet BorneFontaine formate
 * 		Cas invalide: aucun
 */
TEST(BorneFontaine, reqBorneFormate) {
    BorneFontaine borne(123, "100", "Boulevard de l'Indépendance", 45.5017, -73.5673, "Montréal", "Plateau-Mont-Royal");
    
    std::ostringstream oss;
    oss << "Borne-fontaine\n"
                << "----------------------------------------------\n"
                << "Identifiant de la borne : " << 123 << "\n"
                << "Voie publique : " << "100" << "\n"
                << "Nom topographique : " << "Boulevard de l'Indépendance" << "\n"
                << "Latitude : " << -73.5673 << "\n"
                << "Longitude : " << 45.5017 << "\n"
                << "Ville : " << "Montréal" << "\n"
                << "Arrondissement : " << "Plateau-Mont-Royal" << "\n";

    EXPECT_EQ(borne.reqBorneFormate(), oss.str());
}
