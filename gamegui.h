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

    explicit GameGUI(Game *sdo, QWidget * parent = nullptr);
    ~GameGUI();

    void rafraichir(const SujetDObservation * sdo);
    void initTable();
};

#endif // GAMEGUI_H
