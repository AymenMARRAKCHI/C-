/*
 * File:   AjoutBorne.cpp
 * Author: etudiant
 *
 * Created on 23 avril 2024, 16 h 16
 */

#include "AjoutBorne.h"
#include <QMessageBox>
#include "Borne.h"
#include <iostream>

using namespace bornesQuebec;
/**
 * @brief Constructeur de AjoutBorne.
 * @param rien.
 */
AjoutBorne::AjoutBorne()
{ 
  widget.setupUi(this);
  QObject::connect(widget.ok,SIGNAL(clicked()), this, SLOT(valider()));
}

AjoutBorne::~AjoutBorne() { }
//asignation de l'identifiant de la borne
QString  AjoutBorne:: reqIdentifiantBorne() const 
{
  return widget.IdBorne->text () ;
}
//asignation de identifiantVoiePublique
QString AjoutBorne::reqIdentifiantVoiePubliqueBorne() const {
    return widget.IdVoiePublique->text ();
}
//asignation du Nom Topographique
QString AjoutBorne::reqNomTopographiqueBorne() const {
    return widget.NomTopo->text ();
}
//asignation de la longitude
QString  AjoutBorne::reqLongitudeBorne() const {
    return widget.Longitude->text ();
}
//asignation de la latitude
QString  AjoutBorne::reqLatitudeBorne() const {
    return widget.Latitude->text ();
}
//asignation de la Ville
 QString AjoutBorne :: reqVilleBorne() const 
 {
   return widget.Ville->text ();
 }
 //asignation de ArrondissementBorne
 QString AjoutBorne :: reqArrondissementBorne() const 
 {
   return widget.Arrondissement->text ();
 }
 /**
 * @brief Valide et enregistre les données saisies pour une nouvelle Borne .
 *        Vérifie si les champs sont correctement remplis et si les formats sont valides.
 *        Affiche des messages d'erreur en cas de données invalides.
 */
 void AjoutBorne::valider ()
{
  // Validation de l'identifiant de la borne
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


  
  // Validation spécifique pour la ville de Québec
  if (widget.Ville->text () == "Québec" && widget.Arrondissement->text ().isEmpty ())
    {
      QString message ("Un arrondissement doit être spécifié pour la ville de Québec");
      QMessageBox::information (this, "Erreur!", message);
      return;
    }

  // Validation des coordonnées géographiques
  bool isLongitudeValid = !widget.Longitude->text ().isEmpty () && widget.Longitude->text ().toDouble () != 0.0;
  bool isLatitudeValid = !widget.Latitude->text ().isEmpty () && widget.Latitude->text ().toDouble () != 0.0;
  if (!isLongitudeValid || !isLatitudeValid)
    {
      QString message ("Les coordonnées (longitude et latitude) doivent être valides et non nulles");
      QMessageBox::information (this, "Erreur!", message);
      return;
    }

  // Si toutes les validations sont réussies
  accept ();
 }