#ifndef WALL_H
#define WALL_H
#include "piece.h"
class wall : public Piece
{
private:
    bool isPlaced_=false;
public:
    wall();
    string tostring();
    inline void setWall(){
        isPlaced_=true;
    }

};

#endif // WALL_H
