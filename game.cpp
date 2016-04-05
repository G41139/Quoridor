#include "board.h"
#include "game.h"
#include <iostream>
#include <stdexcept>
#include <observergame.h>


void Game::addPlayer()
{
    int nbPlayer_=0;
    while(nbPlayer_ != 2 && nbPlayer_ !=4){
        cout << "Veuillez choisir le nombre de joueur ( 2 ou 4 ) : ";
        cin >> nbPlayer_;
        cout << endl;
    }
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
    listPlayer_.push_back(p1);
    listPlayer_.push_back(p2);
    Player *p3, *p4;
    if(nbPlayer_==4){
        p3= new Player(Side::WEST,(board_.getSize()+1)/2);
        p3->initializePawnPlayer(board_.getSize());
        Pawn *pawn3= new Pawn(p3->getSide(),p3->getPawn()->getPosition());
        board_.placePawn(pawn3,pawn3->getPosition());
        p4 = new Player(Side::EST,(board_.getSize()+1)/2);
        p4->initializePawnPlayer(board_.getSize());
        Pawn *pawn4 =  new Pawn(p4->getSide(),p4->getPawn()->getPosition());
        board_.placePawn(pawn4,pawn4->getPosition());
        listPlayer_.push_back(p3);
        listPlayer_.push_back(p4);
        p1->setNbWall((board_.getSize()+1)/2);
        p2->setNbWall((board_.getSize()+1)/2);
    }
    // Fin initialisation des joueurs et des pions
}

Game::Game( int size) : board_(Board(size))
{
}

void Game::play()
{



    cout << "###############################################" << endl;
    cout << "#Bienvenu sur l'application Console Quoridor! # " << endl;
    cout << "###############################################" << endl;
    cout << endl;

    addPlayer();

    int size=0;
    while(size<5 || size>19 || size%2==0){
        cout << "Veuillez choisir maintenant, la taille du plateau de jeu ( nombre impaire entre 5 et 19 ) : ";
        cin >> size;
        cout << endl;
    }

    int currentPlayer = 0; // on commence toujours par le nord

    while(gameOver_==false){
        cout << "#################################" << endl;
        cout << "#       Plateau de jeu          #" << endl;
        cout << "#################################" << endl;

        ObserverGame obs (&board_);

        cout << "Le joueur courant est le joueur : " << currentPlayer+1 << endl;
        Player *tempPlayer;
        tempPlayer=listPlayer_[currentPlayer];


        cout << "Il vous reste : " << tempPlayer->getNbWall() << " mur disponible " << endl;
        int choixAction=0;
        while (choixAction !=1 && choixAction !=2){
            cout << "Choisissez une action (1 pour déplacer votre pion et 2 pour placer un mur) : ";
            cin >> choixAction;
            cout << endl;
        }

        if(choixAction==1){
            bool temp=false;
            while(!temp){
                char move='0';
                while (move != 'H' && move != 'B' && move !='G' && move != 'D' && move !='A' && move !='E' &&
                       move !='W' && move !='C'){
                    cout << "Choisissez votre déplacement ( H = Haut, B = Bas, G= Gauche, D=droite, diagonale droite haut : E , diagonale droite bas :C,"
                            " diagonale gauche haut :A , diagonale gauche bas : W  ) : ";
                    cin >> move;
                    cout << endl;
                }

                switch (move){
                case 'B':
                    try{
                    board_.movePawn(Direction::SUD,tempPlayer->getPawn());
                    temp=true;
                }catch (exception &e){
                        cerr << e.what() << endl;
                    }
                    break;
                case 'H':
                    try{
                    board_.movePawn(Direction::NORTH,tempPlayer->getPawn());
                    temp=true;
                }catch (exception &e){
                        cerr << e.what() << endl;
                    }
                    break;
                case 'D':
                    try{
                    board_.movePawn(Direction::EST,tempPlayer->getPawn());
                    temp=true;
                }catch (exception &e){
                        cerr << e.what() << endl;
                    }
                    break;
                case 'G':
                    try{
                    board_.movePawn(Direction::WEST,tempPlayer->getPawn());
                    temp=true;
                }catch (exception &e){
                        cerr << e.what() << endl;
                    }
                    break;
                case 'E':
                    try{
                    board_.movePawn(Direction::NORTH_EST,tempPlayer->getPawn());
                    temp=true;
                }catch (exception &e){
                        cerr << e.what() << endl;
                    }
                    break;
                case 'A':
                    try{
                    board_.movePawn(Direction::NORTH_WEST,tempPlayer->getPawn());
                    temp=true;
                }catch (exception &e){
                        cerr << e.what() << endl;
                    }
                    break;
                case 'C':
                    try{
                    board_.movePawn(Direction::SUD_EST,tempPlayer->getPawn());
                    temp=true;
                }catch (exception &e){
                        cerr << e.what() << endl;
                    }
                    break;
                case 'W':
                    try{
                    board_.movePawn(Direction::SUD_WEST,tempPlayer->getPawn());
                    temp=true;
                }catch (exception &e){
                        cerr << e.what() << endl;
                    }
                    break;
                }
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
                if(nbPlayer_==2){
                    if(verifyAllPlayerWay(listPlayer_[0],listPlayer_[1]))
                        ok=true;
                    else
                        board_.removeWall(pos,align_);
                }else{
                    if(verifyAllPlayerWay(listPlayer_[0],listPlayer_[1])&& verifyAllPlayerWay(listPlayer_[2],listPlayer_[3]))
                        ok=true;
                    else
                        board_.removeWall(pos,align_);
                }
            }

            tempPlayer->pickWall();
        }
        if(nbPlayer_==4 && currentPlayer==3 || nbPlayer_==2 && currentPlayer==1)
            currentPlayer=0;
        else
            currentPlayer++;
        if(playerHasWon(tempPlayer)){
            gameOver_=true;
            cout << "Le joueur " << currentPlayer << " remporte la partie !" << endl;
        }
    }


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
    default:
        break;
    }
    return win;
}

void Game::movePawn(Direction direction, Pawn *pawn)
{
    switch (direction){
    case Direction::SUD:
        try{
        board_.movePawn(Direction::SUD,pawn);
    }catch (exception &e){
            cerr << e.what() << endl;
        }
        break;
    case Direction::NORTH:
        try{
        board_.movePawn(Direction::NORTH,pawn);
    }catch (exception &e){
            cerr << e.what() << endl;
        }
        break;
    case Direction::EST:
        try{
        board_.movePawn(Direction::EST,pawn);
    }catch (exception &e){
            cerr << e.what() << endl;
        }
        break;
    case Direction::WEST:
        try{
        board_.movePawn(Direction::WEST,pawn);
    }catch (exception &e){
            cerr << e.what() << endl;
        }
        break;
    default:break;
    }
}


void Game::placeWall(pair<int, int> pos, Alignement align, Player *player)
{
    try{
        board_.placeWall(pos,align);
        player->pickWall();
    }catch (exception &e){
        cerr << e.what() << endl;
    }
}




