/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   AjoutBorne.h
 * Author: etudiant
 *
 * Created on 23 avril 2024, 22 h 06
 */

#ifndef _AJOUTBORNE_H
#define _AJOUTBORNE_H
#include <QString>

#include "ui_AjoutBorne.h"

class AjoutBorne : public QDialog
{
  Q_OBJECT
public:
  AjoutBorne ();
  virtual ~AjoutBorne ();
  QString reqIdentifiantBorne() const ;
  QString reqIdentifiantVoiePubliqueBorne() const ;
  QString reqNomTopographiqueBorne() const  ;
  QString reqLongitudeBorne() const ;
  QString reqLatitudeBorne () const ;
  QString reqVilleBorne() const ;
  QString reqArrondissementBorne() const ;
private slots : 
    void valider();
private:
  Ui::AjoutBorne widget;
};

#endif /* _AJOUTBORNE_H */
