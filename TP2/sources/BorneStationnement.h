/**
 * \file BorneStationnement.h
 * \brief Déclaration de la classe BorneStationnement qui hérite de la classe Borne
 * \author Zied
 * \version 1.0 mise aux normes
 */

#ifndef BORNESTATIONNEMENT_H
#define BORNESTATIONNEMENT_H

#include "Borne.h"
#include <memory>
#include <iostream>
#include <string>
#include <stdexcept>

/**
 * \class BorneStationnement
 * \brief Cette classe permet de gérer des BorneStationnement. Elle hérite de Borne
 */

namespace BorneQuebec
{
  
class BorneStationnement  : public  BorneQuebec :: Borne  {

public:
  // Constructeur
  BorneStationnement(int p_identifiant, const std::string& p_identifiantVoiePublique, 
                 const std::string& p_nomTopographique, double p_longitude, 
                 double p_latitude, int p_numBorne, 
                                const std::string& p_coteRue);
  
  // Méthodes d'accès en lecture
  int reqnumBorne() const ;
  std::string reqcoteRue() const ;
  
  // méthode clone
  virtual std::unique_ptr<Borne> clone() const ;
  
  // Méthode reqBorneFormate
  virtual std::string reqBorneFormate() const ;
  
private:
  // invariant
  void verifieInvariant() const;
  // Objet de la classe
  int m_numBorne;
  std::string m_coteRue;
};

} //util namespace

#endif /* BORNESTATIONNEMENT_H */

