#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <vector>
#include <string>
#include "direction.h"
#include "sujetDObservation.h"
using namespace std;
/*!
 * \class Board
 * \brief Classe qui se charge de de manipuler le plateau de jeu.
 * \author Kasay-Temsamani.
 * \version 1.0
 * \date 2016
 */
class Board : public SujetDObservation
{
private:
    int size_;
    vector <vector<Piece*>> board_;
public:
    /*!
      * \brief Destructeur de la classe Board

      */
    ~Board()=default;
    /*!
         * \brief Board Constructeur d'un plateau carré avec un nombre de lignes et un nombre de colonnes identiques.
         * \param size le nombre de lignes et de colonnes du plateau.
         * \throws invalid_argument exception si le nombre de lignes et de colonnes est incorrect.
         */
    Board(int size);
    /*!
         * \brief to_string Permet d'obtenir la représentation textuelle du plateau de jeu.
         */
    string toString ();
    /*!
         * \brief checkLeftArm Méthode vérifiant la présence d'un mur à gauche du joueur dans le sens
         * de son déplacement conformémént à l'algorithme de Pledge.
         * \param pos La position du joueur.
         * \param direction La direction dans laquelle se déplace le joueur.
         * \return true Si un mur est présent à gauche, sinon false.
         */
    bool checkLeftArm(pair <int,int> pos, Direction direction); // Renvoi true si il y a un mur à gauche
    /*!
         * \brief checkFrontWall Méthode vérifiant la présence d'un mur devant le joueur dans le sens
         * de son déplacement conformémént à l'algorithme de Pledge.
         * \param pos La position du joueur.
         * \param direction La direction dans laquelle se déplace le joueur.
         * \return true Si un mur est présent devant le joueur, sinon false.
         */
    bool checkFrontWall(pair <int,int> pos,Direction direction); // Renvoi true si il y a un mur en face
    /*!
         * \brief placeWall Méthode permettant d'insérer un mur entre 2 paires de cases, celui-ci est inséré
         * de gauche à droite et de haut en bas selon qu'il est aligné horizontalement ou verticalement.
         * \param pos La position origine du mur(ligne,colonne).
         * \param alignement L'alignement horizontal ou vertical du mur.
         * \throws invalid_argument exception si on essaie d'insérer un mur sur les bords nord, sud, est ou ouest.
         */
    void placeWall(pair <int,int> pos, Alignement alignement);
    /*!
         * \brief placePawn Méthode permettant de placer un pion.
         * \param pawn Le pion ou joueur.
         * \param pos La position à laquelle placer le pion.
         */
    void placePawn(Pawn *Pawn, pair <int,int> pos);
    /*!
         * \brief movePawn Méthode permettant de déplacer un pion.
         * \param direction La direction dans laquelle le pion doit se déplacer.
         * \param pawn Le pion ou joueur.
         * \throws invalid_argument exception si la position de déplacement est invalide.
         */
    void movePawn(Direction direction, Pawn *pawn);
    /*!
         * \brief rotatePawn Méthode permettant de faire la rotation vers la gauche ou la droite d'un pion.
         * \param direction La direction de déplacement du pion NORD, SUD, EST ou OUEST.
         * \param cpt Le compteur de rotation conformément à l'algorithme de Pledge.
         * \param leftRotation Le sens de rotation à true vers la gauche, false vers la droite.
         */
    void rotatePawn(Direction *direction, int *cpt, bool leftRotation);
    /*!
        * \brief objectifReached Méthode permettant de savoir si un pion a atteint le bord opposé.
        * \param initSide Le bord d'où part le pion initialement.
        * \param pos La position courante du pion ou joueur.
        * \return true Si le joueur a atteint le bord opposé.
        */
    bool objectifReached(Side initSide, pair<int,int> pos);
    /*!
        * \brief existWay Méthode permettant de savoir si chaque joueur possède tjrs un chemin vers une case
        * de son bord de destination.
        * \param initPos La position initiale du joueur.
        * \param initSide Le bord d'où part le joueur initialement.
        * \return true Si le joueur a atteint le bord opposé.
        */
    bool existWay(pair<int,int> initPos,Side initSide);
    /*!
         * \brief virtualDeplacement Méthode permettant de déplacer virtuellement un joueur.
         * \param pos La position de départ du joueur.
         * \param direction La direction du déplacement.
         */
    void virtualDeplacement(pair<int,int> *pos, Direction direction);
    /*!
         * \brief removeWall Méthode permettant d'enlever un mur lorqu'il est mal placé(invalide).
         * \param pos La position du mur placé.
         * \param align L'alignement du mur, horizontal ou vertical.
         */
    void removeWall(pair <int,int> pos, Alignement align);
    /*!
         * \brief getBoard Accesseur en lecture du plateau de jeu.
         * \return Le plateau de jeu.
         */
    inline vector <vector<Piece*>> getBoard(){
        return board_;
    }
    /*!
         * \brief getSize Accesseur en lecture de la taille du plateau de jeu.
         * \return La taille du plateau de jeu.
         */
    inline int getSize(){
        return size_;
    }
    /*!
         * \brief isFreee Méthode permettant de savoir si une position est libre.
         * \return true Si la position est libre, sinon false.
         */
    inline bool isFree (pair <int, int> position){
        return board_[position.first][position.second]->isEmpty();
    }
    /*!
         * \brief getPiece Accesseur en lecture d'une pièce
         * \param pos La position de la pièce.
         * \return La pièce, soit un mur, soit un pion.
         */
    inline Piece* getPiece(pair <int,int> pos){
        return board_[pos.first][pos.second];
    }

    /*!
         * \brief methode permettant de détruire les espaces mémoire réservés dans le board.
         */
    void destroy();

    bool diagonalMovementPossible (Pawn *pawn, Direction direction);


};

#endif // BOARD_H
