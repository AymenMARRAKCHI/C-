/**
 * \file 
 * \brief Test unitaire de la classe de base Borne
 * \author Aymen Marrakchi
 * \version 0.1
 * \date
 */


#include <cstdlib>
#include <gtest/gtest.h>
#include <iostream>
#include "Borne.h"
#include "ContratException.h"
#include <sstream>
using namespace std;
using namespace bornesQuebec;
/**
 * \class BorneDeTest
 * \brief Classe de test permettant de tester la classe abstraite Borne
 */

class BorneDeTest : public Borne
{
public : 
  
  BorneDeTest (int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude, double p_latitude):
  
  Borne(p_identifiant,p_identifiantVoiePublique,p_nomTopographique, p_longitude, p_latitude){};

  virtual std::unique_ptr<Borne>clone () const
  {
    return 0 ;
  }

};
/**
 * \test Test du constructeur
 * 		Cas valides: Creation d’un objet Borne et verification de l’assignation de tous les attributs
 * 		cas invalides:
 * 			identifiant  inférieur à 0 
 *                     
 **/

TEST ( Borne, constructeur)
{
  BorneDeTest uneBorne(15433, "115066", "Rue Arthur-Dion ",-71.3694, 46.8486 );
  ASSERT_EQ (15433, uneBorne.reqIdentifiant ());
  ASSERT_EQ ("115066", uneBorne.reqIdentifiantVoiePublique ());
  ASSERT_EQ ("Rue Arthur-Dion ", uneBorne.reqNomTopographique ());
  ASSERT_EQ (-71.3694, uneBorne.reqLongitude ());
  ASSERT_EQ (46.8486, uneBorne.reqLatitude ());

}
//Cas invalide

TEST (Borne, ConstructreurIdentifiantMoinDeZero)
{
  ASSERT_THROW (BorneDeTest uneBorne(-1,"115066", "Rue Arthur-Dion ",-71.3694, 46.8486 ),PreconditionException);
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe de test
 */

class uneBorne : public :: testing :: Test 
{
public: 
  
  uneBorne ():
  f_borne (100001, "115066", "1er Avenue", 46.82899800269792, -71.23627057605484){}
  BorneDeTest f_borne;
  

};
/**
 * \test Test de la méthode reqIdentifiant()
 * 		Cas valide: vérifier le retour du nom ID
 * 		Cas invalide: aucun
 */
TEST_F (uneBorne, reqIdentifiant)
{
  ASSERT_EQ (100001, f_borne.reqIdentifiant ());
}
/**
 * \test Test de la méthode reqIdentifiantVoiePublique()
 * 		Cas valide: vérifier le retour du nom IDvoiepublique
 * 		Cas invalide: aucun
 */
TEST_F (uneBorne, reqIdentifiantVoiePublique)
{
  ASSERT_EQ ("115066", f_borne.reqIdentifiantVoiePublique ());
}
/**
 * \test Test de la méthode reqNomTopographique()
 * 		Cas valide: vérifier le retour du nom Topographique
 * 		Cas invalide: aucun
 */
TEST_F (uneBorne, reqNomTopographique)
{
  ASSERT_EQ ("1er Avenue", f_borne.reqNomTopographique());
}
/**
 * \test Test de la méthode reqLongitude()
 * 		Cas valide: vérifier le retour la longitude
 * 		Cas invalide: aucun
 */
TEST_F (uneBorne, reqLongitude)
{
  ASSERT_EQ (46.82899800269792, f_borne.reqLongitude ());
}
/**
 * \test Test de la méthode reqLatitude()
 * 		Cas valide: vérifier le retour la latitude
 * 		Cas invalide: aucun
 */
TEST_F (uneBorne, reqLatitude)
{
  ASSERT_EQ (-71.23627057605484, f_borne.reqLatitude ());
}
/**
 * \test Test de la méthode asgNomTopographique()
 * 		Cas valide: vérifier l'ajout d'un nouveau nom topographique
 * 		Cas invalide: aucun
 */
TEST_F (uneBorne, asgNomTopographique)
{
  f_borne.asgNomTopographique ("1er Avenue");
}

TEST_F (uneBorne, reqBorneFormate) 
{
    std::ostringstream os;
    os << "Identifiant de la borne : " << f_borne.reqIdentifiant() << "\n";
    os << "Voie publique : " << f_borne.reqIdentifiantVoiePublique() << "\n";
    os << "Nom topographique : " << f_borne.reqNomTopographique() << "\n";
    os << "Latitude : " << f_borne.reqLatitude() << "\n";
    os << "Longitude : " << f_borne.reqLongitude() << "\n";
    ASSERT_EQ(os.str(), f_borne.reqBorneFormate());
}