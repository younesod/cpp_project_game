#ifndef POSITION_H
#define POSITION_H
#include <iostream>
#include "Direction.h"
using namespace std;
/**
 * @brief La class Position sert a placer
 * les pièces dans le tableau.
 */
class Position{

private:
    int row;
    int column;
public:


    /**
     * @brief Constructeur de la class Position
     * @param row la ligne
     * @param column la colonne
     */
    Position(int row, int column);
    Position() = default;

    /**
     * @brief nextPosition modification de la position selon la direction
     * @param dir une direction
     * @return retourne une position
     */
    Position nextPosition(const Direction& dir);

    /**
     * @brief nextPosition modification de la position selon la direction
     * @param dir une direction
     * @param nbSteps un nombre
     * @return retourne une position et l'objet ne peut pas être modifié car const
     */
    const Position nextPosition(const Direction &dir, const int &nbSteps) const;

    /**
     * @brief getRow
     * @return retourne la ligne
     */
    int getRow() const;

    /**
     * @brief setRow ajoute le numero d'une ligne
     * @param newRow un nombre
     */
    void setRow(int newRow);

    /**
     * @brief getColumn
     * @return retourne la couleur
     */
    int getColumn() const;

    /**
     * @brief setColumn ajoute le numero d'une colonne
     * @param newColumn un nombre
     */
    void setColumn(int newColumn);

    /**
     * @brief operator == vérifie deux position si elles sont égaux
     * @param pos une position
     * @return retourne true si la position this est egal a pos sinon false
     */
    bool operator==(Position &pos);
};

inline Position::Position(int row, int column){
    this->row = row;
    this->column = column;
}
inline Position Position::nextPosition(const Direction& dir){
    int row = this->row;
    int col = this->column;
    if(dir==Direction::SOUTH) row+=1;
    else if(dir==Direction::NORTH) row-=1;
    else if(dir==Direction::EAST) col+=1;
    else if(dir==Direction::WEST) col-=1;
    return Position(row,col);
}
inline const Position Position::nextPosition(const Direction &dir,const int &nbSteps)const{
    int row = this->row;
    int col = this->column;
    if(dir==Direction::SOUTH) row+=nbSteps;
    else if(dir==Direction::NORTH) row-=nbSteps;
    else if(dir==Direction::EAST) col+=nbSteps;
    else if(dir==Direction::WEST) col-=nbSteps;
    return Position(row,col);
}


inline int Position::getRow() const
{
    return row;
}

inline void Position::setRow(int newRow)
{
    row = newRow;
}

inline int Position::getColumn() const
{
    return column;
}

inline void Position::setColumn(int newColumn)
{
    column = newColumn;
}

inline bool Position::operator==(Position &pos)
{
    return this->row==pos.getRow() && this->column==pos.getColumn();
}




#endif // POSITION_H


