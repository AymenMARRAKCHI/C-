/**
 * \file BorneFontaine.cpp
 * \brief Implantation de la classe BorneFontaine
 * \author Zied
 * \version 1.0 mise aux normes
 */

#include "BorneFontaine.h"
#include <sstream>
#include <iostream>

namespace BorneQuebec
{
  
/**
 * \brief Constructeur de la classe BorneFontaine
 * \param[in] p_identifiant : L’identifiant de la borne
 * \param[in] p_identifiantVoiePublique : l’identifiant de la voie publique sur laquelle la borne est située
 * \param[in] p_nomTopographique : Le nom topographique (générique, liaison, spécifique, direction) du centre de chaussée.
 * \param[in] p_longitude : La longitude
 * \param[in] p_latitude : la latitude
 * \param[in] p_ville : nom de la ville
 * \param[in] p_arrondissement ; nom de l'arrondissement
 */ 
BorneFontaine :: BorneFontaine(int p_identifiant, const std::string& p_identifiantVoiePublique, 
                 const std::string& p_nomTopographique, double p_longitude, 
                 double p_latitude, const std::string& p_ville, 
                                const std::string& p_arrondissement)
        : Borne(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude),
          m_ville(p_ville), m_arrondissement(p_arrondissement)
 {
        PRECONDITION(!(p_ville == "Québec" && p_arrondissement.empty())) ;
        
        POSTCONDITION(m_ville == p_ville);
        POSTCONDITION(m_arrondissement == p_arrondissement);
        
        INVARIANTS();
 
 }

/**
 * \brief retourne la Ville de la BorneFontaine
 * \return la Ville de la BorneFontaine
 */
std::string BorneFontaine :: reqVille() const { return m_ville; }

/**
 * \brief retourne l'Arrondissement de la BorneFontaine
 * \return l'Arrondissement de la BorneFontaine
 */
std::string BorneFontaine :: reqArrondissement() const { return m_arrondissement; }
 
 /**
 * \brief méthode permet de faire une copie allouée sur le monceau de l'objet courant
 */
 std::unique_ptr<BorneQuebec::Borne> BorneFontaine::clone() const {
    
    return std::make_unique<BorneFontaine>(*this);
}

/**
 * \brief Affichage des BorneFontaines
 * \param[in] oss une ostream dans laquelle on affiche les BorneFontaines
 */
std::string BorneFontaine :: reqBorneFormate() const {
        std::ostringstream oss;
        oss << "Borne-fontaine\n"
            << "----------------------------------------------\n"
            << BorneQuebec :: Borne::reqBorneFormate()
            << "Ville : " << m_ville << "\n"
            << "Arrondissement : " << m_arrondissement << "\n";
        return oss.str();
    }

/**
* \brief pour vérifier l'invariant de classe dans l'implantation de la théorie du contrat
*/
 void BorneFontaine :: verifieInvariant() const
{
	INVARIANT(!(m_ville == "Québec" && m_arrondissement.empty()));
        
}
 
 } //util namespace
