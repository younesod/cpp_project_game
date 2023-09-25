#ifndef MAJOR_H
#define MAJOR_H
#include "Piece.h"
#include "Move.h"

/**
 * @brief La class Major est une des pièces du jeu.
 * Herite de la classe Piece.
 */
class Major:public Piece{
public:
    /**
     * @brief Major constructeur,
     * qui permet de mettre une couleur sur la pièce.
     * @param colorPiece c'est la couleur du joueur
     */
    Major(PlayerColor colorPiece);

};



//-----------------IMPLEMENTATION---------------------------//

inline Major::Major(PlayerColor colorPiece):Piece(7,colorPiece,Move::NORMAL)
{

}
#endif // MAJOR_H
