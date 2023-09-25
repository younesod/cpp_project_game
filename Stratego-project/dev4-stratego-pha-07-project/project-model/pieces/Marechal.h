#ifndef MARECHAL_H
#define MARECHAL_H
#include "Piece.h"
#include "Move.h"

/**
 * @brief La class Marechal est une des pièces du jeu.
 * Herite de la classe Piece.
 */
class Marechal:public Piece{
public:
    /**
     * @brief Marechal constructeur,
     * qui permet de mettre une couleur sur la pièce.
     * @param colorPiece c'est la couleur du joueur
     */
    Marechal(PlayerColor colorPiece);

};



//-----------------IMPLEMENTATION---------------------------//

inline Marechal::Marechal(PlayerColor colorPiece): Piece(10,colorPiece,Move::NORMAL)
{

}
#endif // MARECHAL_H
