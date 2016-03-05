#include <iostream>
#include "board.h"
#include "player.h"
#include "side.h"
#include "piece.h"
#include "game.h"
using namespace std;

int main()
{
    Board *board = new Board(9);
    cout << board->toString() << endl;
    return 0;

}

