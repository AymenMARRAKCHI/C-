/**
 * \file Borne.cpp
 * \brief Implémentation de la classe de base Borne.
 * \author Aymen Marrakchi
 * \version 0.1
 * \date
 */

#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include "Borne.h"
#include "ContratException.h"
using namespace std;

namespace bornesQuebec {

  
/**
 * \brief Constructeur avec paramètres.
 *        Crée un objet Borne à partir des valeurs passées en paramètres.
 * \param[in] p_identifiant Un entier représentant l'identifiant de la borne.
 * \param[in] p_identifiantVoiePublique Une chaîne de caractères représentant l'identifiant de la voie publique.
 * \param[in] p_nomTopographique Une chaîne de caractères représentant le nom topographique de la borne.
 * \param[in] p_longitude Une valeur double représentant la longitude de la borne.
 * \param[in] p_latitude Une valeur double représentant la latitude de la borne.
 * \pre p_identifiant > 0
 * \post m_identifiant prend la valeur de p_identifiant
 * \post m_identifiantVoiePublique prend la valeur de p_identifiantVoiePublique
 * \post m_nomTopographique prend la valeur de p_nomTopographique
 * \post m_longitude prend la valeur de p_longitude
 * \post m_latitude prend la valeur de p_latitude
 */
Borne::Borne(int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude, double p_latitude) :
    m_identifiant(p_identifiant), m_identifiantVoiePublique(p_identifiantVoiePublique), m_nomTopographique(p_nomTopographique),
    m_longitude(p_longitude), m_latitude(p_latitude)
{
   PRECONDITION(p_identifiant > 0);
        PRECONDITION(!p_nomTopographique.empty());
        PRECONDITION(estNumeriqueOuVide (p_identifiantVoiePublique));
        POSTCONDITION(m_identifiant == p_identifiant);
        POSTCONDITION(m_identifiantVoiePublique == p_identifiantVoiePublique);
        POSTCONDITION(m_nomTopographique == p_nomTopographique);
        POSTCONDITION(m_longitude == p_longitude);
        POSTCONDITION(m_latitude == p_latitude);
        
        
        INVARIANTS();
}

/**
 * \brief Accesseur de l'identifiant de la borne.
 * \return L'identifiant de la borne.
 */
int Borne::reqIdentifiant() const
{
    return m_identifiant;
}

/**
 * \brief Accesseur de l'identifiant de la voie publique de la borne.
 * \return L'identifiant de la voie publique de la borne.
 */
const string& Borne::reqIdentifiantVoiePublique() const
{
    return m_identifiantVoiePublique;
}

/**
 * \brief Accesseur du nom topographique de la borne.
 * \return Le nom topographique de la borne.
 */
const string& Borne::reqNomTopographique() const
{
    return m_nomTopographique;
}

/**
 * \brief Accesseur de la longitude de la borne.
 * \return La longitude de la borne.
 */
double Borne::reqLongitude() const
{
    return m_longitude;
}

/**
 * \brief Accesseur de la latitude de la borne.
 * \return La latitude de la borne.
 */
double Borne::reqLatitude() const
{
    return m_latitude;
}

/**
 * \brief Modifie le nom topographique de la borne.
 * \param[in] nomTopographique Le nouveau nom topographique de la borne.
 */
void Borne::asgNomTopographique(const std::string& p_nomTopographique)
{
    PRECONDITION (!p_nomTopographique.empty ());
    m_nomTopographique = p_nomTopographique;
    POSTCONDITION (m_nomTopographique == p_nomTopographique);
    INVARIANTS ();
}

/**
 * \brief Surcharge de l'opérateur d'égalité.
 * \param[in] autre La borne à comparer.
 * \return True si les bornes sont égales, False sinon.
 */
bool Borne::operator==(const Borne& autre) const
{
    return (m_identifiant == autre.m_identifiant &&
            m_identifiantVoiePublique == autre.m_identifiantVoiePublique &&
            m_nomTopographique == autre.m_nomTopographique &&
            m_longitude == autre.m_longitude &&
            m_latitude == autre.m_latitude);
}

/**
 * \brief Vérifie si une chaîne de caractères représente un nombre.
 * \param[in] p_identifiantVoiePublique La chaîne de caractères à vérifier.
 * \return True si la chaîne représente un nombre, False sinon.
 */
bool Borne :: estNumeriqueOuVide(const std::string& p_chaine) {
    if (p_chaine.empty()) return true;
    for (char c : p_chaine) {
        if (!isdigit(c)) return false;
    }
    return true;
}

/**
 * \brief Retourne une chaîne de caractères formatée représentant les informations de la borne.
 * \return Une chaîne de caractères formatée représentant les informations de la borne.
 */
std::string Borne::reqBorneFormate() const
{
    std::ostringstream oss;
        oss << "Identifiant de la borne : " << m_identifiant << "\n" ;
                if (!m_identifiantVoiePublique.empty()){
                    oss<< "Voie publique : " << m_identifiantVoiePublique << "\n" ; }
            oss << "Nom topographique : " << m_nomTopographique << "\n"
            << "Latitude : "  << m_latitude << "\n"
            << "Longitude : " << m_longitude<< "\n";
        return oss.str();
}

/**
 * \brief Vérifie les invariants de la classe.
 */
void Borne::verifieInvariant() const
{
        INVARIANT(m_identifiant > 0);
        INVARIANT(!m_nomTopographique.empty() );
        INVARIANT(estNumeriqueOuVide (m_identifiantVoiePublique));
}

}
