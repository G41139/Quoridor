#ifndef GAME
#define GAME
#include "player.h"
#include "board.h"
#include "string"
#include "sujetDObservation.h"
using namespace std;
/*!
 *\mainpage Quoridor
 *
 * La documentation ici présentée concerne une implémentation console complète en C++ du jeu Quoridor .
 *
 * Il s'agit d'un jeu interactif qui se joue à deux ou à quatre.
 *
 * Avant de lire la suite, il est conseillé de prendre connaissance des règles du jeu.
 *
 * <b> Spécificités de l'implémentation </b>
 *
 * Les règles officielles du jeu ont ici été modifiées en un endroit.
 *
 * La taille du plateau de jeu est laissée à la discrétion de l'utilisateur.
 *
 * Les joueurs peuvent décider eux même du choix de la taille du plateau de jeu.
 *
 * Le nombre de murs dépend de la taille du plateau de jeu.
 *
 * <b>Aspects techniques</b>
 *
 * La classe principale est Game. Elle gère une partie de jeu.
 *
 * Elle se sert de la classe Board pour le déplacement et les insertions.
 *
 * Par ailleurs, les joueurs sont des instances de la classe Player.
 *
 * Le gagnant est celui qui aura atteint le bord opposé à celui d'origine.
 *
 * La partie s'arrête lorsqu'il y'a un gagnant ou lorsque il y a un match nul.
 *
 * \author Kasay-Temsamani.
 *
 * \version 1.0
 *
 * \date 2016
 */


/*!
 *\class Game
 *\brief Classe moteur du Jeu. Elle contient toute la logique métier permettant de jouer au jeu Quoridor.
 * \author Kasay-Temsamani.
 * \version 1.0
 * \date 2016
 */
class Game : public SujetDObservation{
    private :
        int nbPlayer_;
        Board board_;
        vector <Player*> listPlayer_;
        bool gameOver_=false;
    public:
        /*!
                * \brief Game Le constructeur de Game.
                * \param nbPlayer Le nombre de joueurs.
                * \param size La taille du plateau de jeu.
                */
        Game(int size);

        /*!
                 * \brief addPlayer Méthode permettant d'ajouter 2 joueurs supplémentaires si la partie est à 4.
                 * \param p1 Le 1er joueur supplémentaire.
                 * \param p2 Le 2eme joueur supplémentaire.
                 */
        void addPlayer();
        /*!
         * \brief play Méthode de jeu permettant au joueur courant de se déplacer, d'insérer des murs.
         * Cette méthode appelle les méthodes privées de la classe Board.
         * de tester si le joueur a gagné ou pas,si la partie se termine par un match nul.
         * et le passage au joueur suivant le cas échéant.
         */
        void play();
        /*!
         * \brief askPositionWall Méthode de lecture de la position souhaitée pour placer un mur.
         * \return La position du mur selon les conventions de positionnement.
         */
        pair<int, int> askPositionWall();
        /*!
                 * \brief removeWall Méthode pour enlever un mur.
                 * \param pos la position du mur (origine) à enlever.
                 * \param align L'alignement du mur.
                 */
        void removeWall(pair<int, int> pos, Alignement align);
        /*!
                * \brief verifyAllPlayerWay Méthode vérifiant si chaque joueur possède toujours un chemin
                * vers une case de son bord.
                * \param p1 Le premier joueur.
                * \param p2 Le deuxième joueur.
                * \return true Si vrai, sinon false.
                */
        bool verifyAllPlayerWay(Player *p1, Player *p2);
        /*!
                 * \brief getBoard Accesseur en lecture du plateau de jeu.
                 * \return Le plateau de jeu.
                 */
        inline Board getBoard(){
            return board_;
        }
        /*!
                 * \brief getListPlayer Accesseur en lecture de la liste de joueur.
                 * \return La liste de joueur.
                 */
        inline vector <Player*> getListPlayer(){
            return listPlayer_;
        }
        /*!
                 * \brief getNbPlayer Accesseur en lecture du nombre de joueur dans la partie.
                 * \return Le nombre de joueur dans la partie.
                 */
        inline int getNbPlayer(){
            return nbPlayer_;
        }
        /*!
                 * \brief gameOver méthode permettant de mettre fin à la partie.
                 */
        inline void gameOver(){
            gameOver_=true;
        }

        /*!
                 * \brief playerHasWon Méthode permettant de savoir si un joueur a gagné ou pas.
                 * \param p Le joueur courant.
                 * \return true si la partie est finie, sinon false.
                 */
        bool playerHasWon(Player *p);
        bool isOver(){
            return gameOver_;
        }
        void movePawn(Direction direction, Pawn *pawn);
        void placeWall (pair <int,int> pos, Alignement align, Player *player);
        void setSize(int size){

        }
};

#endif // GAME

