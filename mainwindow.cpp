#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QPalette>
#include <QString>
#include <gamegui.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Quoridor");
    this->enableConnection();
    this->disableAllButtons();
    game=nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::enableConnection()
{
    connect(ui->actionNew_Game, &QAction::triggered,
            this, &MainWindow::createGame);
    connect(ui->actionQuit_Game, &QAction::triggered,
            &QCoreApplication::quit);
    connect(ui->btnUP, &QPushButton::clicked,
            this, &MainWindow::movementUp);
    connect(ui->btnDown, &QPushButton::clicked,
            this, &MainWindow::movementDown);
    connect(ui->btnLeft, &QPushButton::clicked,
            this, &MainWindow::movementLeft);
    connect(ui->btnRight, &QPushButton::clicked,
            this, &MainWindow::movementRight);
    connect(ui->btnNE, &QPushButton::clicked,
            this, &MainWindow::movementNE);
    connect(ui->btnNW, &QPushButton::clicked,
            this, &MainWindow::movementNW);
    connect(ui->btnSE, &QPushButton::clicked,
            this, &MainWindow::movementSE);
    connect(ui->btnSW, &QPushButton::clicked,
            this, &MainWindow::movementSW);
    connect(ui->btnPlace, &QPushButton::clicked,
            this, &MainWindow::placeWall);
}

void MainWindow::enableBtnGame()
{
    ui->actionNew_Game->setEnabled(true);
}

void MainWindow::disableBtnGame()
{
    ui->actionNew_Game->setEnabled(false);
}

void MainWindow::enableAllButtons()
{
    ui->btnNE->setEnabled(true);
    ui->btnNW->setEnabled(true);
    ui->btnSE->setEnabled(true);
    ui->btnSW->setEnabled(true);
    ui->btnUP->setEnabled(true);
    ui->btnDown->setEnabled(true);
    ui->btnLeft->setEnabled(true);
    ui->btnRight->setEnabled(true);
    ui->btnPlace->setEnabled(true);
}

void MainWindow::disableAllButtons()
{
    ui->btnNE->setEnabled(false);
    ui->btnNW->setEnabled(false);
    ui->btnSE->setEnabled(false);
    ui->btnSW->setEnabled(false);
    ui->btnUP->setEnabled(false);
    ui->btnDown->setEnabled(false);
    ui->btnLeft->setEnabled(false);
    ui->btnRight->setEnabled(false);
    ui->btnPlace->setEnabled(false);
}

void MainWindow::alertIncorrectMovement()
{
    QMessageBox::information(this, "!!!", "The movement is impossible !");
}
void MainWindow::alertIncorrectWallPlacement()
{
    QMessageBox::information(this, "!!!", "You choose an incorrect position for the placement !");
}

void MainWindow::alertWinner()
{
    if(game->playerHasWon(game->getPlayerAt(game->getCurrentPlayer()))){
        QMessageBox::information(this, "Congratulations", "You win !");
        disableAllButtons();
    }
}

void MainWindow::updatePlayerInfo()
{
    QString playerInfo = QString::fromStdString("The player "+to_string(game->getCurrentPlayer()));
    playerInfo += " is playing";
    ui->lblPlayerInfo->setText(playerInfo);
    QPalette pal = ui->lblPlayerInfo->palette();
    switch (game->getCurrentPlayer()) {
    case 0 : pal.setColor(ui->lblPlayerInfo->backgroundRole(), Qt::blue);  break;
    case 1 : pal.setColor(ui->lblPlayerInfo->backgroundRole(), Qt::green); break;
    case 2 : pal.setColor(ui->lblPlayerInfo->backgroundRole(), Qt::yellow);break;
    case 3 : pal.setColor(ui->lblPlayerInfo->backgroundRole(), Qt::red);   break;
    default : break;
    }
    ui->lblPlayerInfo->setPalette(pal);
    ui->lblPlayerInfo->setAutoFillBackground(true);
    ui->lblPlayerInfo->show();
    Player *p=game->getListPlayer()[game->getCurrentPlayer()];
    QString nbWalls = QString::number(p->getNbWall());
    QString playerWalls = "Walls : ";
    playerWalls += nbWalls;
    ui->lblPlayerWalls->setText(playerWalls);
}

