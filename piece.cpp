#include "piece.h"

Wall::Wall()  {
    isPlaced_=false;
    alignement_=Alignement::BLANK;
}

Wall::Wall (pair <int,int> pos, Alignement alignement){
    alignement_=alignement;
    position_=pos;
    isPlaced_=true;
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
    string ch="";
    if(isPlaced_){
        ch=" * ";
    }else{
        ch=" # ";
    }
    return ch;
}

string Pawn::toString(){
    string ch="";
    switch(side_){
    case Side::NORTH:
        ch=" 1 ";
        break;
    case Side::SOUTH:
        ch=" 2 ";
        break;
    case Side::WEST:
        ch=" 3 ";
        break;
    case Side::EST:
         ch=" 4 ";
         break;
    case Side::BLANK:
        ch=" P ";
        break;
    }
    return ch;
}

