/**
 * \file RegistreBorne.cpp
 * \brief Implantation de la classe RegistreBorne
 * \author Aymen Marrakchi
 * \version 1.0 mise aux normes
 */

#include "RegistreBorne.h"
#include "ContratException.h"
#include "Borne.h"
#include <sstream>
#include <algorithm>
#include "BorneException.h"

namespace bornesQuebec
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
void RegistreBorne::ajouteBorne(const bornesQuebec::Borne& p_borne)
{for (const auto& borne : m_bornes) {
        if (*borne == p_borne) {
            throw BorneDejaPresenteException(p_borne.reqBorneFormate());
        }
    }
    m_bornes.push_back(p_borne.clone());
    INVARIANTS();
  }

 void RegistreBorne::supprimeBorne(int p_identifiant) {
    bool trouve = true; // Initialise à true pour entrer dans la boucle
    auto iter = m_bornes.begin();
    while (iter !=m_bornes.end ()) {
        if ((*iter)-> reqIdentifiant()== p_identifiant) {
           iter = m_bornes.erase (iter);
           trouve = true;
        } else {iter ++ ;}
        
    }
    if(!trouve)
      {
        throw BorneAbsenteException("La Borne spécifiée n'est pas dans le registre");
      }

    INVARIANTS(); // Assurez-vous que l'état du vecteur reste valide
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