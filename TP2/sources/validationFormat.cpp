/**
 * \file validationFormat.cpp
 * \brief Implantation des 3 fonctions de validationFormat
 * \author Zied
 * \version 1.0 mise aux normes
 */

#include "validationFormat.h"
#include <sstream>
#include <vector>
#include <string>

using namespace std;
namespace util
{
/**
 * \brief retourne bool valider point cardinal
 * \param[in] p_cardinalite : point cardinal
 * \return bool valider point cardinal
 */ 
bool validePointCardinal(const std::string& p_cardinalite)
    {
        return p_cardinalite == "N" || p_cardinalite == "S" || 
          p_cardinalite == "E"  || p_cardinalite == "O"  || 
          p_cardinalite == "" ;
    }

/**
 * \brief retourne bool valider une ligne de borne
 * \param[in] p_ligne : une ligne l'information de borne
 * \return bool valider une ligne de borne
 */ 
bool valideLigneCVSBorneStationnement(const std::string& p_ligne) {
        istringstream stream(p_ligne);
        string token;
        vector<string> tokens;
        while (getline(stream, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() != 7) {
            return false;
        }

        if (!validePointCardinal(tokens[2])) {
            return false;
        }

        if (!tokens[3].empty()) {
            try {
                int idVoiePublique = stoi(tokens[3]);
                if (idVoiePublique <= 0) {
                    return false;
                }
            } catch (const std::exception&) {
                return false;
            }
        }

        for (int i = 0; i < tokens.size(); i++) {
            if (i != 2 && i != 3 && tokens[i].empty()) {
                return false;
            }
        }

        int longitude = stoi(tokens[5]);
        int latitude = stoi(tokens[6]);

        if (longitude != -71 || latitude != 46) {
            return false;
        }

        return true;
    }
 
/**
 * \brief retourne bool valider Fichier BornesStationnement
 * \param[in] p_fluxBornesStationnement : un flux de BornesStationnement
 * \return bool valider Fichier BornesStationnement
 */   
bool valideFichierBornesStationnement (std::istream& p_fluxBornesStationnement)
    {
    string ligne;
    getline(p_fluxBornesStationnement, ligne);
    if (ligne != "ID,NO_BORNE,COTE_RUE,ID_VOIE_PUBLIQUE,NOM_TOPOGRAPHIQUE,LONGITUDE,LATITUDE") return false;
    while (getline(p_fluxBornesStationnement, ligne)) {
        if (!valideLigneCVSBorneStationnement(ligne)) return false;
        if (ligne.empty()) break;
    }
    return true;
    }


}
