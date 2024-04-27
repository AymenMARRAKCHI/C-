/**
 * \file Borne.h
 * \brief Classe de base abstraite Borne
 * \author Aymen Marrakchi
 * \version 0.1
 * \date
 */

#ifndef BORNE_H
#define BORNE_H

#include <iostream>
#include <string>
#include <memory>
#include <sstream>
namespace bornesQuebec {
  /**
   * \class Borne
   * \brief Classe de base
   */
    class Borne
    {
        private:
          int m_identifiant;
          std::string m_identifiantVoiePublique;
          std::string m_nomTopographique;
          double m_longitude;
          double m_latitude;
          void verifieInvariant () const;
          

        public:
          Borne (int p_identifiant, const std::string& p_identifiantVoiePublique, 
                 const std::string& p_nomTopographique, double p_longitude, double p_latitude);
          int reqIdentifiant () const;

          const std::string& reqIdentifiantVoiePublique () const;
          const std::string& reqNomTopographique () const;
          double reqLongitude () const;
          double reqLatitude () const;

          void asgNomTopographique (const std::string& nomTopographique);

          bool operator== (const Borne& autre) const; 

          virtual ~Borne () {}; // un destructeur 
          virtual std::unique_ptr<Borne> clone () const = 0; //virtuel pure
          virtual std::string reqBorneFormate () const; // methode retournant un objet string
          static bool estNumeriqueOuVide(const std::string& p_chaine) ;


    };
}
#endif // BORNE_H
