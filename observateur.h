/*! \file observateur.h
 * \brief Définition de la classe Observateur.
 */
#ifndef __OBSERVATEUR__H__
#define __OBSERVATEUR__H__

class SujetDObservation;

/*!
  * \brief Classe abstraite dont dérive tout "observateur" du modèle de
  * conception "Observateur / SujetDObservation".
  *
  * \author GoF (?)
  */
class Observateur
{
public:

    /*!
      * \brief Méthode virtuelle pure appelée par le "Sujet d'Observation"
      * lors d'une notification de changement.
      *
      * \param sdo le sujet d'observation donne son adresse par
      *            le biais de ce paramètres : utile lorsqu'un
      *            même observateur écoute plusieurs sujets
      *            d'observation
      */
    virtual void rafraichir(const SujetDObservation * sdo) = 0;

    /*!
      * \brief Destructeur.
      *
      * Implémenté uniquement pour s'assurer qu'il est bien
      * <tt>virtual</tt>.
      */
    virtual ~Observateur(){}
} ;

#endif
