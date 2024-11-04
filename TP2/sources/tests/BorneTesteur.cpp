/**
 * \file BorneTesteur.cpp
 * \brief Implantation des tests unitaires de la classe Borne
 *        Borne étant une classe abstraite, on crée une classe concrète
 *        dérivée de cette classe afin de pouvoir effectuer les tests
 * \author Zied
 * \version 1.0 mise aux normes
 */

#include<gtest/gtest.h>
#include <stdlib.h>
#include <iostream>
#include "Borne.h"
#include "ContratException.h"

using namespace BorneQuebec;

/**
 * \class BorneDeTest
 * \brief classe de test permettant de tester la classe abstraite Borne
 */
class BorneDeTest : public Borne
{
public:
  BorneDeTest (int p_identifiant, const std::string& p_identifiantVoiePublique,
                    const std::string& p_nomTopographique, double p_latitude, double p_longitude):
  Borne(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_latitude, p_longitude){}
  ;//instancie un objet Polygone
  
virtual std::unique_ptr<Borne> clone() const { return 0; } ;
 //doit être implantée car la classe est concrète


};

/**
 * \test Test du constructeur
 * 		Cas valides: Creation d’un objet Borne et verification de l’assignation de tous les attributs
 * 		cas invalides:
 * 			Identifiant < 0
 *                      IdentifiantVoiePublique contient des lettre
 * 			NomTopographique ne doit pas etre vide
 * 			
 *                      
 */
TEST (Borne, constructeur)
{
  BorneDeTest BorneTest(1, "12300", "NomTopographique", 45.5017, -73.5673);
  ASSERT_EQ (1, BorneTest.reqIdentifiant ());
  ASSERT_EQ ("12300", BorneTest.reqIdentifiantVoiePublique  ());
  ASSERT_EQ ("NomTopographique", BorneTest.reqNomTopographique  ());
  ASSERT_EQ (45.5017, BorneTest.reqLongitude  ());
  ASSERT_EQ (-73.5673, BorneTest.reqLatitude  ());
  
}
//Cas invalide

TEST(Borne, ConstructeurIdentifiantInvalidenegatif)
{
    ASSERT_THROW(BorneDeTest BorneTest(-1, "12300", "NomTopographique", 45.5017, -73.5673),PreconditionException) << "L'identifiant ne doit pas etre négative";
}

TEST(Borne, ConstructeurIdentifiantInvalidegal0)
{
    ASSERT_THROW(BorneDeTest BorneTest(0, "12300", "NomTopographique", 45.5017, -73.5673),PreconditionException) << "L'identifiant ne doit pas etre 0";
}

TEST(Borne, ConstructeurIdentifiantVoiePubliqueInvalide)
{
    ASSERT_THROW(BorneDeTest BorneTest(5, "123AA", "NomTopographique", 45.5017, -73.5673),PreconditionException) << "Le IdentifiantVoiePublique ne doit pas CONTENIR DES LETTRE ";  
}

TEST(Borne, ConstructeurnomTopographiqueInvalide)
{
    ASSERT_THROW(BorneDeTest BorneTest(5, "12300", "", 45.5017, -73.5673),PreconditionException) << "Le NomTopographique ne doit pas etre vide";  
}




/**
 * \class UneBorne
 * \brief Fixture  UneBorne pour la création d'un objet Borne pour les tests
 */
class UneBorne : public ::testing::Test
{

public:
  UneBorne () :
  f_Borne (2, "1235", "NomTopographique1", 48.5005, -73.5005){}
  BorneDeTest f_Borne;
  

} ;

/**
 * \test Test de la méthode reqIdentifiant()
 * 		Cas valide: vérifier le retour de l'identifiant
 * 		Cas invalide: aucun
 */
TEST_F (UneBorne, reqIdentifiant)
{
  ASSERT_EQ (2, f_Borne.reqIdentifiant ());
}

/**
 * \test Test de la méthode reqIdentifiantVoiePublique()
 * 		Cas valide: vérifier le retour de l'identifiantVoiePublique
 * 		Cas invalide: aucun
 */
TEST_F (UneBorne, reqIdentifiantVoiePublique)
{
  ASSERT_EQ ("1235", f_Borne.reqIdentifiantVoiePublique ());
}
/**
 * \test Test de la méthode reqNomTopographique()
 * 		Cas valide: vérifier le retour du NomTopographique
 * 		Cas invalide: aucun
 */
TEST_F (UneBorne, reqNomTopographique)
{
  ASSERT_EQ ("NomTopographique1", f_Borne.reqNomTopographique ());
}

/**
 * \test Test de la méthode reqLongitude()
 * 		Cas valide: vérifier le retour du reqLongitude
 * 		Cas invalide: aucun
 */
TEST_F (UneBorne, reqLongitude)
{
  ASSERT_EQ (48.5005, f_Borne.reqLongitude ());
}

