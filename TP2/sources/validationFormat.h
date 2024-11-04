/**
 * \file validationFormat.h
 * \brief Déclaration de 3 fonctions TP1
 * \author Zied
 * \version 1.0 mise aux normes
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

#include <string>
#include <sstream>

/**
 * \brief Ces 3 fonctions permet de Valider un fichier de plusieurs BorneStationnement
 */
namespace util
{
  
    bool validePointCardinal(const std::string& p_cardinalite);
    bool valideLigneCVSBorneStationnement (const std::string& p_ligne);
    bool valideFichierBornesStationnement (std::istream& p_fluxBornesStationnement);

}


#endif /* VALIDATIONFORMAT_H */

