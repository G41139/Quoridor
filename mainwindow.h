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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void enableConnection();
    void enableBtnGame();
    void disableBtnGame();
    void enableAllButtons();
    void disableAllButtons();
    void alertIncorrectMovement();
    void alertIncorrectWallPlacement();
    void alertWinner();
    void updatePlayerInfo();
    void checkBtnMovement();
private:
    Ui::MainWindow *ui;
    Game * game;
private slots:
    void createGame();
    //void quitGame();
    void movementUp();
    void movementDown();
    void movementLeft();
    void movementRight();
    void movementNW();
    void movementNE();
    void movementSE();
    void movementSW();
    void placeWall();
};

#endif // MAINWINDOW_H
