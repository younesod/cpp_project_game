#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "PlayerColor.h"
#include "Deck.h"

/**
 * @brief La class Player est dédiée aux joueurs.
 */
class Player{
private:
    PlayerColor pColor;
    Deck deckP;
    bool turnEnd;
public:
    Player()=default;
    /**
     * @brief constructeur permet de mettre une couleur pour le joueur.
     * @param pColor couleur du joueur
     */
    Player(PlayerColor pColor);

    /**
     * @brief containsFlag
     * @return retourne true si le joueur à un drapeau dans son deck sinon false
     */
    bool containsFlag() const;

    /**
     * @brief getPColor
     * @return retourne la couleur
     */
    PlayerColor getPColor() const;

    /**
     * @brief getDeckP
     * @return retourne le deck (tableau)
     */
    Deck &getDeckP() const;


    /**
     * @brief sizeDeckP
     * @return retourne la taille des pieces placée
     */
    int sizeDeckP();

    /**
     * @brief getPieceDeck
     * @param pos un nombre
     * @return renvoie la piece à la l'index indiqué
     */
    Piece *getPieceDeck(int pos);

    /**
     * @brief initDeck initialise les pieces.
     */
    void initDeck();

    /**
     * @brief selectPiece selectione la piece mit en parametre
     * @param valSymbol symbole de la piece
     */
    Piece *selectPiece(int valSymbol);

    /**
     * @brief addFlag ajoute un drapeau
     * @param symbol le symbole
     */
    void addFlag(const int &symbol);

    /**
     * @brief getTurnEnd
     * @return renvoie le tour du joueur.
     * si true on peut passer au prochain joueur sinon le joueur dois rejouer
     */
    bool getTurnEnd() const;

    /**
     * @brief setTurnEnd modifie l'état du tour
     * @param newTurnEnd  le tour
     */
    void setTurnEnd(bool newTurnEnd);

    /**
     * @brief initDeckDefault initialise les piece par defaut
     */
    void initDeckDefault();
};

inline bool Player::getTurnEnd() const
{
    return turnEnd;
}

inline void Player::setTurnEnd(bool newTurnEnd)
{
    turnEnd = newTurnEnd;
}

inline Player::Player(PlayerColor pColor)
{
    this->pColor=pColor;
    this->deckP=Deck();
}

inline bool Player::containsFlag() const{
    return this->deckP.getFlag()!=nullptr;
}

inline PlayerColor Player::getPColor() const
{
    return this->pColor;
}

inline  Deck &Player::getDeckP()const
{
    return const_cast<Deck&>(this->deckP);
}


inline int Player::sizeDeckP()
{
    return this->deckP.sizeDeckPlayer();
}

inline Piece* Player::getPieceDeck(int pos)
{
    return this->deckP.getPiece(pos);
}

inline void Player::initDeck()
{
    this->deckP.initStockPieces(this->pColor);
}

inline void Player::initDeckDefault(){
    this->deckP.initStockPiecesDefault(this->pColor);
}

inline Piece * Player::selectPiece(int valSymbol)
{
    return this->deckP.selectPiece(valSymbol);
}

inline void Player::addFlag(const int& symbol)
{
    this->deckP.addFlag(symbol);
}







#endif // PLAYER_H


