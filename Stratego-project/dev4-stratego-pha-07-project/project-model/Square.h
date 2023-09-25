#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include<optional>
#include "Piece.h"
#include "SquareType.h"
#include <utility>

class Piece;
/**
 * @brief la class Square est la case du tableau
 */
class Square{
private :
    Piece * piece;
    //indice
    SquareType type;
public:
    Square();

    /**
     * @brief Square
     * @param type type de square eau ou terre
     */
    Square(const SquareType type);

    /**
     * @brief getPiece
     * @return retourne la piece
     */
    const Piece *getPiece() const;

    Piece *getPiece();

    /**
     * @brief getType
     * @return retourne le SquareType
     */
    SquareType getType() const;

    /**
     * @brief put met la pièce dans le square
     * @param piece une pièce
     */
    void put(Piece *piece);

    /**
     * @brief remove met la pièce à nullopt
     */
    void remove();

    /**
     * @brief isFree
     * @return retourne true si la pièce est vide
     */
    bool isFree();

    /**
     * @brief isMyPiece
     * @param color couleur du joueur
     * @return retourne true si la pièce appartient au joueur sinon false
     */
    bool isMyPiece(const PlayerColor &color) const;

    /**
     * @brief isLand
     * @return retourne true si la pièce est 'LAND' sinon false
     */
    bool isLand();

    /**
     * @brief operator ==
     * @param anotherSquare une case du tableau
     * @return retourne true si 'this'square et anotherSquare sont égaux
     */
    bool operator==(const Square &anotherSquare) const;

    /**
     * @brief setPiece ajoute la pièce mit en paramètre
     * @param newPiece une pièce
     */
    //    void setPiece(const Piece *newPiece);
    void setType(SquareType newType);
};


//-----------------IMPLEMENTATION---------------------------//

inline Square::Square() : Square(LAND)
{}

inline Square::Square(const SquareType type) : piece(nullptr), type(type)
{}
inline const Piece *Square::getPiece() const
{
    return piece;
}

inline Piece *Square::getPiece(){
    return const_cast<Piece*>(as_const(*this).getPiece());
}

inline void Square::setType(SquareType newType)
{
    type = newType;
}


inline void Square::put(Piece *piece){
    if(!isFree()){
        throw runtime_error("The square is not free");
    }
    this->piece=const_cast<Piece*>(as_const(piece));
}

inline void Square::remove(){
    if(isFree()){
        throw runtime_error("The square is empty");
    }
    this->piece=nullptr;
}

inline bool Square::isFree(){
    return this->piece==nullptr;
}

inline bool Square::isMyPiece(const PlayerColor &color) const
{
    return this->piece!=nullptr && this->piece->getColorPiece()==color;

}

inline bool Square::isLand()
{
    return this->type==SquareType::LAND;
}

inline bool Square::operator==(const Square &anotherSquare) const
{
    return this->piece->getSymbol()==anotherSquare.getPiece()->getSymbol()
            && this->piece->getColorPiece()==anotherSquare.getPiece()->getColorPiece()
            && this->piece->getTypeMove()==anotherSquare.getPiece()->getTypeMove()
            && this->type==anotherSquare.getType();
}


inline SquareType Square::getType() const{
    return this->type;
}


#endif // SQUARE_H


