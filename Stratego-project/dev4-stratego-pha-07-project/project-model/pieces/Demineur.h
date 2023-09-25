#ifndef DEMINEUR_H
#define DEMINEUR_H
#include "Piece.h"

/**
 * @brief La class Demineur est une des pièces du jeu.
 * Herite de la classe Piece.
 */
class Demineur:public Piece{
public:
    /**
     * @brief Demineur constructeur,
     * qui permet de mettre une couleur sur la pièce.
     * @param colorPiece c'est la couleur du joueur
     */
    Demineur(PlayerColor colorPiece);

};



//-----------------IMPLEMENTATION---------------------------//

inline Demineur::Demineur(PlayerColor colorPiece): Piece(3,colorPiece,Move::NORMAL)
{

}
#endif // DEMINEUR_H
