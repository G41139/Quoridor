#include <iostream>
#include "board.h"
#include "player.h"
#include "side.h"
#include "piece.h"
using namespace std;

int main()
{
    int size;
    cout << "Veuillez entrez la taille du tableau : ";
    cin >> size ;
    Board board (size);
    cout << board.toString();

    pair <int,int > pos {0,4};
    Pawn *pawn= new Pawn (Side::NORTH,pos);
    board.placePawn(pawn,pawn->getPosition());

    cout << endl;

    cout << board.toString();
    Piece *test= new Pawn();
    test=board.getPiece(pos);
    cout<< test->isEmpty()<< endl;
    board.movePawn(Direction::SUD_WEST,pawn);

    pair <int,int> posTemp {0,18};
    board.placeWall(posTemp,Alignement::HORIZONTAL);

    pair <int,int> pos2 {1,5};
    board.placeWall(pos2,Alignement::VERTICAL);

    cout << endl;

    cout << board.toString();

    return 0;

}

