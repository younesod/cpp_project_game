#ifndef ESPIONNE_H
#define ESPIONNE_H
#include "Piece.h"

/**
 * @brief La class Espionne est une des pièces du jeu.
 * Herite de la classe Piece.
 */
class Espionne:public Piece{
public:
    /**
     * @brief Espionne constructeur,
     * qui permet de mettre une couleur sur la pièce.
     * @param colorPiece c'est la couleur du joueur
     */
    Espionne(PlayerColor colorPiece);

};



//-----------------IMPLEMENTATION---------------------------//

inline Espionne::Espionne(PlayerColor colorPiece): Piece(1,colorPiece,Move::NORMAL)
{

}
#endif // ESPIONNE_H
