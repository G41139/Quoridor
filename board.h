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
    bool checkLeftArm(pair <int,int> pos, Direction direction); // Renvoi true si il y a un mur à gauche
    bool checkFrontWall(pair <int,int> pos,Direction direction); // Renvoi true si il y a un mur en face
    void placeWall(pair <int,int> pos, Alignement alignement);
    void placePawn(Pawn *Pawn, pair <int,int> pos);
    void movePawn(Direction direction, Pawn *pawn);
    void rotatePawn(Direction *direction, int *cpt, bool leftRotation);
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
