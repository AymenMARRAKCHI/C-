/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   Supprimer_Bornes.cpp
 * Author: etudiant
 *
 * Created on 24 avril 2024, 23 h 45
 */

#include "Supprimer_Bornes.h"
#include <QMessageBox>

Supprimer_Bornes::Supprimer_Bornes ()
{
  widget.setupUi (this);
  QObject::connect(widget.Supprimer,SIGNAL(clicked()), this, SLOT(Supprime()));

}

Supprimer_Bornes::~Supprimer_Bornes () { }


QString Supprimer_Bornes::reqIdentifiantBorne () const
{
  return widget.IdBorne->text () ;
}

void Supprimer_Bornes::Supprime ()
{
  // Validation de l'identifiant de la borne
  if (widget.IdBorne->text ().isEmpty())
    {
      QString message ("L'identifiant ne peut pas être vide");
      QMessageBox::information (this, "Erreur!", message);
      return;
    }
  accept();
}