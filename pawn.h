#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
#include "direction.h"
#include <string>
#include "side.h"
class Pawn : public Piece
{
private:
    Side side_;
public:
    Pawn();
    void movePawn();
    string toString();
};

#endif // PAWN_H
