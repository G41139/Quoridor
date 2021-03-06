#include "board.h"
#include "piece.h"
#include <stdexcept>
#include <string>
#include "game.h"

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

bool Board::checkLeftArm(pair<int,int> pos, Direction direction)
{
    int trueSize=size_*2-1;
    bool isPresent=true;
    switch (direction){
    case Direction::NORTH:
        if(pos.second==0)
            isPresent=true;
        else
            isPresent=!(board_[pos.first][pos.second-1]->isEmpty());
        break;
    case Direction::SUD:
        if(pos.second==trueSize-1)
            isPresent=true;
        else
            isPresent=!(board_[pos.first][pos.second+1]->isEmpty());
        break;
    case Direction::WEST:
        if(pos.first==trueSize-1)
            isPresent=true;
        else
            isPresent=!(board_[pos.first+1][pos.second]->isEmpty());
        break;
    case Direction::EST:
        if(pos.first==0)
            isPresent=true;
        else
            isPresent=!(board_[pos.first-1][pos.second]->isEmpty());
        break;
    default:
        break;
    }
    return isPresent;
}

bool Board::checkFrontWall(pair<int, int> pos, Direction direction)
{
    int trueSize=2*size_-1;
    bool isPresent=true;
    switch (direction){
    case Direction::NORTH:
        if(pos.first==0){
            isPresent=true;
        }else{
            isPresent=!(board_[pos.first-1][pos.second]->isEmpty());
        }
        break;
    case Direction::SUD:
        if(pos.first==trueSize-1){
            isPresent=true;
        }else{
            isPresent=!(board_[pos.first+1][pos.second]->isEmpty());
        }
        break;
    case Direction::WEST:
        if(pos.second==0){
            isPresent=true;
        }else{
            isPresent=!(board_[pos.first][pos.second-1]->isEmpty());
        }
        break;
    case Direction::EST:
        if(pos.second==trueSize-1)
            isPresent=true;
        else
            isPresent=!(board_[pos.first][pos.second+1]->isEmpty());
        break;
    default :
        break;
    }
    return isPresent;

}
void Board::placeWall(pair<int, int> pos, Alignement alignement)
{
    auto size=size_*2-2;
    if((alignement==Alignement::HORIZONTAL && (pos.first==0 || pos.first==size || (pos.second==0 && pos.first % 2 ==0) || pos.second==size)) ||
            (alignement==Alignement::VERTICAL && (pos.second==0 || pos.second==size || (pos.first==0 && pos.second % 2 ==0) || pos.second==size)) ){
        throw invalid_argument ("A wall can't be placed on the bord of the board game !");
    }
    switch (alignement){
    case Alignement::HORIZONTAL:
        if(pos.second%2==1 || pos.first%2==0){
            throw invalid_argument ("The position is invalid !");
        }
        if(board_[pos.first][pos.second]->isEmpty()&& board_[pos.first][pos.second+1]->isEmpty() && board_[pos.first][pos.second+2]->isEmpty()){
            board_[pos.first][pos.second]->setPlaced();
            board_[pos.first][pos.second+1]->setPlaced();
            board_[pos.first][pos.second+2]->setPlaced();
        }else{
            throw invalid_argument ("The position is invalid ! ");
        }
        break;
    case Alignement::VERTICAL:
        if(pos.first %2 ==1 || pos.second %2==0){
            throw invalid_argument ("The position is invalid !");
        }
        if(board_[pos.first][pos.second]->isEmpty()&& board_[pos.first+1][pos.second]->isEmpty()&& board_[pos.first+2][pos.second]->isEmpty()){
            board_[pos.first][pos.second]->setPlaced();
            board_[pos.first+1][pos.second]->setPlaced();
            board_[pos.first+2][pos.second]->setPlaced();
        }else{
            throw invalid_argument ("The position is invalid !");
        }
        break;
    default:
        break;
    }
    notifierChangement();
}

