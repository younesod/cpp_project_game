#ifndef LIEUTENANT_H
#define LIEUTENANT_H
#include "Piece.h"
#include "Move.h"

/**
 * @brief La class Lieutenant est une des pièces du jeu.
 * Herite de la classe Piece.
 */
class Lieutenant:public Piece{
public:
    /**
     * @brief Lieutenant constructeur,
     * qui permet de mettre une couleur sur la pièce.
     * @param colorPiece c'est la couleur du joueur
     */
    Lieutenant(PlayerColor colorPiece);

};


//-----------------IMPLEMENTATION---------------------------//

inline Lieutenant::Lieutenant(PlayerColor colorPiece):  Piece(5,colorPiece,Move::NORMAL)
{

}
#endif // LIEUTENANT_H
