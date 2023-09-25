#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "Piece.h"
#include "Position.h"
#include "pieces/Bombe.h"
#include "pieces/General.h"
#include "pieces/Marechal.h"
#include "pieces/Colonel.h"
#include "pieces/Major.h"
#include "pieces/Commandant.h"
#include "pieces/Lieutenant.h"
#include "pieces/Sergent.h"
#include "pieces/Demineur.h"
#include "pieces/Eclaireur.h"
#include "pieces/Espionne.h"
#include "pieces/Drapeau.h"

/**
 * @brief La class Deck est l'endroit où l'on stock les pèces
 * perdu et les pièces encore en jeu.
 */
class Deck{
private:
    vector<Piece> pieces;
    vector<Position> position;
    Piece *flag;
    int compteur;
public:
    /**
     * @brief Constructeur de la class Deck.
     * @param playable les pièces qui sont encore en jeu.
     * @param nonPlayable les pièces qui ne sont plus en jeu.
     */
    Deck();

    /**
     * @brief getPlayable
     * @return renvoie le vector playable.
     */
    const vector<Piece *> &getPiecePlaced() const;
    /**
     * @brief add the piece in the non playble deck
     * @param piece
     */
    void add(Piece piece);

    /**
     * @brief add la pièce dans le stockPiece avec le symbole et ajoute une ref à cette pièce dans les playables
     * et puis dans les nonPlayable on supprime le pointer
     * @param symbol un nombre le symbole du boutton
     */
    void add(int symbol);
    /**
     * @brief singlePiece
     * @return true si la piece contient juste une piece 'Drapeau' sinon faux
     */
    bool singlePiece() const;

    /**
     * @brief empty
     * @return retourne true si le vector playable est vide sinon false
     */
    bool empty();
    /**
     * @brief legalMove sert à ce que la pièce ne fasse pas plus de 3 aller-retour consécutif
     * @param start Position de départ
     * @return retourne true si la pièce n'a pas fait plus de trois alle retour sinon false
     */
    bool legalMove(Position start);

    /**
     * @brief intialize le deck par default avec toutes les pièces
     * @param color couleur du joueur
     */
    void initStockPiecesDefault(PlayerColor color);
    /**
     * @brief initStockPieces met dans le vector "piece" les pieces d'un joueur
     * @param color couleur du joueur
     */
    void initStockPieces(PlayerColor color);
    /**
     * @brief contains permet de savoir si une pièce est dans le vecteur
     * @param piece une piece
     * @return retourne true si la pièce est trouvée
     */
    bool contains(int symbol);

    /**
     * @brief sizeDeckPlayer
     * @return renvoie la taille du vector piecePlaced
     */
    int sizeDeckPlayer();

    /**
     * @brief getPiece
     * @param pos un nombre
     * @return retourne la piece à l'index donée
     */
    Piece *getPiece(int pos);

    /**
     * @brief getPieces
     * @return renvoie le vector pieces
     */
    const vector<Piece> &getPieces() const;

    /**
     * @brief addFlag cherche le flag dans le vector et l'ajoute en attribut
     * @param symbol un nombre
     */
    void addFlag(int symbol);

    /**
     * @brief getFlag
     * @return renvoie le drapeau
     */
    Piece *getFlag() const;

    /**
     * @brief selectPiece selectionne la pièce dans le stockPiece avec le symbole et ajoute une ref à cette pièce dans les playables
     * et puis dans les nonPlayable on supprime le pointer
     * @param valeurSymbole un nombre
     */
    Piece * selectPiece(int symbol);

    /**
     * @brief setFlag permet d'ajouter un nouveau drapeau à l'attrivut flag
     * @param newFlag un nouveau drapeau
     */
    void setFlag(Piece *newFlag);

    /**
     * @brief getPieceDeck
     * @param symbol le symbole d'une piece
     * @return renvoie une piece du tableau
     */
    Piece * getPieceDeck(int symbol);

};
//-----------------IMPLEMENTATION---------------------------//
inline Deck::Deck() :  pieces(), position(), compteur(0)
{}

