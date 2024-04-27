
/* 
 * File:   BorneException.h
 * Author: Aymen
 *
 * Created on 20 avril 2024, 21 h 59
 */
#ifndef BORNEEXCEPTION_H
#define BORNEEXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * \class BorneException
 * \brief Classe d'exception pour les opérations sur les bornes.
 *        Hérite de std::runtime_error.
 */

class BorneException : public std::runtime_error {
public:
    /**
     * \brief Constructeur de la classe BorneException
     * \param[in] p_raison La raison de l'exception
     */
    BorneException(const std::string& p_raison): std :: runtime_error (p_raison) {}
};

class BorneDejaPresenteException : public :: BorneException {
public :
  BorneDejaPresenteException (const std::string& p_raison): BorneException (p_raison) {}
  
};

class BorneAbsenteException : public :: BorneException {
public :
  BorneAbsenteException (const std::string& p_raison): BorneException (p_raison) {}
  
};





#endif // BORNEEXCEPTION_H


