#ifndef BOMBE_H
#define BOMBE_H
#include "Piece.h"
#include "Move.h"

/**
 * @brief La class Bombe est une des pièces du jeu.
 * Herite de la classe Piece.
 */
class Bombe:public Piece{
public:
    /**
     * @brief Bombe constructeur,
     * qui permet de mettre une couleur sur la pièce.
     * @param colorPiece c'est la couleur du joueur
     */
    Bombe(PlayerColor colorPiece);

};



//-----------------IMPLEMENTATION---------------------------//
inline Bombe::Bombe(PlayerColor colorPiece) :Piece(11,colorPiece,Move::STATIC)
{
}
#endif // BOMBE_H


