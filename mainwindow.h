#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
             * \brief Constructeur de la classe MainWindow.
             */
    explicit MainWindow(QWidget *parent = 0);
    /*!
             * \brief Destructeur de la classe MainWindow.
             */
    ~MainWindow();
    /*!
             * \brief méthode permettant de faire le lien entre tout les boutons et leurs méthodes associés.
             */
    void enableConnection();
    /*!
             * \brief Methode permettant d'activer le bouton pour une nouvelle partie
             */
    void enableBtnGame();
    /*!
             * \brief Méthode permettant de désactiver le bouton pour une nouvelle partie
             */
    void disableBtnGame();
    /*!
             * \brief Méthode permettant d'activer tout les boutons.
             */
    void enableAllButtons();
    /*!
             * \brief Méthode permettant de désactiver tout les boutons.
             */
    void disableAllButtons();
    /*!
             * \brief Méthode permettant d'alerter un mauvais déplacement du pion.
             */
    void alertIncorrectMovement();
    /*!
             * \brief Méthoder permettant d'alerter un mauvais placement de mur.
             */
    void alertIncorrectWallPlacement();
    /*!
             * \brief Méthoder permettant d'alerter un joueur gagnant.
             * \return Le plateau de jeu.
             */
    void alertWinner();
    /*!
             * \brief Méthode permettant de mettre à jours les informtations sur le joueur courant.
             */
    void updatePlayerInfo();
    /*!
             * \brief Méthode permettant de valider les boutons de déplacements.
             */
    void checkBtnMovement();
private:
    Ui::MainWindow *ui;
    Game * game;
private slots:
    /*!
             * \brief Méthode permettant de créer une partie graphique.
             */
    void createGame();
    //void quitGame();
    /*!
             * \brief Méthode associer au bouton de mouvement haut.
             */
    void movementUp();
    /*!
             * \brief Méthode associer au bouton de mouvement bas.
             */
    void movementDown();
    /*!
             * \brief Méthode associer au bouton de mouvement gauche.
             */
    void movementLeft();
    /*!
             * \brief Méthode associer au bouton de mouvement droite.
             */
    void movementRight();
    /*!
             * \brief Méthode associer au bouton de mouvement NORD WEST.
             */
    void movementNW();
    /*!
             * \brief Méthode associer au bouton de mouvement NORD EST.
             */
    void movementNE();
    /*!
             * \brief Méthode associer au bouton de mouvement SUD EST.
             */
    void movementSE();
    /*!
             * \brief Méthode associer au bouton de mouvement SUD WEST.
             */
    void movementSW();
    /*!
             * \brief Méthode associer au bouton de placement d'un mur.
             */
    void placeWall();
};

#endif // MAINWINDOW_H
