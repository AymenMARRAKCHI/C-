/**
 * \file BorneFontaine.h
 * \brief Déclaration de la classe BorneFontaine qui hérite de la classe Borne
 * \author Zied
 * \version 1.0 mise aux normes
 */

#ifndef BORNEFONTAINE_H
#define BORNEFONTAINE_H

#include "Borne.h"
#include <memory>
#include <iostream>
#include <string>
#include <stdexcept>

/**
 * \class BorneFontaine
 * \brief Cette classe permet de gérer des BorneFontaine. Elle hérite de Borne
 */

namespace BorneQuebec
{
  
class BorneFontaine : public  BorneQuebec :: Borne  {

public:
  // Constructeur
  BorneFontaine(int p_identifiant, const std::string& p_identifiantVoiePublique, 
                 const std::string& p_nomTopographique, double p_longitude, 
                 double p_latitude, const std::string& p_ville, 
                                const std::string& p_arrondissement);
  
  // Méthodes d'accès en lecture
  std::string reqVille() const ;
  std::string reqArrondissement() const ;
  
  // clone 
  virtual std::unique_ptr<Borne> clone() const ;
  
  // Méthode reqBorneFormate
  virtual std::string reqBorneFormate() const ;
  
private:
  // invariant
  void verifieInvariant() const;
  // Objet de la classe
  std::string m_ville;
  std::string m_arrondissement;

};

} //util namespace
#endif /* BORNEFONTAINE_H */

