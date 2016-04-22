#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QWidget>
#include "observateur.h"
#include "QGridLayout"
#include "game.h"
#include <QPushButton>
#include <QLabel>
namespace Ui {
class GameGUI;
}

class GameGUI : public QWidget, public Observateur
{
    Q_OBJECT
private:
    QGridLayout * lay;
    std::vector< std::vector<QLabel *> > icon;
    Ui::GameGUI * ui;
    Game * game;
public:
    /*!
             * \brief Contructeur de le classe GameGUI qui est l'observateur graphique du plateau de jeu.
             * \param sdo Le sujet d'observation qui est le jeu.
             */
    explicit GameGUI(Game *sdo, QWidget * parent = nullptr);
    /*!
             * \brief Destructeur de l'observateur GameGUI.
             */
    ~GameGUI();
    /*!
             * \brief Méthode rafraichir permettant de recharger le plateau de jeu.
             */
    void rafraichir(const SujetDObservation * sdo);
    /*!
             * \brief méthode initTable permettant d'initialiser le tableau graphique en tableau vide.
             */
    void initTable();
};

#endif // GAMEGUI_H
