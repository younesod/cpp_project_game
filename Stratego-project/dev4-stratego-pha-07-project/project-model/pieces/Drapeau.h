#ifndef DRAPEAU_H
#define DRAPEAU_H
#include "Piece.h"

/**
 * @brief La class Drapeau est une des pièces du jeu.
 * Herite de la classe Piece.
 */
class Drapeau:public Piece{
public:
    /**
     * @brief Drapeau constructeur,
     * qui permet de mettre une couleur sur la pièce.
     * @param colorPiece c'est la couleur du joueur
     */
    Drapeau(PlayerColor colorPiece);

};


//-----------------IMPLEMENTATION---------------------------//



inline Drapeau::Drapeau(PlayerColor colorPiece): Piece(0,colorPiece,Move::STATIC)
{
}
#endif // DRAPEAU_H
