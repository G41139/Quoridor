#include <iostream>
#include "board.h"
#include "player.h"
#include "side.h"
using namespace std;

int main()
{
    int size;
    cout << "Veuillez entrez la taille du tableau : ";
    cin >> size ;
    pair <int,int>pos {4,4};
    Board board (size);
    cout << board.toString();

    return 0;

}

