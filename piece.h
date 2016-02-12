#ifndef PIECE_H
#define PIECE_H
#include <utility>
using namespace std;
class Piece
{
private:
    pair <int,int> position_;
public:
    Piece(pair <int,int> position);
    inline pair<int,int> getPosition(){
        return position_;

    }
    inline void setPosition(pair <int,int> position){
        position_=position;
    }

};

#endif // PIECE_H
