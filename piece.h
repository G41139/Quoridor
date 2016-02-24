#ifndef PIECE_H
#define PIECE_H
#include <utility>
#include <string>
#include "side.h"
using namespace std;

//Définition de la classe Piece qui représente soit un mur ou soit un Pion
class Piece
{
protected:
    pair <int,int> position_;
public:
    Piece();
    Piece(pair <int,int> position);
    inline pair<int,int> getPosition(){
        return position_;

    }
    inline void setPosition(pair <int,int> position){
        position_=position;
    }
   virtual string toString();
};

//Définition de la classe Pawn qui définit un pion
class Pawn : public Piece
{
private:
    Side side_;
public:
    Pawn();
    Pawn (Side side,pair <int,int> pos);
    void movePawn();
    string toString();
};


//Définition de la class Wall qui définit un mur
class Wall : public Piece
{
private:
    bool isPlaced_=false;
public:
    Wall();
    Wall(pair <int,int> pos);
    string tostring();
    inline void setWall(){
        isPlaced_=true;
    }

};

#endif // PIECE_H
