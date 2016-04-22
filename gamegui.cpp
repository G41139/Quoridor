#include "gamegui.h"
#include "ui_gamegui.h"
#include <QPushButton>
#include <iostream>

GameGUI::GameGUI(Game *sdo, QWidget *parent) : QWidget(parent), ui(new Ui::GameGUI)
{
    game = dynamic_cast<Game *>(sdo);
    setWindowTitle("Quoridor Game Grid");
    game->attacher(this);
    lay= new QGridLayout();
    initTable();
    rafraichir(game);
    setLayout(lay);
}

GameGUI::~GameGUI()
{
    game->detacher(this);
}

void GameGUI::rafraichir(const SujetDObservation *sdo)
{
    game = (Game *) sdo;
    Board board= game->getBoard();
    QPixmap * pix;
    QLabel *tmp= new QLabel();
    Piece *p;
     auto size=game->getBoard().getSize()*2-1;
    for (unsigned i = 0; i < size; i++) {
        icon[i].resize(size);
        for (unsigned j = 0; j < size; j++) {
             p= board.getBoard()[i][j];
            if(i%2==0 && j%2==0){
                if(p->isEmpty()){
                    std::string im = "images/Empty.png";
                    tmp= new QLabel();
                    pix =new QPixmap(im.c_str());
                    tmp->setPixmap(*pix);
                    icon[i][j]=tmp;
                }else{
                    string im;
                    switch(p->getSide()){
                    case Side::NORTH:
                        im = "images/pawn1.png";
                        break;
                    case Side::SOUTH:
                        im = "images/pawn2.png";
                        break;
                    case Side::WEST:
                        im = "images/pawn3.png";
                        break;
                    case Side::EST:
                        im = "images/pawn4.png";
                        break;
                    }
                    tmp= new QLabel();
                    pix =new QPixmap(im.c_str());
                    tmp->setPixmap(*pix);
                    icon[i][j] =tmp;
                }

            }else{
                if(p->isEmpty()){
                    std::string im = "images/EmptyWall.png";
                    tmp=new QLabel();
                    pix =new QPixmap(im.c_str());
                    tmp->setPixmap(*pix);
                    icon[i][j]=tmp;
                }else{
                    string im;
                    if(p->getAlignement()==Alignement::HORIZONTAL){
                        im = "images/wallH.png";
                    }else{
                        im = "images/WallV.png";
                    }
                    tmp= new QLabel();
                    pix =new QPixmap(im.c_str());
                    tmp->setPixmap(*pix);
                    icon[i][j] =tmp;
                }
            }
            lay->addWidget(icon[i][j], i, j);

        }
    }
}

void GameGUI::initTable()
{
    QPixmap * pix;
    QLabel *tmp= new QLabel();
    auto size= game->getBoard().getSize()*2-1;
    icon.resize(size);
    for (unsigned i = 0; i < size; i++) {
        icon[i].resize(size);
        for (unsigned j = 0; j < size; j++) {

            tmp=new QLabel();
            pix =new QPixmap("images/Empty.png");
            tmp->setPixmap(*pix);
            icon[i][j] =tmp;
            lay->addWidget(icon[i][j],i,j);


        }
    }
}
