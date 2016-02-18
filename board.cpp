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
    vector <Piece *> temp;
    vector <vector<Piece *>>temp2;
    Piece *p;
    size_=size;
    for (int i=0 ; i<=size; i++){
        for(int j=0; j<=size; j++){
            temp.push_back(p);
        }
        temp2.push_back(temp);
        temp.clear();
    }
    board_=temp2;
}
string Board::toString(){
    string ch;
    Piece *p;
    for(int i=0;i<size_; i++){
        ch=ch+"\n";
        for(int j=0 ; j<size_; j++){
            p=board_[i][j];
            ch=ch+p->toString();
        }
    }
    ch=ch+"\n";
    return ch;
}
