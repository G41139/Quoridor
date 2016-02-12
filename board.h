#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <vector>
class Board
{
private:
    static const int size_;
    vector <vector<*Piece,size_>,size_> board_;

public:
    Board();
    void validateSize();
};

#endif // BOARD_H
