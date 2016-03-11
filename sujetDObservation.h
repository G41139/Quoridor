/*! \file sujetDObservation.h
 * \brief Définition de la classe SujetDObservation.
 */
#ifndef __SUJETDOBSERVATION__H__
#define __SUJETDOBSERVATION__H__

#include <vector>

class Observateur;

/*!
  * \brief Classe dont dérive tout "sujet d'observation" du modèle de
  * conception "Observateur / SujetDObservation".
  *
  * \author GOF (?)
  */
class SujetDObservation
{
public :

    /*!
      * \brief Destructeur.
      */
    virtual ~SujetDObservation(){}

    /*!
      * \brief Méthode permettant à un observateur de s'enregistrer comme
      * écouteur du sujet d'observation.
      *
      * \param obs le candidat observateur
      */
    virtual void attacher(Observateur * obs);

    /*!
      * \brief Méthode permettant à un observateur de se retirer de la liste
      * des écouteurs patentés du sujet d'observation.
      *
      * \param obs l'observateur désintéressé
      */
    virtual void detacher(Observateur * obs);

protected :

    /*!
      * \brief Constructeur.
      *
      * Il est protégé pour éviter l'instanciation d'un SujetDObservation
      * non dérivé.
      */
    SujetDObservation(){}

    /*!
      * \brief Méthode qu'un sujet d'observation effectif appelle lorsque
      * son état change.
      *
      * Elle parcourt la collection d'observateurs
      * enregistrés et appelle, pour chacun d'eux, la méthode
      * "rafraichir".
      */
    virtual void notifierChangement();

protected :
    std::vector<Observateur *> mesObservateurs;
} ;

#endif
