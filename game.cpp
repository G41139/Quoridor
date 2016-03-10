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
    p1= new Player(Side::NORTH,board_.getSize()+1);
    p1->initializePawnPlayer(board_.getSize());
    Pawn *pawn1= new Pawn(p1->getSide(),p1->getPawn()->getPosition());
    board_.placePawn(pawn1,pawn1->getPosition());
    p2= new Player(Side::SOUTH,board_.getSize()+1);
    p2->initializePawnPlayer(board_.getSize());
    Pawn *pawn2 = new Pawn(p2->getSide(),p2->getPawn()->getPosition());
    board_.placePawn(pawn2,pawn2->getPosition());
    game.addPlayer(p1,p2);
    Player *p3, *p4;
    if(nbPlayer==4){
        p3= new Player(Side::WEST,(board_.getSize()+1)/2);
        p3->initializePawnPlayer(board_.getSize());
        Pawn *pawn3= new Pawn(p3->getSide(),p3->getPawn()->getPosition());
        board_.placePawn(pawn3,pawn3->getPosition());
        p4 = new Player(Side::EST,(board_.getSize()+1)/2);
        p4->initializePawnPlayer(board_.getSize());
        Pawn *pawn4 =  new Pawn(p4->getSide(),p4->getPawn()->getPosition());
        board_.placePawn(pawn4,pawn4->getPosition());
        game.addPlayer(p3,p4);
        p1->setNbWall((board_.getSize()+1)/2);
        p2->setNbWall((board_.getSize()+1)/2);
    }
    // Fin initialisation des joueurs et des pions

    int currentPlayer = 0; // on commence toujours par le nord

    while(gameOver_==false){
        cout << "#################################" << endl;
        cout << "#       Plateau de jeu          #" << endl;
        cout << "#################################" << endl;
        cout << board_.toString() << endl;
        cout << "Le joueur courant est le joueur : " << currentPlayer+1 << endl;
        Player *tempPlayer;
        switch (currentPlayer){
        case 0 :
            tempPlayer=p1;
            break;
        case 1:
            tempPlayer=p2;
            break;
        case 2:
            tempPlayer=p3;
            break;
        case 3:
            tempPlayer=p4;
            break;
        }
        cout << "Il vous reste : " << tempPlayer->getNbWall() << " mur disponible " << endl;
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
                board_.movePawn(Direction::SUD,tempPlayer->getPawn());
            }catch (exception e){
                    cerr << e.what() << endl;
                }
                break;
            case 'H':
                try{
                board_.movePawn(Direction::NORTH,tempPlayer->getPawn());
            }catch (exception e){
                    cerr << e.what() << endl;
                }
                break;
            case 'D':
                try{
                board_.movePawn(Direction::EST,tempPlayer->getPawn());
            }catch (exception e){
                    cerr << e.what() << endl;
                }
                break;
            case 'G':
                try{
                board_.movePawn(Direction::WEST,tempPlayer->getPawn());
            }catch (exception e){
                    cerr << e.what() << endl;
                }
                break;
            }
        }if(choixAction==2){
            bool ok=false;
            while(!ok){
                char align='o';
                Alignement align_;
                while (align !='H' && align!='V'){
                    cout << "Choissisez l'alignement du mur (H: horizontal , V: Vertical ) : ";
                    cin >> align;
                }
                if(align=='V')
                    align_=Alignement::VERTICAL;
                else
                    align_=Alignement::HORIZONTAL;
                pair <int,int> pos;
                pos=askPositionWall();
                board_.placeWall(pos,align_);
                if(nbPlayer==2){
                    if(verifyAllPlayerWay(p1,p2))
                        ok=true;
                    else
                        board_.removeWall(pos,align_);
                }else{
                    if(verifyAllPlayerWay(p1,p2)&& verifyAllPlayerWay(p3,p4))
                        ok=true;
                    else
                        board_.removeWall(pos,align_);
                }
            }

            tempPlayer->pickWall();
        }
        if(nbPlayer==4 && currentPlayer==3 || nbPlayer==2 && currentPlayer==1)
            currentPlayer=0;
        else
            currentPlayer++;
        if(playerHasWon(tempPlayer)){
            gameOver();
            cout << "Le joueur " << currentPlayer << " remporte la partie !" << endl;
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

pair <int,int> Game::askPositionWall()
{
    cout << "Choisissez la position à partir de laquel votre mur sera placé : " << endl;
    int row=-1;
    while (row <0 || row>board_.getSize()*2-2){
        cout << "Quel est le numéro de la ligne ( en partant de 0 ) : ";
        cin >> row ;
    }
    int column=-1;
    while (column<0 || column>board_.getSize()*2-2){
        cout << "Qul est le numéro de la colonne ( en partant de 0 ) : ";
        cin >> column;
    }
    pair <int,int> pos;
    pos.first=row;
    pos.second=column;
    return pos;
}

void Game::removeWall(pair <int,int> pos, Alignement align)
{
    board_.removeWall(pos,align);
}

bool Game::verifyAllPlayerWay(Player *p1, Player *p2)
{
    bool result1,result2;
    result1=board_.existWay(p1->getPawn()->getPosition(),p1->getPawn()->getSide());
    result2=board_.existWay(p2->getPawn()->getPosition(),p2->getPawn()->getSide());
    return result1 && result2;
}

bool Game::playerHasWon(Player *p)
{
    bool win=false;
    int trueSize=board_.getSize()*2-1;
    switch (p->getSide()){
        case Side::NORTH:
            if(p->getPawn()->getPosition().first==trueSize-1)
                win=true;
            break;
        case Side::SOUTH:
            if(p->getPawn()->getPosition().first==0)
                win=true;
            break;
        case Side::WEST:
            if(p->getPawn()->getPosition().second==trueSize-1)
                win=true;
            break;
        case Side::EST:
            if(p->getPawn()->getPosition().second==0)
                win=true;
            break;
    }
    return win;
}