/**
 * \test Test de la méthode reqLatitude()
 * 		Cas valide: vérifier le retour du reqLatitude
 * 		Cas invalide: aucun
 */
TEST_F (UneBorne, reqLatitude)
{
  ASSERT_EQ (-73.5005, f_Borne.reqLatitude ());
}

/**
 * \test Test de la méthode asgNomTopographique()
 * 		Cas valide: vérifier si le NomTopographique est changer
 * 		Cas invalide: NomTopographique ne doit pas etre vide
 */
TEST_F (UneBorne, asgNomTopographique)
{
  f_Borne.asgNomTopographique ("nom2");
  
  ASSERT_EQ ("nom2", f_Borne.reqNomTopographique ());
}

//Cas invalide

TEST_F(UneBorne, asgNomTopographiquecasinvalide)
{
    ASSERT_THROW(f_Borne.asgNomTopographique (""),PreconditionException) << "Le NomTopographique ne doit pas etre vide";  
}
/**
 * \test Test de la méthode operator== ()
 * 		Cas valide: TRUE si les deux bornes sont identique
 *                          FALSE si les deux bornes ne sont pas identique
 * 		Cas invalide: aucun
 */

TEST_F(UneBorne, EqualOperatorTrue) {
    BorneDeTest borne1(2, "1235", "NomTopographique1", 48.5005, -73.5005);
    EXPECT_TRUE(borne1 == f_Borne)<< "L'operateur de la borne ne correspond pas à l'attendu.";
}

TEST(BorneTest, EqualOperatorFalse) {
    BorneDeTest borne1(1, "10", "Rue de Paris", 48.8566, 2.3522);
    BorneDeTest borne2(2, "1235", "NomTopographique1", 48.5005, -73.5005);
    EXPECT_FALSE(borne1 == borne2)<< "L'operateur de la borne ne correspond pas à l'attendu.";
}

/**
 * \test Test de la méthode std::string reqBorneFormate();
 * 		Cas valide: vérifier le retour des informations sur l’objet Borne formate AVECVoiePublique
 *                          vérifier le retour des informations sur l’objet Borne formate SANSVoiePublique
 * 		Cas invalide: aucun
 */
TEST(BorneTest, ReqBorneFormateAVECVoiePublique) {
    BorneDeTest borne(123, "100", "Boulevard de l'Indépendance", 45.5017, -73.5673);
    std::ostringstream oss;
    oss << "Identifiant de la borne : " << 123 << std::endl
        << "Voie publique : " << "100" << std::endl
        << "Nom topographique : " << "Boulevard de l'Indépendance" << std::endl
        << "Latitude : " << -73.5673 << std::endl
        << "Longitude : " << 45.5017 << std::endl;
    
    EXPECT_EQ(borne.reqBorneFormate(), oss.str())<< "Le formatage de la borne ne correspond pas à l'attendu.";
}

TEST(BorneTest, ReqBorneFormateSANSVoiePublique) {
    BorneDeTest borne(456, "", "Avenue de la République", 48.8566, 2.3522);
    std::ostringstream oss;
    oss << "Identifiant de la borne : " << 456 << std::endl
        << "Nom topographique : " << "Avenue de la République" << std::endl
        << "Latitude : " << 2.3522 << std::endl
        << "Longitude : " << 48.8566 << std::endl;
    
    EXPECT_EQ(borne.reqBorneFormate(), oss.str())<< "Le formatage de la borne ne correspond pas à l'attendu.";
}

/**
 * \test Test de la méthode STATIC estNumeriqueOuVide()
 * 		Cas valide: vérifier le retour de estNumeriqueOuVide avec une chaine vide
 *                          vérifier le retour de estNumeriqueOuVide avec une chaine qui contient des chiffres
 *              Cas invalide : vérifier le retour de estNumeriqueOuVide avec une chaine qui contient des chiffre des des lettres
 * 		
 */

// Cas valide: Chaîne vide
TEST(BorneTest, EstNumeriqueOuVide_ChaineVide) {
    std::string chaineVide = "";
    EXPECT_TRUE(Borne::estNumeriqueOuVide(chaineVide));
}

// Cas valide: Chaîne avec uniquement des chiffres
TEST(BorneTest, EstNumeriqueOuVide_ChaineAvecChiffres) {
    std::string chaineAvecChiffres = "1234567890";
    EXPECT_TRUE(Borne::estNumeriqueOuVide(chaineAvecChiffres));
}

// Cas invalide: Chaîne avec des chiffres et des lettres
TEST(BorneTest, EstNumeriqueOuVide_ChaineAvecChiffresEtLettres) {
    std::string chaineAvecChiffresEtLettres = "123a456";
    EXPECT_FALSE(Borne::estNumeriqueOuVide(chaineAvecChiffresEtLettres));
}