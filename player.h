#ifndef PLAYER
#define PLAYER
#include <string>
#include "side.h"
#include "piece.h"
using namespace std;
/*!
 * \class Player
 * \brief Classe qui représente un joueur.
 * \author Kasay-Temsamani.
 * \version 1.0
 * \date 2016
 */
class Player{
private:
    Pawn* pawn_;
    bool winner_=false;
    int nbWall_;
    Side side_;

public:
    /*!
         * \brief Player Constructeur.
         * \param side Le bord d'où part le joueur initialement.
         * \param nbWall Le nombre de mur dont le joueur dispose.
         */
    Player(Side side, int nbWall);
    /*!
         * \brief getSide Accesseur en lecture du bord d'origine du pion ou joueur.
         * \return Le bord d'origine.
         */
    inline Side getSide(){
        return side_;
    }
    /*!
        * \brief getPawn Accesseur en lecture de l'attribut pion du joueur.
        * \return L'attribut pion du joueur.
        */
    inline Pawn* getPawn(){
        return pawn_;
    }
    /*!
         * \brief getNbWall Accesseur en lecture du nombre de murs restant du joueur.
         * \return Le nombre de mur.
         */
    inline int getNbWall(){
        return nbWall_;
    }
    /*!
         * \brief setNbWall Mutateur, modifie le nombre de murs restant du joueur.
         * \param nbWall Le nombre de mur souhaité.
         */
    inline void setNbWall(int nbWall){
        nbWall_=nbWall;
    }
    /*!
         * \brief pickWall Méthode décrémentant d'une unité le nombre de murs restant du joueur.
         * \throws invalid_argument exception si il n'y a plus de mur.
         */
    void pickWall();
    /*!
         * \brief initializePawnPlayer Méthod qui place le joueur au mileu de son bord de départ.
         * \param sizeBoard La taille du plateau de jeu.
         */
    void initializePawnPlayer(int sizeBoard);

};

#endif // PLAYER

