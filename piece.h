#ifndef PIECE_H
#define PIECE_H
#include <utility>
#include <string>
#include "side.h"
#include "direction.h"
#include "alignement.h"
using namespace std;

//Définition de la classe Piece qui représente soit un mur ou soit un Pion
class Piece
{
public:
    virtual ~Piece()=default;
    Piece()=default;
    virtual pair<int,int> getPosition()=0;
    virtual void setPosition(pair <int,int> pos)=0;
   virtual string toString()=0;
   virtual bool isEmpty()=0;
};

//Définition de la classe Pawn qui définit un pion
class Pawn : public Piece
{
private:
    Side side_;
    pair <int,int> position_;
    Direction direction_;
    bool isPlaced_=false;
public:
    Pawn();
    Pawn (Side side,pair <int,int> pos);
    string toString();
    inline void setPosition(pair <int,int> pos){
        position_=pos;
    }
    inline Side getSide(){
        return side_;
    }

    inline pair <int,int> getPosition(){
        return position_;
    }
    inline bool isEmpty(){
        return !isPlaced_;
    }
    inline void setSide(Side side){
        side_=side;
    }
    inline void setPlaced(){
        isPlaced_=true;
    }
};


//Définition de la class Wall qui définit un mur
class Wall : public Piece
{
private:
    pair <int,int> position_;
    bool isPlaced_=false;
    Alignement alignement_;

public:
    Wall();
    Wall(pair <int,int> pos, Alignement alignement);
    string toString();
    inline void setWall(){
        isPlaced_=true;
    }
    inline void setPosition(pair <int,int> pos){
        position_=pos;
    }
    inline pair <int,int> getPosition(){
        return position_;
    }
    inline bool isEmpty(){
        return !isPlaced_;
    }

};

#endif // PIECE_H