void Board::placePawn(Pawn *pawn, pair <int,int> pos)
{
    board_[pos.first][pos.second]=pawn;
    pawn->setPlaced();
    notifierChangement();
}

void Board::movePawn(Direction direction, Pawn *pawn)
{
    pair<int,int> pos=pawn->getPosition();
    int trueSize=size_*2-2;
    switch (direction){
    case Direction::NORTH:
        if(pos.first==0 || !(board_[pos.first-1][pos.second]->isEmpty())){
            throw invalid_argument ("The position is invalid !");
        }else{
            if( board_[pos.first-2][pos.second]->isEmpty()==false){
                pair <int,int> tempPos { pos.first-4, pos.second};
                pawn->setPosition(tempPos);
                board_[tempPos.first][tempPos.second]->setPlaced();
                board_[tempPos.first][tempPos.second]->setSide(pawn->getSide());
                board_[pos.first][pos.second]->clear();
            }else{
                pair <int,int> tempPos { pos.first-2, pos.second};
                pawn->setPosition(tempPos);
                board_[tempPos.first][tempPos.second]->setPlaced();
                board_[tempPos.first][tempPos.second]->setSide(pawn->getSide());
                board_[pos.first][pos.second]->clear();

            }

        }
        break;
    case Direction::SUD:
        if(pos.first==trueSize || !(board_[pos.first+1][pos.second]->isEmpty()) ){
            throw invalid_argument ("The position is invalid !");
        }else{
            if( board_[pos.first+2][pos.second]->isEmpty()==false){
                pair <int,int> tempPos { pos.first+4, pos.second};
                pawn->setPosition(tempPos);
                board_[tempPos.first][tempPos.second]->setPlaced();
                board_[tempPos.first][tempPos.second]->setSide(pawn->getSide());
                board_[pos.first][pos.second]->clear();

            }else{
                pair <int,int> tempPos { pos.first+2, pos.second};
                pawn->setPosition(tempPos);
                board_[tempPos.first][tempPos.second]->setPlaced();
                board_[tempPos.first][tempPos.second]->setSide(pawn->getSide());
                board_[pos.first][pos.second]->clear();
            }
        }
        break;
    case Direction::EST:
        if(pos.second==trueSize-1 || !(board_[pos.first][pos.second+1]->isEmpty())){
            throw invalid_argument ("The position is invalid !");
        }else{
            if( board_[pos.first][pos.second+2]->isEmpty()==false){
                pair <int,int> tempPos { pos.first, pos.second+4};
                pawn->setPosition(tempPos);
                board_[tempPos.first][tempPos.second]->setPlaced();
                board_[tempPos.first][tempPos.second]->setSide(pawn->getSide());
                board_[pos.first][pos.second]->clear();
            }else{
                pair <int,int> tempPos { pos.first, pos.second+2};
                pawn->setPosition(tempPos);
                board_[tempPos.first][tempPos.second]->setPlaced();
                board_[tempPos.first][tempPos.second]->setSide(pawn->getSide());
                board_[pos.first][pos.second]->clear();
            }
        }
        break;
    case Direction::WEST:
        if(pos.second==0 || !(board_[pos.first][pos.second-1]->isEmpty()) ){
            throw invalid_argument ("The position is invalid !");
        }else{
            if( board_[pos.first][pos.second-2]->isEmpty()==false){
                pair <int,int> tempPos { pos.first, pos.second-4};
                pawn->setPosition(tempPos);
                board_[tempPos.first][tempPos.second]->setPlaced();
                board_[tempPos.first][tempPos.second]->setSide(pawn->getSide());
                board_[pos.first][pos.second]->clear();
            }else{
                pair <int,int> tempPos { pos.first, pos.second-2};
                pawn->setPosition(tempPos);
                board_[tempPos.first][tempPos.second]->setPlaced();
                board_[tempPos.first][tempPos.second]->setSide(pawn->getSide());
                board_[pos.first][pos.second]->clear();
            }
        }
        break;
    case Direction::NORTH_EST:
    {
        pair <int,int> tempPos { pos.first-2, pos.second+2};
        pawn->setPosition(tempPos);
        board_[tempPos.first][tempPos.second]->setPlaced();
        board_[tempPos.first][tempPos.second]->setSide(pawn->getSide());
        board_[pos.first][pos.second]->clear();
        break;
    }
    case Direction::NORTH_WEST:
    {
        pair <int,int> tempPos ={ pos.first-2, pos.second-2};
        pawn->setPosition(tempPos);
        board_[tempPos.first][tempPos.second]->setPlaced();
        board_[tempPos.first][tempPos.second]->setSide(pawn->getSide());
        board_[pos.first][pos.second]->clear();
        break;
    }
    case Direction::SUD_WEST:
    {
        pair <int,int> tempPos { pos.first+2, pos.second-2};
        pawn->setPosition(tempPos);
        board_[tempPos.first][tempPos.second]->setPlaced();
        board_[tempPos.first][tempPos.second]->setSide(pawn->getSide());
        board_[pos.first][pos.second]->clear();
        break;
    }
    case Direction::SUD_EST:
    {
        pair <int,int> tempPos { pos.first+2, pos.second+2};
        pawn->setPosition(tempPos);
        board_[tempPos.first][tempPos.second]->setPlaced();
        board_[tempPos.first][tempPos.second]->setSide(pawn->getSide());
        board_[pos.first][pos.second]->clear();
        break;
    }
    }

    notifierChangement();
}

