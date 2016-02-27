#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <vector>
#include <string>
#include "direction.h"
using namespace std;
class Board
{
private:
    int size_;
    vector <vector<Piece*>> board_;
public:
    Board ();
    Board(int size);
    string toString ();
    void placeWall(pair <int,int> pos, Alignement alignement);
    void placePawn(Pawn *Pawn, pair <int,int> pos);
    void movePawn(Direction direction, Pawn *pawn);
    bool checkWall(pair <int,int> pos);
    inline vector <vector<Piece*>> getBoard(){
        return board_;
    }
    inline int getSize(){
        return size_;
    }
    inline bool isFree (pair <int, int> position){
        return !(board_[position.first][position.second]->isEmpty());
    }
    inline Piece* getPiece(pair <int,int> pos){
        return board_[pos.first][pos.second];
    }



};

#endif // BOARD_H
