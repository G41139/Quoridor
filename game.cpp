#include "board.h"
#include "game.h"
#include <iostream>


void Game::addPlayer(Player *p1, Player *p2)
{
    listPlayer_.push_back(p1);
    listPlayer_.push_back(p2);
}

Game::Game(int nbPlayer, int size) : board_(Board(size))
{
    nbPlayer_=nbPlayer;
}

void Game::play()
{



    cout << "###############################################" << endl;
    cout << "#Bienvenu sur l'application Console Quoridor! # " << endl;
    cout << "###############################################" << endl;
    cout << endl;

    Game::printInstruction();
    int nbPlayer=0;
    while(nbPlayer != 2 && nbPlayer !=4){
        cout << "Veuillez choisir le nombre de joueur ( 2 ou 4 ) : ";
        cin >> nbPlayer;
        cout << endl;
    }

    int size=0;
    while(size<5 || size>19 || size%2==0){
    cout << "Veuillez choisir maintenant, la taille du plateau de jeu ( nombre impaire entre 5 et 19 ) : ";
    cin >> size;
    cout << endl;
    }
    Game game = Game(nbPlayer,size);
    Board board = game.getBoard();
    // Initialisation des Joueurs et des pions
    Player *p1,*p2;
    p1= new Player(Side::NORTH);
    p1->initializePawnPlayer(game.getBoard().getSize());
    Pawn *pawn1= new Pawn(p1->getSide(),p1->getPawn()->getPosition());
    board.placePawn(pawn1,pawn1->getPosition());
    p2= new Player(Side::SOUTH);
    p2->initializePawnPlayer(game.getBoard().getSize());
    Pawn *pawn2 = new Pawn(p2->getSide(),p2->getPawn()->getPosition());
    board.placePawn(pawn2,pawn2->getPosition());
    game.addPlayer(p1,p2);
    if(nbPlayer==4){
        Player *p3= new Player(Side::WEST);
        p3->initializePawnPlayer(game.getBoard().getSize());
        Pawn *pawn3= new Pawn(p3->getSide(),p3->getPawn()->getPosition());
        board.placePawn(pawn3,pawn3->getPosition());
        Player *p4 = new Player(Side::EST);
        p4->initializePawnPlayer(game.getBoard().getSize());
        Pawn *pawn4 =  new Pawn(p4->getSide(),p4->getPawn()->getPosition());
        board.placePawn(pawn4,pawn4->getPosition());
        game.addPlayer(p3,p4);
    }
    // Fin initialisation des joueurs et des pions

    int currentPlayer = 0; // on commence toujours par le nord

    while(!game.gameOver_){
        cout << "#################################" << endl;
        cout << "#       Plateau de jeu          #" << endl;
        cout << "#################################" << endl;
        cout << board.toString() << endl;
        cout << "Le joueur courant est le joueur : " << currentPlayer+1 << endl;

        int choixAction=0;
        while (choixAction !=1 && choixAction !=2){
            cout << "Choisissez une action (1 pour déplacer votre pion et 2 pour placer un mur) : ";
            cin >> choixAction;
            cout << endl;
        }

        if(choixAction==1){

            char move='0';
            while (move != 'H' && move != 'B' && move !='G' && move != 'D'){
                cout << "Choisissez votre déplacement ( H = Haut, B = Bas, G= Gauche, D=droite) : ";
                cin >> move;
                cout << endl;
            }
            switch (move){
                case 'B':
                    try{
                    board.movePawn(Direction::SUD,pawn1);
                    }catch (exception e){
                        cerr << e.what() << endl;
                    }
                    break;
                case 'H':
                    try{
                    board.movePawn(Direction::NORTH,pawn1);
                    }catch (exception e){
                        cerr << e.what() << endl;
                    }
                    break;
                case 'D':
                    try{
                    board.movePawn(Direction::EST,pawn1);
                    }catch (exception e){
                        cerr << e.what() << endl;
                    }
                    break;
                case 'G':
                    try{
                        board.movePawn(Direction::WEST,pawn1);
                    }catch (exception e){
                        cerr << e.what() << endl;
                    }
                    break;
            }
        }

    }

}

void Game::printInstruction()
{
    cout << "################################################################################" << endl;
    cout << "#                          Instruction du jeu                                  #" << endl;
    cout << "#                          -------------------                                 #" << endl;
    cout << "# Les <P> représentent des cases pions et <*> représentent des murs où un mur  #" << endl;
    cout << "#  peut-être placé, et les <#> représentent un mur placé.                      #" << endl;
    cout << "#                                                                              #" << endl;
    cout << "#  Les cases <1> <2> <3> <4> représentent respectivement le joueur 1,2 ,etc... #" << endl;
    cout << "# Pour gagner, c'est simple il suffit que votre pion arrive sur le bord de     #" << endl;
    cout << "# l'autre côté du plateau de jeu.                                              #" << endl;
    cout << "#                                                                              #" << endl;
    cout << "# A chaque tour de jeu, il vous sera demander de soit déplacer un pion ou de   #" << endl;
    cout << "# poser un mur (si il vous en reste dans votre stock de mur)                   #" << endl;
    cout << "#                                                                              #" << endl;
    cout << "################################################################################" << endl;

}



