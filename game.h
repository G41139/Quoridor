#ifndef GAME
#define GAME
#include "player.h"
#include "board.h"
#include "string"
using namespace std;

class Game{
    private :
        bool gameOver_=false;
        int nbPlayer_;
        Board board_;
        vector <Player*> listPlayer_;

    public:
        Game();
        Game(int nbPlayer, int size);
        void play();
        inline void gameOver(){
            gameOver_=true;
        }
        inline Board getBoard(){
            return board_;
        }
};

#endif // GAME

