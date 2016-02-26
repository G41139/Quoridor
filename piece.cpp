#include "piece.h"

Wall::Wall()  {
    isPlaced_=false;
}

Wall::Wall (pair <int,int> pos){

    position_=pos;
    isPlaced_=false;
}

Pawn::Pawn() {
    isPlaced_=false;
    side_=Side::BLANK;
}

Pawn::Pawn(Side side, pair <int, int> pos) {
    position_=pos;
    side_=side;
}
string Wall::toString(){
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

