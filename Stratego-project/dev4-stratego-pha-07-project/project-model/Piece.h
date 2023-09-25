#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string.h>
#include "PlayerColor.h"
#include "Move.h"

using namespace std;
class Square;
/**
 * @brief La class Piece est une piece du jeu.
 */
class Piece {
private:
    int symbol;
    PlayerColor colorPiece;
    Move typeMove;
    bool visible;
    bool isPut;
public:

    Piece() = delete;
    /**
     * @brief Constructeur de la class Piece, permet de mettre un symbot,
     * colorer et le nombre de pas que peut faire la piece.
     * @param symbol le symbol permet de le distinguer des autres pièces.
     * @param colorPiece ajout une couleur a la pièce
     * @param nbMove nombre de pas que peut faire la pièce.
     */
    Piece(int symbol,PlayerColor colorPiece, Move typeMove);

    /**
     * @brief getSymbol
     * @return retourne le symbol
     */
     int getSymbol() const;


    /**
     * @brief getColorPiece
     * @return retourne la couleur
     */
    PlayerColor getColorPiece() const;

    /**
     * @brief getNbMove
     * @return retourne le nombre de pas
     */
    Move getTypeMove() const;

    /**
     * @brief isStronger
     * @param anotherOne position de la piece ennemie
     * @return retourne true si this.piece peut battre la piece ennemie (anotherOne) sinon false
     */
    bool isStronger(Piece *anotherOne);

    /**
     * @brief hasSameSymbol
     * @param anotherOne position de la pièce ennemie
     * @return retourne true si la piece de l'utilisateur et la pièce de l'ennemie sont égaux
     */
    bool hasSameSymbol(Piece *anotherOne);

    /**
     * @brief isEclaireur
     * @return retourne true si la pièce est un éclaireur sinon false
     */
    bool isEclaireur() const;

    /**
     * @brief setVisible permet de rendre la pièce visible
     */
    void toggleVisibility();

    /**
     * @brief getVisible
     * @return retourne true si la pièce est visible sinon false
     */
    bool getVisible() const;

    /**
     * @brief operator ==
     * @param pos une pièce
     * @return retourne true si le symbol, la couleur et le nombre de pas
     * sont égaux sinon false.
     */
    bool operator==(const Piece &pos) const;

    /**
     * @brief getIsPut
     * @return retourne le boolean de l'attribut isPut
     */
    bool getIsPut() const;

    /**
     * @brief setIsPut permet de modifier l'attribut isPut
     * @param newIsPut un boolean
     */
    void setIsPut(bool newIsPut);
};

//-----------------IMPLEMENTATION---------------------------//


inline bool Piece::getIsPut() const
{
    return isPut;

}

inline void Piece::setIsPut(bool newIsPut)
{
    isPut = newIsPut;
}

inline Piece::Piece(int symbol, PlayerColor colorPiece, Move typeMove): symbol(symbol),colorPiece(colorPiece),
  typeMove(typeMove),visible(false),isPut(false)
{
    if(symbol <0){
        throw runtime_error("the symbol must be a valid symbol (check the rules)");
    }
}

inline int Piece::getSymbol()const
{
    return this->symbol;
}

inline PlayerColor Piece::getColorPiece() const
{
    return this->colorPiece;
}

inline Move Piece::getTypeMove()const
{
    return this->typeMove;
}

inline bool Piece::isStronger(Piece *anotherOne)
{
    if((this->symbol == 3 && anotherOne->getSymbol()==11) ||
            (this->symbol == 1 && anotherOne->getSymbol() == 10)){
        return true;
    }else{
        return this->symbol > anotherOne->getSymbol();
    }

}

inline bool Piece::hasSameSymbol(Piece *anotherOne)
{
    return this->symbol==anotherOne->getSymbol();
}

inline bool Piece::isEclaireur() const
{
    return this->symbol==2 && this->typeMove==Move::INFINITE;
}

inline void Piece::toggleVisibility()
{
    visible = !visible;
}

inline bool Piece::getVisible() const{
    return this->visible;
}

inline bool Piece::operator==(const Piece &anotherPiece)const
{
    return this->symbol==anotherPiece.getSymbol() && this->colorPiece==anotherPiece.getColorPiece() && this->typeMove==anotherPiece.getTypeMove();
}
#endif // PIECE_H








