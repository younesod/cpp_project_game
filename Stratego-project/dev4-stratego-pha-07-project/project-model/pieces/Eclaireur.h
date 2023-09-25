#ifndef ECLAIREUR_H
#define ECLAIREUR_H
#include "Piece.h"

/**
 * @brief La class Eclaireur est une des pièces du jeu.
 * Herite de la classe Piece.
 */
class Eclaireur:public Piece{
public:
    /**
     * @brief Eclaireur constructeur,
     * qui permet de mettre une couleur sur la pièce.
     * @param colorPiece c'est la couleur du joueur
     */
    Eclaireur(PlayerColor colorPiece);

};


//-----------------IMPLEMENTATION---------------------------//



inline Eclaireur::Eclaireur(PlayerColor colorPiece): Piece(2,colorPiece,Move::INFINITE)
{

}
#endif // ECLAIREUR_H
