#include "piece.h"
Piece::Piece() {
    pair <int,int> pos {0,0};
    position_=pos;
}

Piece::Piece(pair<int, int> position) : position_(position)
{
}

Wall::Wall() : Piece() {
    isPlaced_=false;
}

Wall::Wall (pair <int,int> pos){
    Piece();
    this->setPosition(pos);
    isPlaced_=false;
}

Pawn::Pawn() : Piece(){
    side_=Side::BLANK;
}

Pawn::Pawn(Side side, pair <int, int> pos) : Piece(pos) {
    side_=side;
}
string Piece::toString(){
        return " # ";
}

string Pawn::toString(){
    string ch="";
    switch(side_){
    case Side::NORTH:
        ch="J1";
        break;
    case Side::SOUTH:
        ch="J2";
        break;
    case Side::WEST:
        ch="J3";
        break;
    case Side::EST:
         ch="J4";
         break;
    case Side::BLANK:
        ch=" P ";
        break;
    }
    return ch;
    }
