/**
 * \file Borne.h
 * \brief Déclaration de la classe Borne, classe abstraite
 * \author Zied
 * \version 1.0 mise aux normes
 */

#ifndef BORNE_H
#define BORNE_H

#include "ContratException.h"
#include <memory>
#include <stdexcept>
#include <string>

/**
 * \class Borne
 * \brief Classe abstraite qui permet de gérer des Bornes
 */


namespace BorneQuebec
{

class Borne
{
public:
  // Constructeur
  Borne(int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude, double p_latitude);
  // Méthodes d'accès en lecture
  int reqIdentifiant() const;
  std::string reqIdentifiantVoiePublique() const;
  std::string reqNomTopographique() const;
  double reqLongitude() const;
  double reqLatitude() const;
  // Mutateur pour changer le nom topographique
  void asgNomTopographique(const std::string& p_nomTopographique);
  // operateur ==
  bool operator ==(const Borne& p_borne) const;
   
  // Destructeur virtuel
  virtual ~Borne ();
  // declaration methode derivee
  virtual std::unique_ptr<Borne> clone() const = 0 ;
  
  // Méthode reqBorneFormate
  virtual std::string reqBorneFormate() const ;
  
  // Methode static pour verifier si une chaine est numerique ou vide 
  static bool estNumeriqueOuVide(const std::string& p_chaine) ;
  
private:
  // invariant
  void verifieInvariant() const;
  // Objet de la classe
  int m_identifiant;
  std::string m_identifiantVoiePublique;
  std::string m_nomTopographique;
  double m_longitude;
  double m_latitude;
  
  

};
} //util namespace

#endif /* BORNE_H */

