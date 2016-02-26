#include "board.h"
#include "piece.h"
#include <stdexcept>
#include <string>

using namespace std;
Board::Board(int size)
{
    if (size % 2==0 || size> 19 || size< 5){
        throw new invalid_argument ("The size is invalid !");
    }
    size_=size;
    auto sizeTemp=size*2-1;
    board_=vector<std::vector<Piece *> > (sizeTemp, std::vector<Piece *>(sizeTemp, nullptr));
    for (int i=0 ; i<sizeTemp; i++){
        for(int j=0; j<sizeTemp; j++){
            pair <int,int> pos {i,j};
            if(i%2==0 && j%2==0){
                Pawn *pw = new Pawn();
                board_[i][j]= pw;
            }else{
                Wall *pp = new Wall();
                board_[i][j]= pp;
            }
        }
    }
}
string Board::toString(){
    string ch;
    for(int i=0;i<size_*2-1; i++){
        ch=ch+"\n";
        for(int j=0 ; j<size_*2-1; j++){
            ch=ch+board_[i][j]->toString();
        }
    }
    ch=ch+"\n";
    return ch;
}

void Board::placePawn(Pawn *pawn, pair <int,int> pos)
{
    board_[pos.first][pos.second]=pawn;
}


bool Board::checkWall(pair <int,int> pos)
{

}

