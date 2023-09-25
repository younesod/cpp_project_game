#ifndef GENERAL_H
#define GENERAL_H
#include "Piece.h"
#include "Move.h"

/**
 * @brief La class General est une des pièces du jeu.
 * Herite de la classe Piece.
 */
class General:public Piece{
public:
    /**
     * @brief General constructeur,
     * qui permet de mettre une couleur sur la pièce.
     * @param colorPiece c'est la couleur du joueur
     */
    General(PlayerColor colorPiece);

};


//-----------------IMPLEMENTATION---------------------------//

inline General::General(PlayerColor colorPiece): Piece(9,colorPiece,Move::NORMAL)
{

}
#endif // GENERAL_H