void Board::rotatePawn(Direction *direction, int *cpt, bool leftRotation)
{
    switch (*direction){
    case Direction::NORTH:
        if(leftRotation){
            *cpt=*cpt-1;
            *direction=Direction::WEST;
        }
        else{
            *cpt=*cpt+1;
            *direction=Direction::EST;
        }
        break;
    case Direction::SUD:
        if(leftRotation){
            *cpt=*cpt-1;
            *direction=Direction::EST;
        }
        else{
            *cpt=*cpt+1;
            *direction=Direction::WEST;
        }
        break;
    case Direction::EST:
        if(leftRotation){
            *cpt=*cpt+1;
            *direction=Direction::NORTH;
        }
        else{
            *cpt=*cpt-1;
            *direction=Direction::SUD;
        }
        break;
    case Direction::WEST:
        if(leftRotation){
            *cpt=*cpt-1;
            *direction=Direction::SUD;
        }
        else{
            *cpt=*cpt+1;
            *direction=Direction::NORTH;
        }
        break;
    default:
        break;
    }
}

bool Board::objectifReached(Side initSide, pair<int,int> pos)
{
    bool reached=false;
    int trueSize=size_*2-1;
    switch (initSide){
    case Side::NORTH:
        if(pos.first+2==trueSize-1)
            reached=true;
        break;
    case Side::SOUTH:
        if(pos.first-2==0)
            reached=true;
        break;
    case Side::WEST:
        if(pos.second+2==trueSize-1)
            reached=true;
        break;
    case Side::EST:
        if(pos.second-2==0)
            reached=true;
        break;
    default:break;
    }
    return reached;
}

bool Board::existWay(pair<int, int> initPos,Side initSide)
{
    bool exist=false;
    Direction initDirection;
    Direction *pinitDirection= &initDirection;
    switch (initSide){
    case Side::NORTH:
        initDirection=Direction::SUD;
        break;
    case Side::SOUTH:
        initDirection=Direction::NORTH;
        break;
    case Side::WEST:
        initDirection=Direction::EST;
        break;
    case Side::EST:
        initDirection=Direction::WEST;
        break;
    case Side::BLANK:
        initDirection=Direction::NORTH;
        break;
    }
    int cptRotation=0;
    int *pcptRotation=&cptRotation;
    pair <int,int> virtualPos=initPos;
    pair <int,int> *pvirtualPos=&virtualPos;
    while(!(objectifReached(initSide,virtualPos)) && cptRotation > -15 && cptRotation<10 ){
        if(cptRotation==0){
            if(!(checkFrontWall(virtualPos,initDirection)))
                virtualDeplacement(&virtualPos,initDirection);
            else
                rotatePawn(pinitDirection,pcptRotation,false);
        }else{
            if(!(checkLeftArm(virtualPos,initDirection)))
                rotatePawn(pinitDirection,pcptRotation,true);
            else{
                if(!(checkFrontWall(virtualPos,initDirection)))
                    virtualDeplacement(pvirtualPos,initDirection);
                else
                    rotatePawn(pinitDirection,pcptRotation,false);
            }
        }
        if(objectifReached(initSide,virtualPos))
            exist=true;
        if(cptRotation<-15 || cptRotation>10)
            exist=false;
    }
    return exist;
}

