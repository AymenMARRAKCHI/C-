/**
 * \file BorneStationnement.cpp
 * \brief Classe BorneStationnement, derrivé de la classe de base Borne
 * \author Aymen Marrakchi
 * \version 0.1
 * \date
 */

#ifndef BORNESTATIONNEMENT_H
#define BORNESTATIONNEMENT_H

#include "Borne.h" // Assurez-vous que ce chemin est correct ou ajustez selon votre structure de projet
#include <string>
#include <memory>
namespace bornesQuebec 
{
  /**
 * \class BorneStationnement
 * \brief Classe dérivée de la classe Borne
 */
       class BorneStationnement : public Borne 
        {
        public:
            // Constructeur
            BorneStationnement (int p_identifiant, const std::string& p_identifiantVoiePublique,
                                const std::string& p_nomTopographique, double p_longitude, double p_latitude,
                                int p_numBorne, const std::string& p_coteRue);

            // Accesseurs
            int reqNumBorne(void) const;
            std::string reqCoteRue(void) const;

            // Méthodes spécifiques
            virtual std::unique_ptr<Borne> clone() const ;
            virtual std::string reqBorneFormate(void) const;

        private:
            // Attributs spécifiques
            int m_numBorne; // Le numéro de la borne
            std::string m_coteRue; // Le côté de la rue (point cardinal)

            // Méthode de validation
            void verifieInvariant (void) const;

        };
}
#endif // BORNESTATIONNEMENT_H
