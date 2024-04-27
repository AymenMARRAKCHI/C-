/**
 * \file BorneStationnement.cpp
 * \brief Implémentation de la classe BorneStationnement, dérivée de la classe Borne.
 * \author Aymen Marrakchi
 * \version 0.1
 * \date
 */

#include "ValidationFormate.h"
#include "BorneStationnement.h"
#include "ContratException.h"
#include <sstream>
namespace bornesQuebec 
{

/**
 * \brief Constructeur avec paramètres.
 *        Crée un objet BorneStationnement à partir des valeurs passées en paramètres.
 * \param[in] p_identifiant Un entier représentant l'identifiant de la borne stationnement.
 * \param[in] p_identifiantVoiePublique Une chaîne de caractères représentant l'identifiant de la voie publique.
 * \param[in] p_nomTopographique Une chaîne de caractères représentant le nom topographique de la borne stationnement.
 * \param[in] p_longitude Une valeur double représentant la longitude de la borne stationnement.
 * \param[in] p_latitude Une valeur double représentant la latitude de la borne stationnement.
 * \param[in] p_numBorne Un entier représentant le numéro de la borne de stationnement.
 * \param[in] p_coteRue Une chaîne de caractères représentant le côté de la rue où se trouve la borne de stationnement.
 * \pre p_numBorne >= 1 && p_numBorne <= 9999
 * \pre util::validePointCardinal(p_coteRue) retourne true
 * \post m_numBorne prend la valeur de p_numBorne
 * \post m_coteRue prend la valeur de p_coteRue
 */
BorneStationnement::BorneStationnement(int p_identifiant, const std::string& p_identifiantVoiePublique,
                                        const std::string& p_nomTopographique, double p_longitude,
                                        double p_latitude, int p_numBorne, const std::string& p_coteRue)
: Borne(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude), 
  m_numBorne(p_numBorne), m_coteRue(p_coteRue)
{
  PRECONDITION(p_numBorne >= 1 && p_numBorne <= 9999);
  PRECONDITION(util::validePointCardinal(p_coteRue));
  
  POSTCONDITION(m_numBorne == p_numBorne);
  POSTCONDITION(m_coteRue == p_coteRue);
  
  INVARIANTS();
}

/**
 * \brief Accesseur pour le numéro de la borne de stationnement.
 * \return Le numéro de la borne de stationnement.
 */
int BorneStationnement::reqNumBorne() const {
    return m_numBorne;
}

/**
 * \brief Accesseur pour le côté de la rue où se trouve la borne de stationnement.
 * \return Le côté de la rue où se trouve la borne de stationnement.
 */
std::string BorneStationnement::reqCoteRue() const {
    return m_coteRue;
}

/**
 * \brief Crée un clone de la borne de stationnement.
 * \return Un pointeur unique vers une copie de la borne de stationnement.
 */
std::unique_ptr<Borne> BorneStationnement::clone() const {
    return std::make_unique<BorneStationnement>(*this);
}

/**
 * \brief Retourne une chaîne de caractères formatée représentant les informations de la borne de stationnement.
 * \return Une chaîne de caractères formatée représentant les informations de la borne de stationnement.
 */
std::string BorneStationnement :: reqBorneFormate() const {
        std::ostringstream oss;
        oss << "Borne de stationnement\n"
            << "----------------------------------------------\n"
            << bornesQuebec :: Borne::reqBorneFormate()
            << "Numero de la borne : " << m_numBorne << "\n"
            << "Cote de la rue : " << m_coteRue << "\n";
        return oss.str();
    }

/**
 * \brief Vérifie les invariants de la classe BorneStationnement.
 */
void BorneStationnement::verifieInvariant() const {
    INVARIANT(m_numBorne >= 1 && m_numBorne <= 9999);
    INVARIANT(util::validePointCardinal(m_coteRue));
}

}
