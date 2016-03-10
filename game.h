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
        pair<int, int> askPositionWall();
        void removeWall(pair<int, int> pos, Alignement align);
        bool verifyAllPlayerWay(Player *p1, Player *p2);
        inline void gameOver(){
            gameOver_=true;
        }
        inline Board getBoard(){
            return board_;
        }
        bool playerHasWon(Player *p);
};

#endif // GAME