void Board::virtualDeplacement(pair<int, int> *pos, Direction direction)
{
    switch(direction){
    case Direction::NORTH: pos->first=pos->first-2;break;
    case Direction::SUD: pos->first=pos->first+2;break;
    case Direction::EST: pos->second=pos->second+2;break;
    case Direction::WEST : pos->second=pos->second-2;break;
    default:
        break;
    }
}

void Board::removeWall(pair<int, int> pos, Alignement align)
{
    switch(align){
    case Alignement::HORIZONTAL:
        board_[pos.first][pos.second]= new Wall();
        board_[pos.first][pos.second+1]= new Wall();
        board_[pos.first][pos.second+2]= new Wall();
        break;
    case Alignement::VERTICAL:
        board_[pos.first][pos.second]= new Wall();
        board_[pos.first+1][pos.second]= new Wall();
        board_[pos.first+2][pos.second]= new Wall();
        break;
    default: break;
    }
}

void Board::destroy()
{
    for(int i=0;i<size_*2-1; i++){
        for(int j=0 ; j<size_*2-1; j++){
            delete board_[i][j];

        }
    }
}

bool Board::diagonalMovementPossible(Pawn *pawn, Direction direction)
{
    pair <int,int> pos = pawn->getPosition();
    bool result=false;

    switch (direction){

    case Direction::NORTH_EST:

        if(pos.first==0 || pos.second==size_*2-2){
            result=false;
        }
        if( ( board_[pos.first-2][pos.second+1]->isEmpty() && ! board_[pos.first-3][pos.second]->isEmpty() &&
             !board_[pos.first-2][pos.second]->isEmpty())){
            result=true;
        }
        else if( (board_[pos.first-1][pos.second+2]->isEmpty() && !board_[pos.first][pos.second+2]->isEmpty() &&
                  !board_[pos.first][pos.second+3]->isEmpty())){
            result=true;
        }else{
            result=false;
        }
        break;


    case Direction::NORTH_WEST:
        if(pos.first==0 || pos.second==0){
            result=false;
        }
        if( ( board_[pos.first-2][pos.second-1]->isEmpty() && ! board_[pos.first-3][pos.second]->isEmpty() &&
             !board_[pos.first-2][pos.second]->isEmpty())){
            result=true;
        }
        else if( (board_[pos.first-1][pos.second-1]->isEmpty() && !board_[pos.first][pos.second-2]->isEmpty() &&
                  !board_[pos.first][pos.second-3]->isEmpty())){
            result=true;
        }else{
            result=false;
        }
        break;
    case Direction::SUD_EST:
        if(pos.first==size_*2-2 || pos.second==size_*2-2){
            result=false;
        }
        if( ( board_[pos.first+2][pos.second+1]->isEmpty() && ! board_[pos.first+3][pos.second]->isEmpty() &&
             !board_[pos.first+2][pos.second]->isEmpty())){
            result=true;
        }
        else if( (board_[pos.first+1][pos.second+2]->isEmpty() && !board_[pos.first][pos.second+2]->isEmpty() &&
                  !board_[pos.first][pos.second+3]->isEmpty())){
            result=true;
        }else{
            result=false;
        }
        break;
    case Direction::SUD_WEST:
        if(pos.first==0 || pos.second==size_*2-2){
            result=false;
        }
        if( ( board_[pos.first+2][pos.second-1]->isEmpty() && ! board_[pos.first+3][pos.second]->isEmpty() &&
             !board_[pos.first+2][pos.second]->isEmpty())){
            result=true;
        }
        else if( (board_[pos.first+1][pos.second-2]->isEmpty() && !board_[pos.first][pos.second-2]->isEmpty() &&
                  !board_[pos.first][pos.second-3]->isEmpty())){
            result=true;
        }else{
            result=false;
        }
        break;
    default:break;
    }
    return result;
}

