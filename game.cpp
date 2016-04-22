#include "board.h"
#include "game.h"
#include <iostream>
#include <stdexcept>
#include <observergame.h>


void Game::addPlayer(int nb)
{
    nbPlayer_=0;
    // Initialisation des Joueurs et des pions
    Player *p1,*p2;
    p1= new Player(Side::NORTH,board_.getSize()+1);
    p1->initializePawnPlayer(board_.getSize());
    Pawn *pawn1= new Pawn(p1->getSide(),p1->getPawn()->getPosition());
    board_.placePawn(pawn1,pawn1->getPosition());
    p2= new Player(Side::SOUTH,board_.getSize()+1);
    p2->initializePawnPlayer(board_.getSize());
    Pawn *pawn2 = new Pawn(p2->getSide(),p2->getPawn()->getPosition());
    board_.placePawn(pawn2,pawn2->getPosition());
    listPlayer_.push_back(p1);
    listPlayer_.push_back(p2);
    Player *p3, *p4;
    if(nbPlayer_==4){
        p3= new Player(Side::WEST,(board_.getSize()+1)/2);
        p3->initializePawnPlayer(board_.getSize());
        Pawn *pawn3= new Pawn(p3->getSide(),p3->getPawn()->getPosition());
        board_.placePawn(pawn3,pawn3->getPosition());
        p4 = new Player(Side::EST,(board_.getSize()+1)/2);
        p4->initializePawnPlayer(board_.getSize());
        Pawn *pawn4 =  new Pawn(p4->getSide(),p4->getPawn()->getPosition());
        board_.placePawn(pawn4,pawn4->getPosition());
        listPlayer_.push_back(p3);
        listPlayer_.push_back(p4);
        p1->setNbWall((board_.getSize()+1)/2);
        p2->setNbWall((board_.getSize()+1)/2);
    }
    // Fin initialisation des joueurs et des pions
    nbPlayer_=listPlayer_.size();
    notifierChangement();
}

Game::Game( int size) : board_(Board(size)), currentPlayer(0)
{
}



pair <int,int> Game::askPositionWall()
{
    cout << "Choisissez la position à partir de laquel votre mur sera placé : " << endl;
    int row=-1;
    while (row <0 || row>board_.getSize()*2-2){
        cout << "Quel est le numéro de la ligne ( en partant de 0 ) : ";
        cin >> row ;
    }
    int column=-1;
    while (column<0 || column>board_.getSize()*2-2){
        cout << "Qul est le numéro de la colonne ( en partant de 0 ) : ";
        cin >> column;
    }
    pair <int,int> pos;
    pos.first=row;
    pos.second=column;
    return pos;
}

void Game::removeWall(pair <int,int> pos, Alignement align)
{
    board_.removeWall(pos,align);
    notifierChangement();
}

bool Game::verifyAllPlayerWay(Player *p1, Player *p2)
{
    bool result1,result2;
    result1=board_.existWay(p1->getPawn()->getPosition(),p1->getPawn()->getSide());
    result2=board_.existWay(p2->getPawn()->getPosition(),p2->getPawn()->getSide());
    return result1 && result2;
}

bool Game::playerHasWon(Player *p)
{
    bool win=false;
    int trueSize=board_.getSize()*2-1;
    switch (p->getSide()){
    case Side::NORTH:
        if(p->getPawn()->getPosition().first==trueSize-1)
            win=true;
        break;
    case Side::SOUTH:
        if(p->getPawn()->getPosition().first==0)
            win=true;
        break;
    case Side::WEST:
        if(p->getPawn()->getPosition().second==trueSize-1)
            win=true;
        break;
    case Side::EST:
        if(p->getPawn()->getPosition().second==0)
            win=true;
        break;
    default:
        break;
    }
    return win;
}

void Game::movePawn(Direction direction, Pawn *pawn)
{
    switch (direction){
    case Direction::SUD:
        board_.movePawn(Direction::SUD,pawn);
        break;
    case Direction::NORTH:
        board_.movePawn(Direction::NORTH,pawn);
        break;
    case Direction::EST:
        board_.movePawn(Direction::EST,pawn);
        break;
    case Direction::WEST:
        board_.movePawn(Direction::WEST,pawn);
        break;
    case Direction::NORTH_EST:
        board_.movePawn(Direction::NORTH_EST,pawn);
        break;
    case Direction::NORTH_WEST:
        board_.movePawn(Direction::NORTH_WEST,pawn);
        break;
    case Direction::SUD_EST:
        board_.movePawn(Direction::SUD_EST,pawn);
        break;
    case Direction::SUD_WEST:
        board_.movePawn(Direction::SUD_WEST,pawn);
        break;
    default:break;

    }
    notifierChangement();
}


void Game::placeWall(pair<int, int> pos, Alignement align, Player *player)
{
        board_.placeWall(pos,align);
        player->pickWall();
        notifierChangement();
}

void Game::nextPlayer()
{
    if(this->getNbPlayer()==4 && currentPlayer==3 || this->getNbPlayer()==2 && currentPlayer==1)
                currentPlayer=0;
            else
        currentPlayer++;
}

bool Game::possibleMovement(Direction d, Pawn *p)
{
    return board_.movementPossible(p,d);
}

bool Game::possibleDiagonalMovement(Direction d, Pawn *p)
{
    return board_.diagonalMovementPossible(p, d);
}




