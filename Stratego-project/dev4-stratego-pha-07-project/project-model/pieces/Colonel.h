#ifndef COLONEL_H
#define COLONEL_H
#include "Piece.h"

/**
 * @brief La class Colonel est une des pièces du jeu.
 * Herite de la classe Piece.
 */
class Colonel:public Piece{
public:
    /**
     * @brief Colonel constructeur,
     * qui permet de mettre une couleur sur la pièce.
     * @param colorPiece c'est la couleur du joueur
     */
    Colonel(PlayerColor colorPiece);

};



//-----------------IMPLEMENTATION---------------------------//


inline Colonel::Colonel(PlayerColor colorPiece): Piece(8,colorPiece,Move::NORMAL)
{
}
#endif // COLONEL_H
