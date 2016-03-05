#ifndef PLAYER
#define PLAYER
#include <string>
#include "side.h"
#include "piece.h"
using namespace std;
class Player{
private:
    Pawn pawn_;
    bool winner_=false;
    int nbWall_;
    Side side_;

public:
    Player(Side side);
    inline void winGame(){
        winner_=true;
    }
    inline Side getSide(){
        return side_;
    }
    inline Pawn getPawn(){
        return pawn_;
    }
    inline int getNbWall(){
        return nbWall_;
    }
    void pickWall();

};

#endif // PLAYER

