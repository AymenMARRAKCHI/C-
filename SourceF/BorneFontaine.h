/**
 * \file BorneFontaine.h
 * \brief Classe BorneFontaine, derrivée de la classe Borne
 * \author Aymen Marrakchi
 * \version 0.1
 * \date
 */

#ifndef BORNEFONTAINE_H
#define BORNEFONTAINE_H

#include "Borne.h"
#include <string>
#include <memory>
namespace bornesQuebec {
/**
 * \class BorneFontaine
 * \brief Classe dérivée de la classe Borne
 */
class BorneFontaine : public Borne {
public:
    // Constructeur
    BorneFontaine(int p_identifiant, const std::string& p_identifiantVoiePublique,
                  const std::string& p_nomTopographique, double longitude, double p_latitude,
                  const std::string& p_ville, const std::string& p_arrondissement);
    
    // Requêteurs
    std::string reqVille(void) const;
    std::string reqArrondissement(void) const;
    
    // Méthode clone
    virtual std::unique_ptr<Borne> clone() const ;
    
    // Formate les informations de la borne fontaine
    virtual std::string reqBorneFormate(void) const ;
    
    
private:
    std::string m_ville;            // Nom de la ville où se trouve la borne fontaine
    std::string m_arrondissement;   // Nom de l'arrondissement pour la ville de Québec
    void verifieInvariant (void) const;

};
}
#endif // BORNEFONTAINE_H