bool Board::movementPossible(Pawn *pawn, Direction direction)
{
    pair <int,int> pos = pawn->getPosition();
    bool result=false;
    switch (direction){
    case Direction::NORTH:
        if(pos.first==0){
            result=false;
            break;
        }else{
            if(board_[pos.first-2][pos.second]->isEmpty() && board_[pos.first-1][pos.second]->isEmpty() ){
                result=true;
            }
            if(board_[pos.first-2][pos.second]->isEmpty()==false && board_[pos.first-4][pos.second]->isEmpty() &&
                    board_[pos.first-1][pos.second]->isEmpty() && board_[pos.first-3][pos.second]->isEmpty()){
                result=true;
            }
        }
        break;
    case Direction::SUD:
        if(pos.first==2*size_-2){
            result=false;
            break;
        }else{
            if(board_[pos.first+2][pos.second]->isEmpty() && board_[pos.first+1][pos.second]->isEmpty()){
                result=true;
            }
            if(board_[pos.first+2][pos.second]->isEmpty()==false && board_[pos.first+4][pos.second]->isEmpty() &&
                    board_[pos.first+1][pos.second]->isEmpty() && board_[pos.first+3][pos.second]->isEmpty()){
                result=true;
            }
        }
        break;
    case Direction::WEST:
        if(pos.second==0){
            result=false;
        }else{
            if(board_[pos.first][pos.second-2]->isEmpty() && board_[pos.first][pos.second-1]->isEmpty()){
                result=true;
            }
            if(board_[pos.first][pos.second-2]->isEmpty()==false && board_[pos.first][pos.second-4]->isEmpty() &&
                    board_[pos.first][pos.second-1]->isEmpty() && board_[pos.first][pos.second-3]->isEmpty()){
                result=true;
            }
        }
        break;
    case Direction::EST:
        if(pos.second==size_*2-2){
            result=false;
        }else{
            if(board_[pos.first+2][pos.second]->isEmpty() && board_[pos.first][pos.second+1]->isEmpty()){
                result=true;
            }
            if(board_[pos.first][pos.second+2]->isEmpty()==false && board_[pos.first][pos.second+4]->isEmpty() &&
                    board_[pos.first][pos.second+1]->isEmpty() && board_[pos.first][pos.second+3]->isEmpty()){
                result=true;
            }
        }
        break;
    default:break;
    }
    return result;
}

bool Board::placementWallPossible(pair<int, int> pos, Alignement align)
{
    bool result=false;
    if(align==Alignement::HORIZONTAL){
        if(pos.first==0 || pos.first== size_*2-2 || pos.second%2==1 || pos.first%2==0){
            result=false;
        }else{
            if(board_[pos.first][pos.second]->isEmpty() &&  board_[pos.first][pos.second+1]->isEmpty() &&
                    board_[pos.first][pos.second+2]->isEmpty()){
                result=true;
            }
        }
    }
    if(align==Alignement::VERTICAL){
        if(pos.second==0 || pos.second== size_*2-1 || pos.first %2 ==1 || pos.second %2==0){
            result=false;
        }else{
            if(board_[pos.first][pos.second]->isEmpty() &&  board_[pos.first+1][pos.second]->isEmpty() &&
                    board_[pos.first+2][pos.second]->isEmpty()){
                result=true;
            }
        }
    }
    return result;
}
