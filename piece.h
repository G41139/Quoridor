#ifndef PIECE_H
#define PIECE_H
#include <utility>
#include <string>
#include "side.h"
#include "direction.h"
#include "alignement.h"
using namespace std;

//Définition de la classe Piece qui représente soit un mur ou soit un Pion
/*!
 * \class Pièce
 * \brief Classe qui représente une pièce du plateau de jeu qui peut être un pion ou un mur
 * par héritage.
 * \author Kasay-Temsamani.
 * \version 1.0
 * \date 2016
 */
class Piece
{
public:
    /*!
         * \brief ~Piece Déstructeur par défaut de Piece.
         */
    virtual ~Piece()=default;
    /*!
         * \brief Piece Constructeur par défaut de Piece.
         */
    Piece()=default;
    /*!
         * \brief getPosition Méthode virtuelle pure donnant la position
         *  que pion et/ou mur doivent implémenter.
         */
    virtual pair<int,int> getPosition()=0;
    /*!
         * \brief setPosition Méthode virtuelle pure permettant de changer la position
         * que pion et/ou mur doivent implémenter.
         * \param pos La position souhaitée: ligne, colonne.
         */
    virtual void setPosition(pair <int,int> pos)=0;
    /*!
         * \brief to_string Méthode virtuelle pure permettant d'obtenir la représentation textuelle
         *  d'une pièce que pion et/ou mur doivent implémenter.
         */
   virtual string toString()=0;
    /*!
         * \brief isEmpty Méthode virtuelle pure permettant de savoir si une pièce est vide ou pas
         * que pion et/ou mur doivent implémenter.
         * \return true si est vide, sinon false.
         */
   virtual bool isEmpty()=0;
   virtual void setSide(Side side)=0;
   virtual void setPlaced()=0;
   virtual void clear()=0;
};

//Définition de la classe Pawn qui définit un pion
//Définition de la classe Pawn qui définit un pion
/*!
 * \class Pawn
 * \brief Classe qui représente une pièce du plateau de jeu qui est un pion par héritage.
 * \author Kasay-Temsamani.
 * \version 1.0
 * \date 2016
 */
class Pawn : public Piece
{
private:
    Side side_;
    pair <int,int> position_;
    Direction direction_;
    bool isPlaced_=false;
public:
    /*!
         * \brief Pawn Constructeur par défaut d'un pion.
         */
    Pawn();
    /*!
         * \brief Pawn Constructeur d'un pion.
         * \param side Le bord d'où part le pion ou le joueur initialement.
         * \param pos La position courante du pion.
         */
    Pawn (Side side,pair <int,int> pos);
    /*!
         * \brief to_string Permet d'obtenir la représentation textuelle d'un pion 'P' si il n'y a
         * aucun joueur dans la pièce (position) ou alors "1", "2", "3", "4", selon que la position
         * est respectivement occupée par le joueur 1, 2, 3 ou 4.
         */
    string toString();
    /*!
         * \brief setPosition Mutateur, permet de changer la position d'un pion.
         * \param pos La position souhaitée: ligne, colonne.
         */
    inline void setPosition(pair <int,int> pos){
        position_=pos;
    }
    /*!
         * \brief getSide Accesseur en lecture du bord d'origine du pion ou joueur.
         * \return Le bord d'origine.
         */
    inline Side getSide(){
        return side_;
    }
    /*!
         * \brief getPosition Accesseur en lecture de la position d'un pion.
         * \return La position: ligne, colonne.
         */
    inline pair <int,int> getPosition(){
        return position_;
    }
    /*!
        * \brief isEmpty Méthode permettant de savoir si un pion est placé ou pas.
        * \return true Si aucun pion n'est placé, sinon false.
        */
    inline bool isEmpty(){
        return !isPlaced_;
    }
    /*!
         * \brief setSide Mutateur, permet de changer le bord d'origine du pion ou joueur.
         */
    inline void setSide(Side side){
        side_=side;
    }
    /*!
         * \brief setPlaced Mutateur, permet de placer un joeur ou pion à la position courante.
         */
    inline void setPlaced(){
        isPlaced_=true;
    }
    inline void clear(){
        isPlaced_=false;
    }
};


//Définition de la class Wall qui définit un mur
//Définition de la class Wall qui définit un mur
/*!
 * \class Wall
 * \brief Classe qui représente une pièce du plateau de jeu qui est un mur par héritage.
 * \author Kasay-Temsamani.
 * \version 1.0
 * \date 2016
 */
class Wall : public Piece
{
private:
    pair <int,int> position_;
    bool isPlaced_=false;
    Alignement alignement_;

public:
    /*!
         * \brief Wall Constructeur par défaut d'un mur.
         */
    Wall();
    /*!
         * \brief Wall Constructeur d'un mur, celui-ci va de gauche à droite et de haut en bas selon
         * qu'il est aligné horizontalement ou verticalement.
         * \param pos La position origine du mur(ligne,colonne).
         * \param alignement L'alignement horizontal ou vertical du mur.
         */
    Wall(pair <int,int> pos, Alignement alignement);
    /*!
         * \brief to_string Permet d'obtenir la représentation textuelle d'un mur selon qu'il est
         * placé "#" ou pas "*"
         */
    string toString();
    /*!
         * \brief setWall Mutateur, permet de placer un mur.
         */
    inline void setPlaced(){
        isPlaced_=true;
    }
    /*!
         * \brief setPosition Mutateur, permet de changer la position d'un mur.
         * \param pos La position souhaitée: ligne, colonne.
         */
    inline void setPosition(pair <int,int> pos){
        position_=pos;
    }
    /*!
         * \brief getPosition Accesseur en lecture de la position d'un mur.
         * \return La position: ligne, colonne.
         */
    inline pair <int,int> getPosition(){
        return position_;
    }
    /*!
         * \brief isEmpty Méthode permettant de savoir si un mur est placé ou pas.
         * \return true Si aucun mur n'est placé, sinon false.
         */
    inline bool isEmpty(){
        return !isPlaced_;
    }
    inline void clear(){
        isPlaced_=false;
    }
    inline void setSide(Side side){
        return ;
    }
};

#endif // PIECE_H