inline const vector<Piece> &Deck::getPieces() const
{
    return pieces;
}

inline Piece *Deck::getFlag() const
{
    return flag;
}

inline Piece * Deck::selectPiece(int symbol)
{
    Piece *p;
    size_t i=0;
    bool putted=false;
    while(!putted && i<pieces.size()){
        if(pieces.at(i).getSymbol()==symbol && !pieces.at(i).getIsPut()){
            pieces.at(i).setIsPut(true);
            putted=true;
            p=&pieces.at(i);
            return p;
        }
        i++;
    }
    return nullptr;
}


inline void Deck::setFlag(Piece *newFlag)
{
    flag = newFlag;
}


inline void Deck::add(Piece piece)
{
    this->selectPiece(piece.getSymbol());
}
inline void Deck::add(int symbol){
    this->selectPiece(symbol);
}
inline void Deck::addFlag(int symbol)
{
    bool found=false;
    size_t i=0;
    while (!found && i<pieces.size()){
        if(pieces.at(i).getSymbol()==symbol){
            this->flag=&pieces.at(i);
            found=true;
        }
        i++;
    }

}
inline bool Deck::legalMove(Position start){

    if(this->position.size() > 4){
        this->position.clear();
    }

    this->position.push_back(start);
    if(this->position.size() == 4){

        if((this->position[0] == this->position[2]) && (this->position[1] == this->position[3])){
            return false;
        }
        return true;
    }

    return true;
}


inline bool Deck::singlePiece() const{
    int cpt=0;
    for(auto & piece : pieces){
        if(!piece.getIsPut()){
            cpt++;
        }
    }
    return cpt==1;
}

inline bool Deck::empty()
{
    bool empty=false;
    for(auto & piece: pieces){
        if(piece.getIsPut()==false){
            empty=true;
            return empty;
        }
    }
    return empty;
}

inline bool Deck::contains(int symbol)
{
    bool found=false;
    size_t i=0;
    while(!found && i<this->pieces.size()){
        if(this->pieces.at(i).getSymbol()==symbol && this->pieces.at(i).getIsPut()) found=true;
    }
    return found;
}

inline int Deck::sizeDeckPlayer()
{
    return this->pieces.size();
}

