
/*
 * File:   GestionBorne.cpp
 * Author: Aymen Marrakchi
 *
 * Created on 23 avril 2024
 */

#include "GestionBorne.h"
#include "Supprimer_Bornes.h"
#include "Borne.h"
#include "BorneFontaine.h"
#include "BorneException.h"
#include "BorneStationnement.h"
#include "AjoutBorne.h"
#include "RegistreBorne.h"
#include <vector>
#include <qt5/QtWidgets/qmessagebox.h>
#include <QMessageBox>
#include "AjoutBorneStationnement.h"
#include "Supprimer_Bornes.h"

using namespace std;
// Ouverture d'une interface principale qui gère les bornes
GestionBorne::GestionBorne (QWidget *parent) : QMainWindow(parent), m_bornes("Borne de l'agglomération de la ville de Québec \n"
"----------------------------------------------")
{ widget.setupUi (this);
}
// Un destructuer de l'objet
GestionBorne::~GestionBorne () { }
/**
 * @brief Ouvre la fenêtre pour ajouter une Borne Fontaine.
 *        Permet de saisir les informations d'une nouvelle BorneFontaine  et de l'ajouter au registre .
 */
void GestionBorne:: dialogFontaine()
{
  AjoutBorne BorneF;
  if (BorneF.exec())
    {
      try
        {
          // Créer une nouvelle borne avec les informations récupérées de l'interface
          bornesQuebec::BorneFontaine bf(BorneF.reqIdentifiantBorne ().toInt (),
                                                     BorneF.reqIdentifiantVoiePubliqueBorne ().toStdString (),
                                                     BorneF.reqNomTopographiqueBorne ().toStdString (),
                                                     BorneF.reqLongitudeBorne ().toDouble (),
                                                     BorneF.reqLatitudeBorne ().toDouble (),
                                                     BorneF.reqVilleBorne ().toStdString (),
                                                     BorneF.reqArrondissementBorne ().toStdString ());

          // Ajouter la nouvelle borne au vecteur de bornes
          m_bornes.ajouteBorne(bf);
        }
      catch (BorneDejaPresenteException &e)
        {
          QString message = "La borne est déjà présente dans le registre \n";
          message.append (e.what ());
          QMessageBox::warning (this, "Borne déjà présente!", message);
        }
      // Le second catch est supprimé comme vous l'avez demandé

      // Mettre à jour l'affichage ou le log des bornes (si vous avez une interface ou un mécanisme pour cela)
      // Ceci remplace le reqAnnuaireFormate() dans votre exemple
      // Par exemple, vous pourriez avoir quelque chose comme ça:
      widget.affichage->setText (m_bornes.reqRegistreBorneFormate ().c_str ());
    }
}


/**
 * @brief Ouvre la fenêtre pour ajouter une Borne Fontaine.
 *        Permet de saisir les informations d'une nouvelle BorneStationnement   et de l'ajouter au registre .
 */
void GestionBorne :: dialogStationnement()
{
  AjoutBorneStationnement Stationnement;
  if (Stationnement.exec())
    {
      try
        {
          // Créer une nouvelle borne avec les informations récupérées de l'interface
          bornesQuebec::BorneStationnement bs(Stationnement.reqIdentifiantBorne ().toInt (),
                                                     Stationnement.reqIdentifiantVoiePubliqueBorne ().toStdString (),
                                                     Stationnement.reqNomTopographiqueBorne ().toStdString(),
                                                     Stationnement.reqLongitudeBorne ().toDouble (),
                                                     Stationnement.reqLatitudeBorne ().toDouble (),
                                                     Stationnement.reqNumBorneStationnement ().toInt (),
                                                     Stationnement.reqCoteRue ().toStdString() );

          // Ajouter la nouvelle borne au vecteur de bornes
          m_bornes.ajouteBorne(bs);
        }
      catch (BorneDejaPresenteException &e)
        {
          QString message = "La borne est déjà présente dans le registre \n";
          message.append (e.what ());
          QMessageBox::warning (this, "Borne déjà présente!", message);
        }
      // Le second catch est supprimé comme vous l'avez demandé

      // Mettre à jour l'affichage ou le log des bornes (si vous avez une interface ou un mécanisme pour cela)
      // Ceci remplace le reqAnnuaireFormate() dans votre exemple
      // Par exemple, vous pourriez avoir quelque chose comme ça:
      widget.affichage->setText (m_bornes.reqRegistreBorneFormate ().c_str ());
    }
}
/**
 * @brief Ouvre la fenêtre pour supprimer une Borne .
 *         Permet de saisir les informations d'une Borne et de la supprimer du registre si elle y existe..
 */
void GestionBorne::dialogSupprimer ()
{
  Supprimer_Bornes B;
  if (B.exec ())
    {
      try
        {
          m_bornes.supprimeBorne (B.reqIdentifiantBorne ().toInt ());
        }
      catch (BorneAbsenteException &e)
        {
          // Correction du message pour correspondre à l'exception capturée
          QString message = "Erreur, la Borne n'existe pas dans l'annuaire !\n";
          message.append (e.what ());
          QMessageBox::warning (this, "Borne absente!", message);
        }
      // Mettre à jour l'affichage après une tentative de suppression
      widget.affichage->setText (m_bornes.reqRegistreBorneFormate ().c_str ());
    }
}
