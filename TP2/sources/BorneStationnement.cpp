/**
 * \file BorneStationnement.cpp
 * \brief Implantation de la classe BorneStationnement
 * \author Zied
 * \version 1.0 mise aux normes
 */

#include "BorneStationnement.h"
#include "validationFormat.h"
#include <sstream>
#include <iostream>

namespace BorneQuebec
{
  
/**
 * \brief Constructeur de la classe BorneStationnement
 * \param[in] p_identifiant : L’identifiant de la borne
 * \param[in] p_identifiantVoiePublique : l’identifiant de la voie publique sur laquelle la borne est située
 * \param[in] p_nomTopographique : Le nom topographique (générique, liaison, spécifique, direction) du centre de chaussée.
 * \param[in] p_longitude : La longitude
 * \param[in] p_latitude : la latitude
 * \param[in] p_numBorne : Le numéro de la borne
 * \param[in] p_coteRue : Le coté par rapport au centre de chaussée où est la borne
 */
BorneStationnement :: BorneStationnement(int p_identifiant, const std::string& p_identifiantVoiePublique, 
                 const std::string& p_nomTopographique, double p_longitude, 
                 double p_latitude, int p_numBorne, 
                                const std::string& p_coteRue)
                : Borne(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude),
          m_numBorne(p_numBorne), m_coteRue(p_coteRue)
 {
        PRECONDITION(p_numBorne > 1);
        PRECONDITION(p_numBorne < 9999);
        PRECONDITION(util::validePointCardinal (p_coteRue));
        
        POSTCONDITION(m_numBorne == p_numBorne);
        POSTCONDITION(m_coteRue == p_coteRue);
        
        INVARIANTS();
 
 
 }
  
/**
 * \brief retourne le numBorne de la BorneStationnement
 * \return le numBorne de la BorneStationnement
 */
int BorneStationnement :: reqnumBorne() const { return m_numBorne; }

/**
 * \brief retourne la coteRue de la BorneStationnement
 * \return la coteRue de la BorneStationnement
 */
std::string BorneStationnement :: reqcoteRue() const { return m_coteRue; }

 /**
 * \brief méthode permet de faire une copie allouée sur le monceau de l'objet courant
 */
std::unique_ptr<BorneQuebec::Borne> BorneStationnement::clone() const {
  
    return std::make_unique<BorneStationnement>(*this);
    }

/**
 * \brief Affichage des BorneStationnements
 * \param[in] oss une ostream dans laquelle on affiche les BorneStationnements
 */
std::string BorneStationnement :: reqBorneFormate() const {
        std::ostringstream oss;
        oss << "Borne de stationnement\n"
            << "----------------------------------------------\n"
            << BorneQuebec :: Borne::reqBorneFormate()
            << "Numero de la borne : " << m_numBorne << "\n"
            << "Cote de la rue : " << m_coteRue << "\n";
        return oss.str();
    }

/**
* \brief pour vérifier l'invariant de classe dans l'implantation de la théorie du contrat
*/
  void BorneStationnement :: verifieInvariant() const
  {
	INVARIANT(util::validePointCardinal (m_coteRue));
        INVARIANT(m_numBorne > 1);
        INVARIANT(m_numBorne < 9999);
        
  }
  
  } //util namespace