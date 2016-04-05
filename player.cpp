#include <string>
#include "player.h"
#include <stdexcept>
using namespace std;

Player::Player(Side side , int nbWall)
{
    nbWall_=nbWall;
    side_=side;
    pawn_= new Pawn();
    pawn_->setSide(side);
}

void Player::pickWall()
{
    if(nbWall_==0){
        throw new invalid_argument ("The wall stock is empty !");
    }
    nbWall_-=1;
}

void Player::initializePawnPlayer(int size)
{
    int sizeBoard=2*size-1;
    pair <int, int > pos;
    switch (side_){
        case Side::NORTH:
            pawn_->setSide(side_);
            pos.first=0;
            pos.second=sizeBoard/2;
            pawn_->setPosition(pos);

            break;
       case Side::SOUTH:
           pos.first=sizeBoard-1;
           pos.second=sizeBoard/2;
           pawn_->setPosition(pos);
           pawn_->setSide(side_);
           break;
       case Side::WEST:
            pos.first=sizeBoard/2;
            pos.second=0;
            pawn_->setPosition(pos);
            pawn_->setSide(side_);
            break;
       case Side::EST:
            pos.first=sizeBoard/2;
            pos.second=sizeBoard-1;
            pawn_->setPosition(pos);
            pawn_->setSide(side_);
            break;
    }
}

