/**
 * \file RegistreBorne.h
 * \brief Déclaration de la classe RegistreBorne
 * \author Aymen Marrakchi
 * \version 3.0 mise aux normes
 */

#ifndef REGISTREBORNE_H
#define REGISTREBORNE_H

#include "Borne.h"
#include <vector>
#include <memory>
#include <string>

/**
 * \class RegistreBorne
 * \brief Cette classe permet de gérer des BorneFontaine et BorneStationnement
 */

namespace bornesQuebec
{
  
class RegistreBorne
{
public:
  // Constructeur
  RegistreBorne(const std::string& p_nomRegistreBorne);
  // Accesseur
  std::string reqnomRegistreBorne() const;

  // Nombre de bornes enregistrées
  size_t NombreDeBornes() const;

  // Ajouter une borne
  void ajouteBorne(const bornesQuebec::Borne& p_borne);
  void supprimeBorne (int p_identifiant);
  // Obtenir les informations formatées du registre
  std::string reqRegistreBorneFormate() const;
  
  
  // Constructeur de copie
  RegistreBorne(const RegistreBorne& p_RegistreBorne);

  // Opérateur d'assignation
  RegistreBorne& operator=(const RegistreBorne& p_RegistreBorne);
  
  // enlever la Premiere Ligne d'un texte 
  //utilisation uniquement pour le formatage demander dans le programe minimaliste
  std::string enleverPremiereLigne(const std::string& texte) const ;
  
  
  
private:
  // invariant
  void verifieInvariant() const;
  // Objet de la classe
  std::string m_nomRegistreBorne;
  std::vector<std::unique_ptr<bornesQuebec::Borne>> m_bornes;


};

} //util namespace

#endif /* REGISTREBORNE_H */

