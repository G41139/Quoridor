#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <vector>
#include <string>
using namespace std;
class Board
{
private:
    int size_;
    vector <vector<Piece*>> board_;
public:
    Board ();
    Board(int size);
    bool validatePosition(pair <int,int> position);
    string toString ();
    void initializeBoardWall();
    inline bool isEmpty(pair <int,int> position){
        return board_[position.first][position.second]==nullptr;
    }

    inline vector <vector<Piece*>> getBoard(){
        return board_;
    }
    inline int getSize(){
        return size_;
    }
    inline void placePiece(Piece *p){
        board_[p->getPosition().first][p->getPosition().second]=p;
    }
    inline void removePiece(pair <int, int> position){
        board_[position.first][position.second]=new Piece();
    }
    bool isFree (pair <int, int> position);
    void placeWall();

};

#endif // BOARD_H
