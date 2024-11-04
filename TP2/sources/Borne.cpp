/**
 * \file Borne.cpp
 * \brief Implantation de la classe Borne
 * \author Zied
 * \version 1.0 mise aux normes
 */

#include "Borne.h"
#include <sstream>
#include <iostream>
#include <cctype>

namespace BorneQuebec
{
/**
 * \brief Constructeur de la classe Borne
 * \param[in] p_identifiant : L’identifiant de la borne
 * \param[in] p_identifiantVoiePublique : l’identifiant de la voie publique sur laquelle la borne est située
 * \param[in] p_nomTopographique : Le nom topographique (générique, liaison, spécifique, direction) du centre de chaussée.
 * \param[in] p_longitude : La longitude
 * \param[in] p_latitude : la latitude
 */ 
Borne :: Borne(int p_identifiant, const std::string& p_identifiantVoiePublique, 
                 const std::string& p_nomTopographique, double p_longitude, 
                 double p_latitude) : 
        m_identifiant(p_identifiant),
        m_identifiantVoiePublique(p_identifiantVoiePublique),
        m_nomTopographique(p_nomTopographique),
        m_longitude(p_longitude),
        m_latitude(p_latitude) 
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
 * \brief retourne l'identifiant de la Borne
 * \return l'identifiant de la Borne
 */  
int Borne :: reqIdentifiant() const { return m_identifiant; }

/**
 * \brief retourne l'IdentifiantVoiePublique de la Borne
 * \return l'IdentifiantVoiePublique de la Borne
 */
std::string Borne :: reqIdentifiantVoiePublique() const { return m_identifiantVoiePublique; }

/**
 * \brief retourne le NomTopographique de la Borne
 * \return le NomTopographique de la Borne
 */
std::string Borne :: reqNomTopographique() const { return m_nomTopographique; }

/**
 * \brief retourne la Longitude de la Borne
 * \return la Longitude de la Borne
 */
double Borne :: reqLongitude() const { return m_longitude; }

/**
 * \brief retourne l'atitude de la Borne
 * \return l'atitude de la Borne
 */
double Borne :: reqLatitude() const { return m_latitude; }

/**
 * \brief Mutateur pour changer le nom topographique
 * \param[in] p_nomTopographique
 */ 
void Borne :: asgNomTopographique(const std::string& p_nomTopographique) 
  { 
    PRECONDITION(!p_nomTopographique.empty());
    m_nomTopographique = p_nomTopographique;
    POSTCONDITION(m_nomTopographique == p_nomTopographique);
    INVARIANTS();
    
  }

/**
 * \brief l’opérateur de comparaison d’égalité, La comparaison se fait sur la base de tous les attributs.
 * \param[in] p_borne : une Borne
 */ 
bool Borne :: operator==(const Borne& p_borne) const
  {
	return m_identifiant == p_borne.m_identifiant &&
               m_identifiantVoiePublique == p_borne.m_identifiantVoiePublique &&
               m_nomTopographique == p_borne.m_nomTopographique &&
               m_longitude == p_borne.m_longitude &&
               m_latitude == p_borne.m_latitude ;
  }
  
/**
 * \brief Affichage des Bornes
 * \param[in] oss une ostream dans laquelle on affiche les Bornes
 */
  std::string Borne :: reqBorneFormate() const {
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
 * \brief pour vérifier l'invariant de classe dans l'implantation de la théorie du contrat
 */  
Borne :: ~Borne () {; }
  
/**
 * \brief Methode pour verifier si une chaine est numerique ou vide
 */
bool Borne :: estNumeriqueOuVide(const std::string& p_chaine) {
    if (p_chaine.empty()) return true;
    for (char c : p_chaine) {
        if (!isdigit(c)) return false;
    }
    return true;
}


/**
 * \brief pour vérifier l'invariant de classe dans l'implantation de la théorie du contrat
 */
void Borne :: verifieInvariant() const
{
	INVARIANT(m_identifiant > 0);
        INVARIANT(!m_nomTopographique.empty() );
        INVARIANT(estNumeriqueOuVide (m_identifiantVoiePublique));

        
}

} // util namespace


