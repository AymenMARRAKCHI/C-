/* 
 * File:   AjoutBorneStationnement.h
 * Author: etudiant
 *
 * Created on 24 avril 2024, 20 h 01
 */

#ifndef _AJOUTBORNESTATIONNEMENT_H
#define _AJOUTBORNESTATIONNEMENT_H

#include "ui_AjoutBorneStationnement.h"

class AjoutBorneStationnement : public QDialog
{
  Q_OBJECT
public:
  AjoutBorneStationnement (QWidget *parent = 0);
  virtual ~AjoutBorneStationnement ();
  
  // Accesseurs
  QString reqIdentifiantBorne() const ;
  QString reqIdentifiantVoiePubliqueBorne() const ;
  QString reqNomTopographiqueBorne() const  ;
  QString reqLongitudeBorne() const ;
  QString reqLatitudeBorne () const ;
  QString reqNumBorneStationnement ()const;
  QString reqCoteRue()const;
  private slots : 
    void valider();
private:
  Ui::AjoutBorneStationnement widget;
};

#endif /* _AJOUTBORNESTATIONNEMENT_H */


