#ifndef GAME_H
#define GAME_H
#include <vector>
#include "player.h"
#include "board.h"
using namespace std;
class Game
{
private:
    vector <Player> listPlayer_;
    Board board_;

public:
    Game();
};

#endif // GAME_H
