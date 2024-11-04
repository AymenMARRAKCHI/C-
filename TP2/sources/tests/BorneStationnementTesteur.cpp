/**
 * \file BorneStationnementTesteur.cpp
 * \brief Test unitaire de la classe BorneStationnement
 * \author Zied
 * \version 1.0 mise aux normes
 */

#include<gtest/gtest.h>
#include <stdlib.h>
#include <iostream>
#include "BorneStationnement.h"
#include "ContratException.h"

using namespace BorneQuebec ;

/**
 * \brief Test du constructeur
 * 		  Cas valides: Création d'un objet BorneStationnement et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		       Le m_numBorne sup que 4 chiffres
 *                     m_coteRue n'est pas un point cardinal
 */
TEST (BorneStationnement, constructeur)
{
  BorneStationnement BorneStationnementtest(1, "123", "NomTopographique", 45.5017, -73.5673, 1234, "E");
  ASSERT_EQ (1, BorneStationnementtest.reqIdentifiant ());
  ASSERT_EQ ("123", BorneStationnementtest.reqIdentifiantVoiePublique  ());
  ASSERT_EQ ("NomTopographique", BorneStationnementtest.reqNomTopographique  ());
  ASSERT_EQ (45.5017, BorneStationnementtest.reqLongitude  ());
  ASSERT_EQ (-73.5673, BorneStationnementtest.reqLatitude  ());
  ASSERT_EQ (1234, BorneStationnementtest.reqnumBorne ());
  ASSERT_EQ ("E", BorneStationnementtest.reqcoteRue  ());
  
}
//Cas invalide

TEST (BorneStationnement, ConstructeurCasinvalidem_numBorneplus)
{
    ASSERT_THROW(BorneStationnement BorneStationnementtest(1, "123", "NomTopographique", 45.5017, -73.5673, 12345, "E"),PreconditionException) << "Le m_numBorne Peut etre compose de 1 à 4 chiffres";
}

TEST( BorneStationnement, ConstructeurCasinvalidem_coteRue)
{
    ASSERT_THROW(BorneStationnement BorneStationnementtest(1, "123", "NomTopographique", 45.5017, -73.5673, 1234, "Eva"),PreconditionException) << "m_coteRue Il doit correspondre à un point cardinal";
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UneBorneStationnement: public ::testing::Test
{
public:
	UneBorneStationnement() :
		f_BorneStationnement(1, "123", "NomTopographique", 45.5017, -73.5673, 1234, "E")
	{}
	;
	BorneStationnement f_BorneStationnement;
};

/**
 * \brief Test de la méthode reqnumBorne()
 *     Cas valide: vérifier le numBorne
 *     Cas invalide: aucun
 */
TEST_F(UneBorneStationnement, reqnumBorne)
{
	ASSERT_EQ(1234,f_BorneStationnement.reqnumBorne ());
}

/**
 * \brief Test de la méthode reqcoteRue()
 *     Cas valide: vérifier le coteRue
 *     Cas invalide: aucun
 */
TEST_F(UneBorneStationnement, reqcoteRue)
{
	ASSERT_EQ("E",f_BorneStationnement.reqcoteRue ());
}




/**
 * \brief Test de la méthode clone()
 *     Cas valide: Vérifie que le clone n'est pas null, une instance distincte et les informations du clone correspondent à l'original
 *     Cas invalide: aucun
 */
TEST(BorneStationnement, Clone) {
    BorneStationnement original(123, "100", "Boulevard de l'Indépendance", 45.5017, -73.5673, 250, "N");
    std::unique_ptr<BorneQuebec::Borne> clonePtr = original.clone();

    ASSERT_TRUE(clonePtr != nullptr);
    BorneStationnement* clone = dynamic_cast<BorneStationnement*>(clonePtr.get());
    ASSERT_TRUE(clone != nullptr);

    // Comparaison de chaque attribut membre, y compris ceux hérités
    EXPECT_EQ(original.reqIdentifiant(), clone->reqIdentifiant());
    EXPECT_EQ(original.reqIdentifiantVoiePublique(), clone->reqIdentifiantVoiePublique());
    EXPECT_EQ(original.reqNomTopographique(), clone->reqNomTopographique());
    EXPECT_EQ(original.reqLongitude(), clone->reqLongitude());
    EXPECT_EQ(original.reqLatitude(), clone->reqLatitude());
    EXPECT_EQ(original.reqnumBorne(), clone->reqnumBorne());
    EXPECT_EQ(original.reqcoteRue(), clone->reqcoteRue());
}

/**
 * \test Test de la méthode std::string reqBorneFormate();
 * 		Cas valide: vérifier le retour des informations sur l’objet BorneFontaine formate
 * 		Cas invalide: aucun
 */
TEST(BorneStationnement, reqBorneFormate) {
    BorneStationnement BorneStationnement(123, "100", "Boulevard de l'Indépendance", 45.5017, -73.5673, 1234, "E");
    
    std::ostringstream oss;
    oss << "Borne de stationnement\n"
                << "----------------------------------------------\n"
                << "Identifiant de la borne : " << 123 << "\n"
                << "Voie publique : " << "100" << "\n"
                << "Nom topographique : " << "Boulevard de l'Indépendance" << "\n"
                << "Latitude : " << -73.5673 << "\n"
                << "Longitude : " << 45.5017 << "\n"
                << "Numero de la borne : " << 1234 << "\n"
                << "Cote de la rue : " << "E" << "\n";

    EXPECT_EQ(BorneStationnement.reqBorneFormate(), oss.str());
}