void MainWindow::checkBtnMovement()
{
    Player *p= game->getPlayerAt(game->getCurrentPlayer());
    if(game->possibleMovement(Direction::NORTH,p->getPawn()))
        ui->btnUP->setEnabled(true);
    else
        ui->btnUP->setEnabled(false);
    if(game->possibleMovement(Direction::SUD,p->getPawn()))
        ui->btnDown->setEnabled(true);
    else
        ui->btnDown->setEnabled(false);
    if(game->possibleMovement(Direction::EST,p->getPawn()))
        ui->btnRight->setEnabled(true);
    else
        ui->btnRight->setEnabled(false);
    if(game->possibleMovement(Direction::WEST,p->getPawn()))
        ui->btnLeft->setEnabled(true);
    else
        ui->btnLeft->setEnabled(false);
    if(game->possibleDiagonalMovement(Direction::NORTH_EST,p->getPawn()))
        ui->btnNE->setEnabled(true);
    else
        ui->btnNE->setEnabled(false);
    if(game->possibleDiagonalMovement(Direction::NORTH_WEST,p->getPawn()))
        ui->btnNE->setEnabled(true);
    else
        ui->btnNW->setEnabled(false);
    if(game->possibleDiagonalMovement(Direction::SUD_EST,p->getPawn()))
        ui->btnSE->setEnabled(true);
    else
        ui->btnSE->setEnabled(false);
    if(game->possibleDiagonalMovement(Direction::SUD_WEST,p->getPawn()))
        ui->btnSW->setEnabled(true);
    else
        ui->btnSW->setEnabled(false);

}
void MainWindow::createGame()
{
    ui->actionNew_Game->setDisabled(true);
    bool ok;
    unsigned nbPlayers;
    unsigned gridSideSize;
    bool setupOk = false;
    while(!setupOk) {
        nbPlayers = (unsigned)QInputDialog::getInt(this, tr("New game"),
                                                   tr("Choose number of players (2 or 4) :"), 2, 2, 4, 2, &ok);
        gridSideSize = (unsigned)QInputDialog::getInt(this, tr("New game"),
                                                      tr("Choose size of grid (5 to 19 of uneven numbers) :"), 5, 5, 19, 2, &ok);
        if (ok) {
            try {
                game= new Game (gridSideSize);
                game->setNbPlayer(nbPlayers);
                game->addPlayer(nbPlayers);
                game->setCurrentPlayer(0);
                disableBtnGame();
                this->enableAllButtons();
                updatePlayerInfo();
                setupOk = true;
            }catch (invalid_argument &e) {
                QMessageBox::information(this, "ERROR", "Number of players or the size is incorrect !");
            }
        }
    }
    GameGUI *gui= new GameGUI(game);
    gui->show();
}



void MainWindow::movementUp()
{
    if(game->getBoard().movementPossible(game->getPlayerAt(game->getCurrentPlayer())->getPawn(),Direction::NORTH)){
        game->movePawn(Direction::NORTH,game->getPlayerAt(game->getCurrentPlayer())->getPawn());
        alertWinner();
        game->nextPlayer();
        updatePlayerInfo();       
    }else{
        alertIncorrectMovement();
    }
}

void MainWindow::movementDown()
{
    if(game->getBoard().movementPossible(game->getPlayerAt(game->getCurrentPlayer())->getPawn(),Direction::SUD)){
        game->movePawn(Direction::SUD,game->getPlayerAt(game->getCurrentPlayer())->getPawn());
        alertWinner();
        game->nextPlayer();
        updatePlayerInfo();

    }else{
        alertIncorrectMovement();
    }
}

void MainWindow::movementLeft()
{
    if(game->getBoard().movementPossible(game->getPlayerAt(game->getCurrentPlayer())->getPawn(),Direction::WEST)){
        game->movePawn(Direction::WEST,game->getPlayerAt(game->getCurrentPlayer())->getPawn());
        alertWinner();
        game->nextPlayer();
        updatePlayerInfo();
    }else{
        alertIncorrectMovement();
    }
}

void MainWindow::movementRight()
{
    if(game->getBoard().movementPossible(game->getPlayerAt(game->getCurrentPlayer())->getPawn(),Direction::EST)){
        game->movePawn(Direction::EST,game->getPlayerAt(game->getCurrentPlayer())->getPawn());
        alertWinner();
        game->nextPlayer();
        updatePlayerInfo();
    }else{
        alertIncorrectMovement();
    }
}

void MainWindow::movementNW()
{
    if(game->getBoard().diagonalMovementPossible(game->getPlayerAt(game->getCurrentPlayer())->getPawn(),Direction::NORTH_WEST)){
        game->movePawn(Direction::NORTH_WEST,game->getPlayerAt(game->getCurrentPlayer())->getPawn());
        alertWinner();
        game->nextPlayer();
        updatePlayerInfo();
    }else{
        alertIncorrectMovement();
    }
}

void MainWindow::movementNE()
{
    if(game->getBoard().diagonalMovementPossible(game->getPlayerAt(game->getCurrentPlayer())->getPawn(),Direction::NORTH_EST)){
        game->movePawn(Direction::NORTH_EST,game->getPlayerAt(game->getCurrentPlayer())->getPawn());
        alertWinner();
        game->nextPlayer();
        updatePlayerInfo();
    }else{
        alertIncorrectMovement();
    }
}

void MainWindow::movementSE()
{
    if(game->getBoard().diagonalMovementPossible(game->getPlayerAt(game->getCurrentPlayer())->getPawn(),Direction::SUD_EST)){
        game->movePawn(Direction::SUD_EST,game->getPlayerAt(game->getCurrentPlayer())->getPawn());
        alertWinner();
        game->nextPlayer();
        updatePlayerInfo();
    }else{
        alertIncorrectMovement();
    }
}

void MainWindow::movementSW()
{
    if(game->getBoard().diagonalMovementPossible(game->getPlayerAt(game->getCurrentPlayer())->getPawn(),Direction::SUD_WEST)){
        game->movePawn(Direction::SUD_WEST,game->getPlayerAt(game->getCurrentPlayer())->getPawn());
        alertWinner();
        game->nextPlayer();
        updatePlayerInfo();
    }else{
        alertIncorrectMovement();
    }
}

void MainWindow::placeWall()
{
    int column = (int)ui->btnCol->value();
    int row = (int) ui->btnRow->value();
    pair <int,int> pos {row,column};
    Alignement align;
    if(ui->btnVerti->isChecked()){
        align=Alignement::VERTICAL;
    }else{
        align=Alignement::HORIZONTAL;
    }
    if(game->getBoard().placementWallPossible(pos,align)){
        game->placeWall(pos,align,game->getPlayerAt(game->getCurrentPlayer()));
        game->nextPlayer();
        updatePlayerInfo();
    }else{
        alertIncorrectWallPlacement();
    }
}