inline Piece *Deck::getPiece(int pos)
{
    return &this->pieces.at(pos);
}
inline void Deck::initStockPieces(PlayerColor color){
    this->pieces.push_back(Marechal(color));
    this->pieces.push_back(General(color));
    this->pieces.push_back(Colonel(color));
    this->pieces.push_back(Colonel(color));
    this->pieces.push_back(Major(color));
    this->pieces.push_back(Major(color));
    this->pieces.push_back(Major(color));
    this->pieces.push_back(Commandant(color));
    this->pieces.push_back(Commandant(color));
    this->pieces.push_back(Commandant(color));
    this->pieces.push_back(Commandant(color));
    this->pieces.push_back(Lieutenant(color));
    this->pieces.push_back(Lieutenant(color));
    this->pieces.push_back(Lieutenant(color));
    this->pieces.push_back(Lieutenant(color));
    this->pieces.push_back(Sergent(color));
    this->pieces.push_back(Sergent(color));
    this->pieces.push_back(Sergent(color));
    this->pieces.push_back(Sergent(color));
    this->pieces.push_back(Demineur(color));
    this->pieces.push_back(Demineur(color));
    this->pieces.push_back(Demineur(color));
    this->pieces.push_back(Demineur(color));
    this->pieces.push_back(Demineur(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Espionne(color));
    this->pieces.push_back(Drapeau(color));
    this->pieces.push_back(Bombe(color));
    this->pieces.push_back(Bombe(color));
    this->pieces.push_back(Bombe(color));
    this->pieces.push_back(Bombe(color));
    this->pieces.push_back(Bombe(color));
    this->pieces.push_back(Bombe(color));
}

inline void Deck::initStockPiecesDefault(PlayerColor color)
{
    this->pieces.push_back(Bombe(color));
    this->pieces.push_back(Bombe(color));
    this->pieces.push_back(Bombe(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Demineur(color));
    this->pieces.push_back(Lieutenant(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Bombe(color));
    this->pieces.push_back(Bombe(color));
    this->pieces.push_back(Bombe(color));

    this->pieces.push_back(Espionne(color));
    this->pieces.push_back(Lieutenant(color));
    this->pieces.push_back(Sergent(color));
    this->pieces.push_back(Sergent(color));
    this->pieces.push_back(Commandant(color));
    this->pieces.push_back(Commandant(color));
    this->pieces.push_back(Sergent(color));
    this->pieces.push_back(Sergent(color));
    this->pieces.push_back(Lieutenant(color));
    this->pieces.push_back(Lieutenant(color));

    this->pieces.push_back(Marechal(color));
    this->pieces.push_back(General(color));
    this->pieces.push_back(Drapeau(color));
    this->pieces.push_back(Commandant(color));
    this->pieces.push_back(Commandant(color));
    this->pieces.push_back(Major(color));
    this->pieces.push_back(Major(color));
    this->pieces.push_back(Major(color));
    this->pieces.push_back(Colonel(color));
    this->pieces.push_back(Colonel(color));

    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Demineur(color));
    this->pieces.push_back(Demineur(color));
    this->pieces.push_back(Demineur(color));
    this->pieces.push_back(Demineur(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Eclaireur(color));
    this->pieces.push_back(Eclaireur(color));




    if(color==RED){
        this->selectPiece(11);
        this->selectPiece(11);
        this->selectPiece(11);
        this->selectPiece(2);
        this->selectPiece(3);
        this->selectPiece(5);
        this->selectPiece(2);
        this->selectPiece(11);
        this->selectPiece(11);
        this->selectPiece(11);

        this->selectPiece(10);
        this->selectPiece(9);
        this->selectPiece(0);
        this->selectPiece(6);
        this->selectPiece(6);
        this->selectPiece(7);
        this->selectPiece(7);
        this->selectPiece(7);
        this->selectPiece(8);
        this->selectPiece(8);

        this->selectPiece(1);
        this->selectPiece(5);
        this->selectPiece(4);
        this->selectPiece(4);
        this->selectPiece(6);
        this->selectPiece(6);
        this->selectPiece(4);
        this->selectPiece(4);
        this->selectPiece(5);
        this->selectPiece(5);

        this->selectPiece(2);
        this->selectPiece(2);
        this->selectPiece(2);
        this->selectPiece(3);
        this->selectPiece(3);
        this->selectPiece(3);
        this->selectPiece(3);
        this->selectPiece(2);
        this->selectPiece(2);
        this->selectPiece(2);


    }
    else if(color==BLUE){
        this->selectPiece(2);
        this->selectPiece(2);
        this->selectPiece(2);
        this->selectPiece(3);
        this->selectPiece(3);
        this->selectPiece(3);
        this->selectPiece(3);
        this->selectPiece(2);
        this->selectPiece(2);
        this->selectPiece(2);


        this->selectPiece(10);
        this->selectPiece(9);
        this->selectPiece(0);
        this->selectPiece(6);
        this->selectPiece(6);
        this->selectPiece(7);
        this->selectPiece(7);
        this->selectPiece(7);
        this->selectPiece(8);
        this->selectPiece(8);

        this->selectPiece(11);
        this->selectPiece(11);
        this->selectPiece(11);
        this->selectPiece(2);
        this->selectPiece(3);
        this->selectPiece(5);
        this->selectPiece(2);
        this->selectPiece(11);
        this->selectPiece(11);
        this->selectPiece(11);

        this->selectPiece(1);
        this->selectPiece(5);
        this->selectPiece(4);
        this->selectPiece(4);
        this->selectPiece(6);
        this->selectPiece(6);
        this->selectPiece(4);
        this->selectPiece(4);
        this->selectPiece(5);
        this->selectPiece(5);
    }


}



#endif // DECK_H




