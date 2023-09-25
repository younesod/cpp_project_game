#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <array>
#include "Square.h"
#include "Position.h"
#include "Deck.h"
#include "Piece.h"
#include "Player.h"
#include <utility>

/**
 * @brief La class Board, représente l'endroit où l'on
 * peut poser nos pièces.
 */
class Board{

private:
    array<array<Square,10>,10> squares;
public:
    /**
     * @brief Constructeur de Board.
     */
    Board()=default;


    /**
     * @brief vérifie si une position se trouve dans le plateau
     * @param position
     * @return bool
     */
    bool isInside(const Position& position)const ;

    /**
     * @brief initBoard initialise le tableau en mettant l'eau et la terre
     */
    void initBoard();

    /**
     * @brief getSquare
     * @param position une position
     * @return retourne le square à la position donnée et ne peut pas être modifiée car const
     */
    const Square &getSquare(const Position &position) const;

    /**
     * @brief getSquare
     * @param position une position
     * @return retourne le square à la position donnée
     */
    Square &getSquare(const Position &position);
    /**
     * @brief isEmpty
     * @return retourne true s'il n'y a pas de pièce dans le tableau
     */
    bool isEmpty() const;

    /**
     * @brief put met la pièce à la position donnée
     * @param piece une pièce du jeu
     * @param position une position
     */
    void put(Piece *piece, const Position &position);

    /**
     * @brief remove suprimme la pièce à la position donnée
     * @param position une position
     */
    void remove(const Position &position);

    /**
     * @brief isMyPiece permet de voir si la pièce appartient à un joueur
     * @param position une position
     * @param color couleur du joueur
     * @return retourne true si la pièce appartient bien à un joueur donné sinon false
     */
    bool isMyPiece(const Position &position, const PlayerColor &color);

    /**
     * @brief isFree permet de voir si le square est vide
     * @param position une position
     * @return retourne true si le square est vide sinon false
     */
    bool isFree(const Position &position);

    /**
     * @brief getPiece
     * @param position une position
     * @return return la piece à la position donnée
     */
    const Piece *getPiece(const Position &position) const;

    /**
     * @brief getPiece
     * @param position une position
     * @return return la piece à la position donnée et ne peut pas être modifiée car const
     */
    Piece *getPiece(const Position &position);

    /**
     * @brief setPiece met la pièce à la position donnée
     * @param piece une pièce
     * @param position une position
     */
    void setPiece(Piece *piece, const Position &position);
};

//-----------------IMPLEMENTATION---------------------------//



inline const Square& Board::getSquare(const Position &position) const
{
    if(!isInside(position)){
        throw out_of_range("The given position is not inside the board");
    }
    return this->squares[position.getRow()][position.getColumn()];
}
inline Square& Board::getSquare(const Position &position){
    return const_cast<Square&>(as_const(*this).getSquare(position));
}


inline bool Board::isInside(const Position &position)const
{
    return position.getColumn() < 10 && position.getColumn() >=0
            && position.getRow() < 10 && position.getRow() >=0;
}



inline bool Board::isEmpty() const{
    for(size_t i=0;i<10;i++){
        for(size_t j=0;j<10;j++){
            if(this->squares[i][j].getPiece() !=nullptr ){
                return false;
            }
        }
    }
    return true;
}

inline void Board::initBoard(){

    {
        for(size_t i=0;i<10;i++){
            for(size_t j=0;j<10;j++){
                if((i==4 && (j==2 || j==3 || j==6 || j==7)) ||
                        (i==5 && (j==2 || j==3 || j==6 || j==7))){
                    this->squares[i][j].setType(SquareType::WATER);
                }
            }
        }
    }
}

inline void Board::put(Piece *piece,const  Position &position)
{
    if(!isInside(position)){
        throw runtime_error("Position is outside the board, put cannot be used");
    }
    this->getSquare(position).put(piece);
}

inline void Board::remove(const Position& position)
{
    if(!isInside(position)){
        throw runtime_error("Position is outside the board, remove cannot be used");
    }
    getSquare(position).remove();
}

inline bool Board::isMyPiece(const Position &position, const PlayerColor& color)
{
    return getSquare(position).isMyPiece(color);
}

inline bool Board::isFree(const Position &position)
{
    return getSquare(position).isFree();
}

inline const Piece* Board::getPiece(const Position &position)const
{
    if(!isInside(position)){
        throw runtime_error("Position is outside the board, cannot get the Piece");
    }
    return getSquare(position).getPiece();
}

inline  Piece* Board::getPiece(const Position &position){
    return const_cast<Piece*>(as_const(*this).getPiece(position));
}


inline void Board::setPiece(Piece *piece, const Position &position)
{
    if(!isInside(position) && this->getPiece(position)!=nullptr){
        throw runtime_error("Position is outside the board, cannot get the Piece");
    }
    this->squares[position.getRow()][position.getColumn()].put(piece);
}





#endif // BOARD_H
