/*! \file sujetDObservation.h
 * \brief D�finition de la classe SujetDObservation.
 */
#ifndef __SUJETDOBSERVATION__H__
#define __SUJETDOBSERVATION__H__

#include <vector>

class Observateur;

/*!
  * \brief Classe dont d�rive tout "sujet d'observation" du mod�le de
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
      * \brief M�thode permettant � un observateur de s'enregistrer comme
      * �couteur du sujet d'observation.
      *
      * \param obs le candidat observateur
      */
    virtual void attacher(Observateur * obs);

    /*!
      * \brief M�thode permettant � un observateur de se retirer de la liste
      * des �couteurs patent�s du sujet d'observation.
      *
      * \param obs l'observateur d�sint�ress�
      */
    virtual void detacher(Observateur * obs);

protected :

    /*!
      * \brief Constructeur.
      *
      * Il est prot�g� pour �viter l'instanciation d'un SujetDObservation
      * non d�riv�.
      */
    SujetDObservation(){}

    /*!
      * \brief M�thode qu'un sujet d'observation effectif appelle lorsque
      * son �tat change.
      *
      * Elle parcourt la collection d'observateurs
      * enregistr�s et appelle, pour chacun d'eux, la m�thode
      * "rafraichir".
      */
    virtual void notifierChangement();

protected :
    std::vector<Observateur *> mesObservateurs;
} ;

#endif
