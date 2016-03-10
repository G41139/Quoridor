#include <iostream>
#include <stdlib.h>
#include "board.h"
#include "player.h"
#include "side.h"
#include "piece.h"
#include "game.h"
using namespace std;

int main()
{

    //Game *game=nullptr;
    //game->play();

    Game * game= new Game(2,7);
    game->play();
    return 0;

}

