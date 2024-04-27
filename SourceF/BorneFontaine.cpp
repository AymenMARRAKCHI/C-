/**
 * \file BorneFontaine.cpp
 * \brief Implémentation de la classe BorneFontaine.
 * \author Aymen Marrakchi
 * \version 0.1
 * \date
 */

#include "BorneFontaine.h"
#include "ContratException.h"
#include <sstream>
using namespace std;
namespace bornesQuebec {

/**
 * \brief Constructeur avec paramètres.
 *        Crée un objet BorneFontaine à partir des valeurs passées en paramètres.
 * \param[in] p_identifiant Un entier représentant l'identifiant de la borne fontaine.
 * \param[in] p_identifiantVoiePublique Une chaîne de caractères représentant l'identifiant de la voie publique.
 * \param[in] p_nomTopographique Une chaîne de caractères représentant le nom topographique de la borne fontaine.
 * \param[in] p_longitude Une valeur double représentant la longitude de la borne fontaine.
 * \param[in] p_latitude Une valeur double représentant la latitude de la borne fontaine.
 * \param[in] p_ville Une chaîne de caractères représentant la ville où se trouve la borne fontaine.
 * \param[in] p_arrondissement Une chaîne de caractères représentant l'arrondissement où se trouve la borne fontaine (si la ville est "Québec").
 * \pre p_ville non vide
 * \pre Si p_ville est "Québec", p_arrondissement non vide
 * \post m_ville prend la valeur de p_ville
 * \post m_arrondissement prend la valeur de p_arrondissement
 */
BorneFontaine::BorneFontaine(int p_identifiant, const string& p_identifiantVoiePublique,
                             const string& p_nomTopographique, double p_longitude, double p_latitude,
                             const string& p_ville, const string& p_arrondissement)
  : Borne(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude),
    m_ville(p_ville), m_arrondissement(p_arrondissement)
{
  PRECONDITION(!(p_ville == "Québec" && p_arrondissement.empty())) ;
  POSTCONDITION(m_ville == p_ville);
  POSTCONDITION(m_arrondissement == p_arrondissement);
  INVARIANTS();
}

/**
 * \brief Accesseur de la ville où se trouve la borne fontaine.
 * \return La ville où se trouve la borne fontaine.
 */
string BorneFontaine::reqVille(void) const
{
  return m_ville;
}


/**
 * \brief Accesseur de l'arrondissement où se trouve la borne fontaine.
 * \return L'arrondissement où se trouve la borne fontaine.
 */
string BorneFontaine::reqArrondissement(void) const
{
  return m_arrondissement;
}

/**
 * \brief Crée un clone de la borne fontaine.
 * \return Un pointeur unique vers une copie de la borne fontaine.
 */
unique_ptr<Borne> BorneFontaine::clone() const
{
  return make_unique<BorneFontaine>(*this);
}

/**
 * \brief Retourne une chaîne de caractères formatée représentant les informations de la borne fontaine.
 * \return Une chaîne de caractères formatée représentant les informations de la borne fontaine.
 */
std::string BorneFontaine :: reqBorneFormate() const {
        std::ostringstream oss;
        oss << "Borne-fontaine\n"
            << "----------------------------------------------\n"
            << bornesQuebec :: Borne::reqBorneFormate()
            << "Ville : " << m_ville << "\n"
            << "Arrondissement : " << m_arrondissement << "\n";
        return oss.str();
    }
/**
 * \brief Vérifie les invariants de la classe BorneFontaine.
 */
void BorneFontaine::verifieInvariant(void) const
{
  INVARIANT(!m_ville.empty());
  INVARIANT(m_ville != "Québec" || !m_arrondissement.empty());
}

}
