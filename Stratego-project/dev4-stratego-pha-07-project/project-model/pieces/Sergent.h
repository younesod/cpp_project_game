#ifndef SERGENT_H
#define SERGENT_H
#include "Piece.h"
#include "Move.h"

/**
 * @brief La class Sergent est une des pièces du jeu.
 * Herite de la classe Piece.
 */
class Sergent:public Piece{
public:
    /**
     * @brief Sergent constructeur,
     * qui permet de mettre une couleur sur la pièce.
     * @param colorPiece c'est la couleur du joueur
     */
    Sergent(PlayerColor colorPiece);
};


//-----------------IMPLEMENTATION---------------------------//

inline Sergent::Sergent(PlayerColor colorPiece): Piece(4,colorPiece,Move::NORMAL)
{

}
#endif // SERGENT_H
