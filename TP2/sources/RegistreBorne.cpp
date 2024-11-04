/**
 * \file RegistreBorne.cpp
 * \brief Implantation de la classe RegistreBorne
 * \author Zied
 * \version 1.0 mise aux normes
 */

#include "RegistreBorne.h"
#include <sstream>

namespace BorneQuebec
{
  
/**
 * \brief Constructeur de la classe Borne
 * \param[in] p_nomRegistreBorne : La version du Registre
 */ 
RegistreBorne::RegistreBorne(const std::string& p_nomRegistreBorne):
    m_nomRegistreBorne(p_nomRegistreBorne)
    {
        PRECONDITION(!(p_nomRegistreBorne.empty()));
        POSTCONDITION(m_nomRegistreBorne == p_nomRegistreBorne);
        INVARIANTS();
    }

/**
 * \brief retourne le nomRegistreBorne du RegistreBorne
 * \return le nomRegistreBorne du RegistreBorne
 */ 
std::string RegistreBorne::reqnomRegistreBorne() const{return m_nomRegistreBorne;}

/**
 * \brief méthode permettant de savoir combien de bornes sont enregistrées
 */ 
size_t RegistreBorne::NombreDeBornes() const {return m_bornes.size();}

  /**
 * \brief méthode permet d’ajouter une borne au vecteur de bornes
 */ 
void RegistreBorne::ajouteBorne(const BorneQuebec::Borne& borne)
{m_bornes.push_back(borne.clone());
INVARIANTS();
}
  
/**
 * \brief Obtenir les informations formatées du registre
 * \param[in] oss une ostream dans laquelle on affiche les Bornes
 */
  std::string RegistreBorne::reqRegistreBorneFormate() const{
    std::ostringstream oss;
    oss << "Registre : " << m_nomRegistreBorne << "\n";
    for (const auto& borne : m_bornes) {
        oss << borne->reqBorneFormate() << "\n----------------------------------------------\n";
    }
    return oss.str();
}
  
  
  // Constructeur de copie

/**
 * \brief un constructeur copie
 * \param[in] p_RegistreBorne : La version du Registre
 */
RegistreBorne::RegistreBorne(const RegistreBorne& p_RegistreBorne) : m_nomRegistreBorne(p_RegistreBorne.m_nomRegistreBorne) {
    for (const auto& borne : p_RegistreBorne.m_bornes) {
        m_bornes.push_back(borne->clone());
    }
    INVARIANTS();
    }

/**
 * \brief l’opérateur d’assignation
 * \param[in] p_RegistreBorne : un RegistreBorne
 */ 
  RegistreBorne& RegistreBorne::operator=(const RegistreBorne& p_RegistreBorne) {
    if (this != &p_RegistreBorne) {
        m_nomRegistreBorne = p_RegistreBorne.m_nomRegistreBorne;
        m_bornes.clear();
        for (const auto& borne : p_RegistreBorne.m_bornes) {
            m_bornes.push_back(borne->clone());
        }
    }
    return *this;
}
  
  /**
 * \brief enlever la Premiere Ligne d'un texte 
 * \param[in] texte : un texte 
 */
  std::string RegistreBorne::enleverPremiereLigne (const std::string& texte)const {
    std::istringstream flux(texte);
    std::string ligne;
    std::string resultat;
    // Ignore la première ligne
    std::getline(flux, ligne);
    // Reconstruit la chaîne sans la première ligne
    while (std::getline(flux, ligne)) {
        resultat += ligne + "\n";
    }
    return resultat;
    }

/**
* \brief pour vérifier l'invariant de classe dans l'implantation de la théorie du contrat
*/
 void RegistreBorne :: verifieInvariant() const
{
	INVARIANT(!(m_nomRegistreBorne.empty()));
        
}
 
 } //util namespace