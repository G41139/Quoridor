#ifndef GAME
#define GAME
#include "player.h"
#include "board.h"
#include "string"
using namespace std;

class Game{
    private :
        int nbPlayer_;
        Board board_;
        vector <Player*> listPlayer_;

    public:
        bool gameOver_=false;
        void addPlayer(Player *p1, Player *p2);
        Game(int nbPlayer, int size);
        void play();
        void printInstruction();
        void initializeGame();
        inline void gameOver(){
            gameOver_=true;
        }
        inline Board getBoard(){
            return board_;
        }
};

#endif // GAME

