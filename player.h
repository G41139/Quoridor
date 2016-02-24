#ifndef PLAYER
#define PLAYER
#include <string>
#include "side.h"
using namespace std;
class Player{
private:
    string name_;
    //Pawn pawn_;
    bool winner_=false;
    bool isPlaying;
    int nbWall_;
    Side side_;

public:
    Player(string name, Side side);
    bool isWinner();
    inline string getName(){
        return name_;
    }
    inline void winGame(){
        winner_=true;
    }
    inline Side getSide(){
        return side_;
    }
    //inline Pawn getPawn(){
      //  return pawn_;
    //}

};

#endif // PLAYER

