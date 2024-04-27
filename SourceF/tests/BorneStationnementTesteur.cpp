/**
 * \file 
 * \brief Test unitaire de la classe de base BorneStationnement
 * \author Aymen Marrakchi
 * \version 0.1
 * \date
 */
#include <cstdlib>
#include <gtest/gtest.h>
#include <iostream>
#include "BorneStationnement.h"
#include "ContratException.h"
using namespace std;
using namespace bornesQuebec;

/**
* \brief Test du constructeur
* Cas valides : Création d'un objet BorneFontaine et vérification de l'assignation de tous les attributs
*                           Cas invalides :
 *                          NumBorne invalide
 *                          PointCardinalInvalide
 *                          Cas Valuide:
 *
 */
TEST (BorneStationnement, constructeur)
{
  BorneStationnement BorneStationnementtest(1, "123", "NomTopographique", 45.5017, -73.5673, 1234, "E");
  ASSERT_EQ (1, BorneStationnementtest.reqIdentifiant ());
  ASSERT_EQ ("123", BorneStationnementtest.reqIdentifiantVoiePublique  ());
  ASSERT_EQ ("NomTopographique", BorneStationnementtest.reqNomTopographique  ());
  ASSERT_EQ (45.5017, BorneStationnementtest.reqLongitude  ());
  ASSERT_EQ (-73.5673, BorneStationnementtest.reqLatitude  ());
  ASSERT_EQ (1234, BorneStationnementtest.reqNumBorne ());
  ASSERT_EQ ("E", BorneStationnementtest.reqCoteRue  ());
  
}
//cas invalide
TEST (BorneStationnementTest, NumBorneInvalide)
{
  ASSERT_THROW (BorneStationnement uneBorneStationnement(15433, "115066", "Rue Arthur-Dion ",-71.3694, 46.8486,-1, "E"), PreconditionException);
}

TEST (BorneStationnementTest, PointCardinalInvalid)
{
  ASSERT_THROW (BorneStationnement uneBorneStationnement(15433, "115066", "Rue Arthur-Dion ",-71.3694, 46.8486,4005, "Z"), PreconditionException);
}



class uneBorneStationnement : public :: testing :: Test
{
public : 
  uneBorneStationnement():
  uneBorneStationnement1(15433, "115066", "Rue Arthur-Dion ",-71.3694, 46.8486,4005, "E") {};
  
  BorneStationnement uneBorneStationnement1;
};
/**
 * \test Test de la méthode reqNumBorne()
 * 		Cas valide: vérifier le retour de Numborne
 * 		Cas invalide: aucun
 */

TEST_F(uneBorneStationnement, reqNumBorne)
{
  ASSERT_EQ(4005, uneBorneStationnement1.reqNumBorne ());
}
/**
 * \test Test de la méthode reqCoteRue()
 * 		Cas valide: vérifier le retour de la cote de Rue
 * 		Cas invalide: aucun
 */

TEST_F(uneBorneStationnement, reqCoteRue)
{
  ASSERT_EQ("E", uneBorneStationnement1.reqCoteRue ());
}
TEST(BorneStationnement, Clone) {
    BorneStationnement original(123, "100", "Boulevard de l'Indépendance", 45.5017, -73.5673, 250, "N");
    std::unique_ptr<bornesQuebec::Borne> clonePtr = original.clone();

    ASSERT_TRUE(clonePtr != nullptr);
    BorneStationnement* clone = dynamic_cast<BorneStationnement*>(clonePtr.get());
    ASSERT_TRUE(clone != nullptr);

    // Comparaison de chaque attribut membre, y compris ceux hérités
    EXPECT_EQ(original.reqIdentifiant(), clone->reqIdentifiant());
    EXPECT_EQ(original.reqIdentifiantVoiePublique(), clone->reqIdentifiantVoiePublique());
    EXPECT_EQ(original.reqNomTopographique(), clone->reqNomTopographique());
    EXPECT_EQ(original.reqLongitude(), clone->reqLongitude());
    EXPECT_EQ(original.reqLatitude(), clone->reqLatitude());
    EXPECT_EQ(original.reqNumBorne(), clone->reqNumBorne());
    EXPECT_EQ(original.reqCoteRue(), clone->reqCoteRue());
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