void Board::movePawn(Direction direction, Pawn *pawn)
{
    pair<int,int> pos=pawn->getPosition();
    bool result=true;
    switch (direction){
        case Direction::NORTH:
            if(pos.first==0 || !(board_[pos.first-1][pos.second]->isEmpty()) || !(board_[pos.first-2][pos.second]->isEmpty()) ){
                result=false;
            }else{
                if( board_[pos.first-2][pos.second]->isEmpty()==false){
                    pair <int,int> tempPos { pos.first-4, pos.second};
                    Pawn *temp= new Pawn(pawn->getSide(),tempPos);
                    board_[temp->getPosition().first][temp->getPosition().second]=temp;
                    delete board_[pawn->getPosition().first][pawn->getPosition().second];
                }else{
                    pair <int,int> tempPos { pos.first-2, pos.second};
                    Pawn *temp= new Pawn(pawn->getSide(),tempPos);
                    board_[temp->getPosition().first][temp->getPosition().second]=temp;
                    delete board_[pawn->getPosition().first][pawn->getPosition().second];
                    Pawn *temp2= new Pawn();
                    board_[pawn->getPosition().first][pawn->getPosition().second]=temp2;

                }

            }
            break;
        case Direction::SUD:
            if(pos.first==size_ || !(board_[pos.first+1][pos.second]->isEmpty()) || !(board_[pos.first+2][pos.second]->isEmpty()) ){
                result=false;
            }else{
                if( board_[pos.first+2][pos.second]->isEmpty()==false){
                    pair <int,int> tempPos { pos.first+4, pos.second};
                    Pawn *temp= new Pawn(pawn->getSide(),tempPos);
                    board_[temp->getPosition().first][temp->getPosition().second]=temp;
                    delete board_[pawn->getPosition().first][pawn->getPosition().second];
                }else{
                    pair <int,int> tempPos { pos.first+2, pos.second};
                    Pawn *temp= new Pawn(pawn->getSide(),tempPos);
                    board_[temp->getPosition().first][temp->getPosition().second]=temp;
                    delete board_[pawn->getPosition().first][pawn->getPosition().second];
                    Pawn *temp2= new Pawn();
                    board_[pawn->getPosition().first][pawn->getPosition().second]=temp2;
                }
            }
            break;
        case Direction::EST:
            if(pos.second==size_ || !(board_[pos.first][pos.second+1]->isEmpty()) || !(board_[pos.first][pos.second+2]->isEmpty()) ){
                result=false;
            }else{
                if( board_[pos.first][pos.second+2]->isEmpty()==false){
                    pair <int,int> tempPos { pos.first, pos.second+4};
                    Pawn *temp= new Pawn(pawn->getSide(),tempPos);
                    board_[temp->getPosition().first][temp->getPosition().second]=temp;
                    delete board_[pawn->getPosition().first][pawn->getPosition().second];
                }else{
                    pair <int,int> tempPos { pos.first, pos.second+2};
                    Pawn *temp= new Pawn(pawn->getSide(),tempPos);
                    board_[temp->getPosition().first][temp->getPosition().second]=temp;
                    delete board_[pawn->getPosition().first][pawn->getPosition().second];
                    Pawn *temp2= new Pawn();
                    board_[pawn->getPosition().first][pawn->getPosition().second]=temp2;
                }
            }
            break;
        case Direction::WEST:
            if(pos.second==0 || !(board_[pos.first][pos.second-1]->isEmpty()) || !(board_[pos.first][pos.second-2]->isEmpty()) ){
                result=false;
            }else{
                if( board_[pos.first][pos.second-2]->isEmpty()==false){
                    pair <int,int> tempPos { pos.first, pos.second-4};
                    Pawn *temp= new Pawn(pawn->getSide(),tempPos);
                    board_[temp->getPosition().first][temp->getPosition().second]=temp;
                    delete board_[pawn->getPosition().first][pawn->getPosition().second];
                }else{
                    pair <int,int> tempPos { pos.first, pos.second-2};
                    Pawn *temp= new Pawn(pawn->getSide(),tempPos);
                    board_[temp->getPosition().first][temp->getPosition().second]=temp;
                    delete board_[pawn->getPosition().first][pawn->getPosition().second];
                    Pawn *temp2= new Pawn();
                    board_[pawn->getPosition().first][pawn->getPosition().second]=temp2;
                }
            }
            break;
        case Direction::NORTH_EST :
            if(pos.first==0 || !(board_[pos.first-1][pos.second+1]->isEmpty()) || pos.second==size_ ){
                result=false;
            }else{
                pair <int,int> tempPos { pos.first-2, pos.second+2};
                Pawn *temp= new Pawn(pawn->getSide(),tempPos);
                board_[temp->getPosition().first][temp->getPosition().second]=temp;
                delete board_[pawn->getPosition().first][pawn->getPosition().second];
                Pawn *temp2= new Pawn();
                board_[pawn->getPosition().first][pawn->getPosition().second]=temp2;
            }
            break;
        case Direction::NORTH_WEST :
            if(pos.first==0|| !(board_[pos.first-1][pos.second-1]->isEmpty()) || pos.second==0 ){
                result=false;
            }else{
                pair <int,int> tempPos { pos.first-2, pos.second-2};
                Pawn *temp= new Pawn(pawn->getSide(),tempPos);
                board_[temp->getPosition().first][temp->getPosition().second]=temp;
                delete board_[pawn->getPosition().first][pawn->getPosition().second];
                Pawn *temp2= new Pawn();
                board_[pawn->getPosition().first][pawn->getPosition().second]=temp2;
            }
            break;
        case Direction::SUD_EST :
            if(pos.first==size_ || !(board_[pos.first+1][pos.second+1]->isEmpty()) || pos.second==size_ ){
                result=false;
            }else{
                pair <int,int> tempPos { pos.first+2, pos.second+2};
                Pawn *temp= new Pawn(pawn->getSide(),tempPos);
                board_[temp->getPosition().first][temp->getPosition().second]=temp;
                delete board_[pawn->getPosition().first][pawn->getPosition().second];
                Pawn *temp2= new Pawn();
                board_[pawn->getPosition().first][pawn->getPosition().second]=temp2;
            }
            break;
        case Direction::SUD_WEST:
            if(pos.first==size_ || !(board_[pos.first+1][pos.second-1]->isEmpty()) || pos.second==0 ){
                result=false;
            }else{
                pair <int,int> tempPos { pos.first+2, pos.second-2};
                Pawn *temp= new Pawn(pawn->getSide(),tempPos);
                board_[temp->getPosition().first][temp->getPosition().second]=temp;
                delete board_[pawn->getPosition().first][pawn->getPosition().second];
                Pawn *temp2= new Pawn();
                board_[pawn->getPosition().first][pawn->getPosition().second]=temp2;
            }
    }
}
