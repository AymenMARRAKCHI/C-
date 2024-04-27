/**
 * \file ValidationFormat.cpp
 * \brief Implémentation des méthodes utilitaires pour la classe BorneFontaine.
 * \author Aymen Marrakchi
 * \version 0.1
 * \date
 */

#include "ValidationFormate.h"
#include <sstream>
#include <vector>
#include <string>

using namespace std;

namespace util {

/**
 * \brief Vérifie si une chaîne de caractères représente un point cardinal valide.
 * \param[in] p_pointCardinal La chaîne de caractères à vérifier.
 * \return True si la chaîne représente un point cardinal valide, False sinon.
 */
bool validePointCardinal(const string& p_pointCardinal)
{
    if (p_pointCardinal == "N" || p_pointCardinal == "S" || 
        p_pointCardinal == "E" || p_pointCardinal == "O" || 
        p_pointCardinal == "" )
        return true;
    else
        return false;
}

/**
 * \brief Vérifie si une ligne de données CSV correspondant à une borne de stationnement est valide.
 * \param[in] p_ligne La ligne de données CSV à vérifier.
 * \return True si la ligne est valide, False sinon.
 */
bool valideLigneCVSBorneStationnement(const string& p_ligne) {
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
        } catch (const exception&) {
            return false;
        }
    }

    for (size_t i = 0; i < tokens.size(); ++i) {
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
 * \brief Vérifie si un flux contenant des données de bornes de stationnement est valide.
 * \param[in] p_fluxBornesStationnement Le flux contenant les données de bornes de stationnement.
 * \return True si les données sont valides, False sinon.
 */
bool valideFichierBornesStationnement(istream& p_fluxBornesStationnement) {
    string ligne;
    getline(p_fluxBornesStationnement, ligne);
    if (ligne != "identifiant, identifiantVoiePublique, nomTopographique, longitude, latitude") return false;
    while (getline(p_fluxBornesStationnement, ligne)) {
        if (ligne.empty()) break;
        if (!valideLigneCVSBorneStationnement(ligne)) return false;
    }

    return true;
}

/**
 * \brief Convertit une chaîne de caractères en double.
 * \param[in] p_chaine La chaîne de caractères à convertir.
 * \return La valeur double résultante.
 * \throw std::invalid_argument Si la chaîne ne peut pas être convertie en double.
 * \throw std::out_of_range Si le double converti dépasse la plage de valeurs.
 */
double convertirChaineEnDouble(const string& p_chaine)
{
    try
    {
        // Tente de convertir la chaîne en double
        return std::stod(p_chaine);
    }
    catch (const std::invalid_argument& e)
    {
        // Gère le cas où la chaîne ne peut pas être convertie en double
        throw std::invalid_argument("Argument invalide : Impossible de convertir la chaîne en double.");
    }
    catch (const std::out_of_range& e)
    {
        // Gère le cas où le double converti dépasse la plage de valeurs
        throw std::out_of_range("Hors de portée : La chaîne représente un nombre en dehors de la plage des valeurs représentables par un double.");
    }
}

} // namespace util
