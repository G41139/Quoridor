#ifndef OBSERVERGAME_H
#define OBSERVERGAME_H
#include "observateur.h"
#include "game.h"
/*!
 * \class ObserverGame.
 * \brief Class héritant de la classe Observateur, celle-ci permet de notifier un changement lors de la modification du plateu de jeu.
 * \author Kasay-Temsamani.
 * \version 1.0
 * \date 2016
 */
class ObserverGame : public Observateur
{
private:

    Board *board;

public:
    /*!
         * \brief Constructeur de la classe ObservGame qui crée un observateur du tableu de jeu.
         * \param le sujet d'observation qui sera observé
         */
    ObserverGame(SujetDObservation *sujet);
    /*!
         * \brief La méthode d'indiquer à l'observateur qu'il y a eu des changements chez le sujet d'observation
         * \param le sujet d'observation qui sera observé
         */
    void rafraichir (const SujetDObservation *sdo) override;
    /*!
         * \brief Destructeur de la classe ObserverGame
         */
    ~ObserverGame();
};

#endif // OBSERVERGAME_H
