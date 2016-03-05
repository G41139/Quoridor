#include <string>
#include "player.h"
#include <stdexcept>
using namespace std;

Player::Player(Side side)
{
    side_=side;
}

void Player::pickWall()
{
    if(nbWall_==0){
        throw new invalid_argument ("The wall stock is empty !");
    }
    nbWall_--;
}

