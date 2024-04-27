/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   GestionBorne.h
 * Author: etudiant
 *
 * Created on 23 avril 2024, 21 h 49
 */

#ifndef _GESTIONBORNE_H
#define _GESTIONBORNE_H
#include "Borne.h"
#include "ui_GestionBorne.h"
#include <vector>
#include "RegistreBorne.h"
#include "Borne.h"
#include "BorneFontaine.h"

class GestionBorne : public QMainWindow
{
  Q_OBJECT
public:
  GestionBorne (QWidget *parent = 0);
  virtual ~GestionBorne ();
  private slots: 
    void dialogStationnement();
    void dialogFontaine();
    void dialogSupprimer ();

    
private:
  Ui::GestionBorne widget;
  bornesQuebec::RegistreBorne m_bornes;
  
};

#endif /* _GESTIONBORNE_H */
