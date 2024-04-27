/**
 * \file 
 * \brief Test unitaire de la classe de base RegistreBorne
 * \author Aymen Marrakchi
 * \version 0.1
 * \date
 */
#include <cstdlib>
#include <gtest/gtest.h>
#include <iostream>
#include "RegistreBorne.h"
#include "ContratException.h"
#include "BorneStationnement.h"
#include "BorneFontaine.h"
#include "BorneException.h"
using namespace std;
using namespace bornesQuebec;


class RegistreBorneTest : public ::testing::Test {
public:
    RegistreBorne registre{"RegistreTest"};

    void SetUp()  {
        registre.ajouteBorne(BorneStationnement(1, "123", "1re Avenue", -71.2363
, 46.829, 4005, "E"));
    }
};
/**
* \brief Test du constructeur
* Cas valides : Création d'un objet RegistreBorne et vérification de l'assignation de tous les attributs
*                           Cas invalides :
 *                          Nom de registre de borne Vide
 *                          Cas Valuide:
 *
 */
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
                "Voie publique : 200\n"
                "Nom topographique : Avenue Test\n"
                "Latitude : -73.5678\n"
                "Longitude : 45.5022\n"
                "Numero de la borne : 300\n"
                "Cote de la rue : S\n"
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
                "Voie publique : 123\n"
                "Nom topographique : 1er Avenue \n"
                "Latitude : 45.5017\n"
                "Longitude : -73.5673\n"
                "Numero de la borne : 123\n"
                "Cote de la rue : N\n"
                "\n----------------------------------------------\n";
std::string resultatFormate = registre.reqRegistreBorneFormate();
std::string resultatSansPremiereLigne = registre.enleverPremiereLigne(resultatFormate);


    ASSERT_EQ(resultatSansPremiereLigne, expected);
}
//cas Invalide
/**
 * \brief Test de la méthode supprimeBorne()
 * Cas valide: Vérifier la suppression d'une borne existante
 */
TEST_F(RegistreBorneTest, supprimerBorneValide) {
    int identifiantExistant = 1;  // Assurez-vous que cette borne a été ajoutée dans SetUp()
    registre.supprimeBorne(identifiantExistant);
    EXPECT_EQ(registre.NombreDeBornes(), 0) << "La borne doit être supprimée du registre";
}

/**
 * \brief Test de la méthode supprimeBorne()
 * Cas invalide: Vérifier la suppression d'une borne non existante
 */
TEST_F(RegistreBorneTest, supprimerBorneInvalide) {
    int identifiantNonExistant = 40;  // Utilisez un identifiant qui n'a pas été ajouté dans SetUp()
    ASSERT_THROW(registre.supprimeBorne(identifiantNonExistant),BorneAbsenteException()) << "Une exception doit être lancée si la borne n'existe pas";
}
