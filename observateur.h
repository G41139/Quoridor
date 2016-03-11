/*! \file observateur.h
 * \brief D�finition de la classe Observateur.
 */
#ifndef __OBSERVATEUR__H__
#define __OBSERVATEUR__H__

class SujetDObservation;

/*!
  * \brief Classe abstraite dont d�rive tout "observateur" du mod�le de
  * conception "Observateur / SujetDObservation".
  *
  * \author GoF (?)
  */
class Observateur
{
public:

    /*!
      * \brief M�thode virtuelle pure appel�e par le "Sujet d'Observation"
      * lors d'une notification de changement.
      *
      * \param sdo le sujet d'observation donne son adresse par
      *            le biais de ce param�tres : utile lorsqu'un
      *            m�me observateur �coute plusieurs sujets
      *            d'observation
      */
    virtual void rafraichir(const SujetDObservation * sdo) = 0;

    /*!
      * \brief Destructeur.
      *
      * Impl�ment� uniquement pour s'assurer qu'il est bien
      * <tt>virtual</tt>.
      */
    virtual ~Observateur(){}
} ;

#endif
