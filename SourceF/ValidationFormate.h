/**
 * \file ValidationFormate.h
 * \brief  Déclaration  des methodes utils pour La classe BorneFontaine
 * \author Aymen Marrakchi
 * \version 0.1
 * \date
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H
#include <string>
#include <sstream>
namespace util
{
  
    bool validePointCardinal(const std::string& p_pointCardinal);
    bool valideLigneCVSBorneStationnement (const std::string& p_ligne);
    bool valideFichierBornesStationnement (std::istream& p_fluxBornesStationnement);
    
    double convertirChaineEnDouble (const std::string& p_chaine);
    
}

#endif /* VALIDATIONFORMAT_H */