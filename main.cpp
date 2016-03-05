#include <iostream>
#include "board.h"
#include "player.h"
#include "side.h"
#include "piece.h"
#include "game.h"
using namespace std;

int main()
{
    Board *board = new Board(9);
    Pawn *pawn= new Pawn(Side::NORTH,{0,0});

    board->placePawn(pawn,pawn->getPosition());
    board->placeWall({1,0},Alignement::HORIZONTAL);
    board->placeWall({1,4},Alignement::HORIZONTAL);
    board->placeWall({1,8},Alignement::HORIZONTAL);
    board->placeWall({1,12},Alignement::HORIZONTAL);
    board->placeWall({0,15},Alignement::VERTICAL);


    cout << board->toString() << endl;
    bool result= board->existWay(pawn->getPosition(),pawn->getSide());
    cout << result << endl;
    return 0;

}

