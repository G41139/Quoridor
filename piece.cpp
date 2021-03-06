#include "piece.h"

Wall::Wall()  {
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
    switch (side){
        case Side::NORTH:
            direction_=Direction::SUD;
            break;
        case Side::SOUTH:
            direction_=Direction::NORTH;
            break;
        case Side::WEST:
            direction_=Direction::EST;
            break;
        case Side::EST:
            direction_=Direction::WEST;
            break;
        case Side::BLANK:
            direction_=Direction::NORTH;
            break;
    }
}
string Wall::toString(){
    string ch="";
    if(isPlaced_){
        ch=" # ";
    }else{
        ch=" * ";
    }
    return ch;
}

string Pawn::toString(){
    string ch="";
    if(isPlaced_){
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
                ch=" X ";
            break;
    }
    }else{
        ch=" P ";
    }
    return ch;
}

