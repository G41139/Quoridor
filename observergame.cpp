#include "observergame.h"
#include "sujetDObservation.h"
#include "game.h"
#include "iostream"

ObserverGame::ObserverGame(SujetDObservation *suj){
    this->board = (Board *) suj;
    board->attacher(this);
}

void ObserverGame::rafraichir(const SujetDObservation *sdo){
    this->board = (Board *) sdo;
    std::cout << board->toString();
}

ObserverGame::~ObserverGame(){

}

