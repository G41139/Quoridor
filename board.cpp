    #include "board.h"
#include "piece.h"
#include <stdexcept>
#include <string>

using namespace std;
Board::Board(int size)
{
    if (size % 2==0 || size> 19 || size< 5){
        throw new invalid_argument ("The size is invalid !");
    }
    size_=size;
    auto sizeTemp=size*2-1;
    board_=vector<std::vector<Piece *> > (sizeTemp, std::vector<Piece *>(sizeTemp, nullptr));
    for (int i=0 ; i<sizeTemp; i++){
        for(int j=0; j<sizeTemp; j++){
            pair <int,int> pos {i,j};
            if(i%2==0 && j%2==0){
                Pawn *pw = new Pawn();
                board_[i][j]= pw;
            }else{
                Wall *pp = new Wall();
                board_[i][j]= pp;
            }
        }
    }
}
string Board::toString(){
    string ch;
    for(int i=0;i<size_*2-1; i++){
        ch=ch+"\n";
        for(int j=0 ; j<size_*2-1; j++){
            ch=ch+board_[i][j]->toString();
        }
    }
    ch=ch+"\n";
    return ch;
}
