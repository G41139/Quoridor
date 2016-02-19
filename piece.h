#ifndef PIECE_H
#define PIECE_H
#include <utility>
#include <string>
using namespace std;
class Piece
{
protected:
    pair <int,int> position_;
public:
    Piece();
    //Piece(pair <int,int> position);
    inline pair<int,int> getPosition(){
        return position_;

    }
    inline void setPosition(pair <int,int> position){
        position_=position;
    }
   string toString();
};

#endif // PIECE_H
