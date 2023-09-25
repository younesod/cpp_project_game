#ifndef COMMANDANT_H
#define COMMANDANT_H
#include "Piece.h"

/**
 * @brief La class Commandant est une des pièces du jeu.
 * Herite de la classe Piece.
 */
class Commandant:public Piece{
public:
    /**
     * @brief Commandant constructeur,
     * qui permet de mettre une couleur sur la pièce.
     * @param colorPiece c'est la couleur du joueur
     */
    Commandant(PlayerColor colorPiece);

};

//-----------------IMPLEMENTATION---------------------------//



inline Commandant::Commandant(PlayerColor colorPiece):Piece(6,colorPiece,Move::NORMAL)
{

}
#endif // COMMANDANT_H
