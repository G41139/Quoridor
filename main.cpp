#include <iostream>
#include <stdlib.h>
#include "board.h"
#include "player.h"
#include "side.h"
#include "piece.h"
#include "game.h"
#include "observergame.h"
#include "mainwindow.h"
#include <QApplication>
using namespace std;

//int main()
//{
//    cout << "###############################################" << endl;
//    cout << "#Bienvenu sur l'application Console Quoridor! # " << endl;
//    cout << "###############################################" << endl;
//    cout << endl;
//    int size=0;
//    while(size<5 || size>19 || size%2==0){
//        cout << "Veuillez choisir maintenant, la taille du plateau de jeu ( nombre impaire entre 5 et 19 ) : ";
//        cin >> size;
//        cout << endl;
//    }
//    Game game = Game(size);
//    game.addPlayer();



//    int currentPlayer = 0; // on commence toujours par le nord

//    while(game.isOver()==false){
//        cout << "#################################" << endl;
//        cout << "#       Plateau de jeu          #" << endl;
//        cout << "#################################" << endl;
//        Board board= game.getBoard();
//        cout << game.getBoard().toString()<< endl;
//        ObserverGame obs (&board);

//        cout << "Le joueur courant est le joueur : " << currentPlayer+1 << endl;
//        Player *tempPlayer;
//        tempPlayer=game.getListPlayer()[currentPlayer];


//        cout << "Il vous reste : " << tempPlayer->getNbWall() << " mur disponible " << endl;
//        int choixAction=0;
//        while (choixAction !=1 && choixAction !=2){
//            cout << "Choisissez une action (1 pour déplacer votre pion et 2 pour placer un mur) : ";
//            cin >> choixAction;
//            cout << endl;
//        }

//        if(choixAction==1){
//            bool temp=false;
//            while(!temp){
//                char move='0';
//                while (move != 'H' && move != 'B' && move !='G' && move != 'D' && move !='J' &&
//                       move !='K' && move !='U' && move !='T'){
//                    cout << "Choisissez votre déplacement ( H = Haut, B = Bas, G= Gauche, D=droite, A=Mouvements Diagonaux ) : ";
//                    cin >> move;
//                    cout << endl;
//                }

//                switch (move){
//                case 'B':
//                    try{
//                    game.movePawn(Direction::SUD,tempPlayer->getPawn());
//                    temp=true;
//                }catch (exception &e){
//                        cerr << e.what() << endl;
//                    }
//                    break;
//                case 'H':
//                    try{
//                    game.movePawn(Direction::NORTH,tempPlayer->getPawn());
//                    temp=true;
//                }catch (exception &e){
//                        cerr << e.what() << endl;
//                    }
//                    break;
//                case 'D':
//                    try{
//                    game.movePawn(Direction::EST,tempPlayer->getPawn());
//                    temp=true;
//                }catch (exception &e){
//                        cerr << e.what() << endl;
//                    }
//                    break;
//                case 'G':
//                    try{
//                    game.movePawn(Direction::WEST,tempPlayer->getPawn());
//                    temp=true;
//                }catch (exception &e){
//                        cerr << e.what() << endl;
//                    }
//                    break;
//                case 'T':
//                    if(game.getBoard().diagonalMovementPossible(tempPlayer->getPawn(),Direction::NORTH_WEST)){
//                        game.movePawn(Direction::NORTH_WEST,tempPlayer->getPawn());
//                        temp=true;
//                    }
//                    break;
//                case 'U':
//                    if(game.getBoard().diagonalMovementPossible(tempPlayer->getPawn(),Direction::NORTH_EST)){
//                        game.movePawn(Direction::NORTH_EST,tempPlayer->getPawn());
//                        temp=true;
//                    }
//                    break;
//                case 'J':
//                    if(game.getBoard().diagonalMovementPossible(tempPlayer->getPawn(),Direction::SUD_WEST)){
//                        game.movePawn(Direction::SUD_WEST,tempPlayer->getPawn());
//                        temp=true;
//                    }
//                    break;
//                case 'K':
//                    if(game.getBoard().diagonalMovementPossible(tempPlayer->getPawn(),Direction::SUD_WEST)){
//                        game.movePawn(Direction::SUD_WEST,tempPlayer->getPawn());
//                        temp=true;
//                    }
//                    break;
//                default:break;
//                }
//            }
//        }if(choixAction==2){
//            bool ok=false;
//            bool temp=false;
//            while(!ok && !temp){
//                char align='o';
//                Alignement align_;
//                while (align !='H' && align!='V'){
//                    cout << "Choissisez l'alignement du mur (H: horizontal , V: Vertical ) : ";
//                    cin >> align;
//                }
//                if(align=='V')
//                    align_=Alignement::VERTICAL;
//                else
//                    align_=Alignement::HORIZONTAL;
//                pair <int,int> pos;
//                pos=game.askPositionWall();
//                try{
//                    game.placeWall(pos,align_,tempPlayer);
//                    temp=true;
//                }catch (exception &e){
//                    cerr << e.what() << endl;
//                    temp=false;
//                }

//                if(game.getNbPlayer()==2){
//                    if(game.verifyAllPlayerWay(game.getListPlayer()[0],game.getListPlayer()[1]))
//                        ok=true;
//                    else
//                        game.removeWall(pos,align_);
//                }else{
//                    if(game.verifyAllPlayerWay(game.getListPlayer()[0],game.getListPlayer()[1])&& game.verifyAllPlayerWay(game.getListPlayer()[2],game.getListPlayer()[3]))
//                        ok=true;
//                    else
//                        game.removeWall(pos,align_);
//                }
//            }

//            tempPlayer->pickWall();
//        }
//        if(game.playerHasWon(tempPlayer)){
//            game.gameOver();
//            cout << "Le joueur " << currentPlayer+1 << " remporte la partie !" << endl;
//        }
//        if(game.getNbPlayer()==4 && currentPlayer==3 || game.getNbPlayer()==2 && currentPlayer==1)
//            currentPlayer=0;
//        else
//            currentPlayer++;
//    }
//    game.getBoard().destroy();
//    return 0;
//}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    m.show();

    return a.exec();
}
