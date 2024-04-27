
/*
 * File:   AjoutBorneStationnement.cpp
 * Author: etudiant
 *
 * Created on 24 avril 2024, 20 h 01
 */

#include "AjoutBorneStationnement.h"
#include <QMessageBox>
#include "Borne.h"
#include <iostream>
#include "ValidationFormate.h"
using namespace bornesQuebec;

AjoutBorneStationnement::AjoutBorneStationnement (QWidget *parent) : QDialog(parent)
{
  widget.setupUi (this);
  QObject::connect(widget.Ok, SIGNAL(clicked()), this, SLOT(valider()));
}

AjoutBorneStationnement::~AjoutBorneStationnement () { }
//asignation de identifiant de la brorne
QString  AjoutBorneStationnement:: reqIdentifiantBorne() const 
{
  return widget.IdBorne->text () ;
}
//asignation de l'identifiant voie Publique
QString AjoutBorneStationnement::reqIdentifiantVoiePubliqueBorne() const {
    return widget.IdVoiePublique->text ();
}
//asignation du Nom Topograpghique

QString AjoutBorneStationnement::reqNomTopographiqueBorne() const {
    return widget.NomTopo->text ();
}
//asignation de  la longitude
QString  AjoutBorneStationnement::reqLongitudeBorne() const {
    return widget.Longitude->text ();
}
//asignation de la Latitude
QString  AjoutBorneStationnement::reqLatitudeBorne() const {
    return widget.Latitude->text ();
}
//asignation de NumBorneStationnement
QString AjoutBorneStationnement::reqNumBorneStationnement ()const
{
  return widget.NumStatio->text ();
}
//asignation de CoteRue
QString AjoutBorneStationnement::reqCoteRue()const
{
  return (widget.CoteRue->text ());
}

void AjoutBorneStationnement::valider ()
{
  int IdBorne = widget.IdBorne->text ().toInt();
  if (IdBorne <= 0)
    {
      QString message ("L'identifiant doit être supérieur à 0");
      QMessageBox::information (this, "Erreur!", message);
      return;
    }

  // Validation du nom topographique
  if (widget.NomTopo->text ().isEmpty ())
    {
      QString message ("Le nom topographique ne doit pas être vide");
      QMessageBox::information (this, "Erreur!", message);
      return;
    }

  // Validation de l'identifiant de la voie publique
  if (!bornesQuebec::Borne::estNumeriqueOuVide (widget.IdVoiePublique->text ().toStdString ()))
    {
      QString message ("L'identifiant de la voie publique doit être numérique ou vide");
      QMessageBox::information (this, "Erreur!", message);
      return;
    }
  int NumBorne = widget.NumStatio->text ().toInt();
  if(NumBorne <= 1 && NumBorne >= 9999 )
    {
      QString message ("Le numéro de la Borne doit être compris entre 1 et 9999");
      QMessageBox::information (this, "Erreur!", message);
      return;
    }
  if(widget.NumStatio->text ().isEmpty())
    {
      QString message ("Le numéro de la Borne ne doit être pas être vide");
      QMessageBox::information (this, "Erreur!", message);
      return;
    }
  if (!util::validePointCardinal (widget.CoteRue->text ().toStdString()))
    {
		QString message("La Cote de la rue (N, S, E, O) ");
                QMessageBox::information(this, "Erreur!", message);

		return;
    }
  accept ();
}

