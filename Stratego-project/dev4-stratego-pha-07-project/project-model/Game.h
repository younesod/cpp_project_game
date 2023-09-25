#ifndef GAME_H
#define GAME_H
#include <fstream>
#include "Board.h"
#include "Player.h"
#include "Position.h"
#include "State.h"
#include "Position.h"
#include "Piece.h"
#include "Direction.h"
#include "Observable.h"
#include <utility>


/**
 * @brief La class Game est la structure du jeu.
 */
class Game:public observer::Observable{
private:
    Board board;
    Player playerRed;
    Player playerBlue;
    Player currentPlayer;
    State state;

    /**
     * @brief canPass permet en fonction de la direction de bouger la piece
     * @param start position de départ
     * @param direction une direction
     * @return la position avancée à la position voulu
     */
    Position canPass(const Position &start,Direction const &direction);

    /**
     * @brief applyMove permet d'appliquer le mouvement de la piece
     * @param start position de départ
     * @param direction une direction
     * @param nbSteps nombre de pat
     */
    void applyMove(const Position &start, const Direction &direction, const int &nbSteps);


public:
    /**
     * @brief Game c'est le constructeur, permet de jouer au jeu.
     */
    Game();

    /**
     * @brief start permet de start le jeu
     * @param url1 string url (path)
     * @param url2 string url (path)
     */
    void start(std::vector<string>url1, std::vector<string>url2);

    /**
     * @brief start permet de start le jeu
     */
    void start();

    /**
     * @brief startGame permet d'initialiser les pieces des joueur et met le jeu en etat "INITIALIZE"
     */
    void startGame();

    /**
     * @brief endGame détecte la fin du jeu
     * @return retourn true si le jeu est fini sinon false
     */
    bool endGame();

    /**
     * @brief move permet de bouger la pièce et d'éliminer la pièce ennemie
     * si possible
     * @param start la position de la piece que l'on veut bouger
     * @param direction la direction a la qu'elle on veut bouger la piece
     * @param nbSteps le nombre de pas
     */
    void move(const Position &start, const Direction direction, const int nbSteps);

    /**
     * @brief getWinner
     * @return retourne le gaganant du jeu
     */
    PlayerColor getWinner() const;


    /**
     * @brief getBoard
     * @return retourne le Board et l'objet ne peut pas être modifié car const
     */
    const Board &getBoard() const;

    /**
     * @brief getBoard
     * @return retourne le Board
     */
    Board &getBoard();

    /**
     * @brief getPlayerRed
     * @return retourne le joueur rouge
     */
    const Player &getPlayerRed() const;

    /**
     * @brief getPlayerBlue
     * @return retourne le joueur bleu et l'objet ne peut pas être modifié car const
     */
    const Player &getPlayerBlue() const;

    /**
     * @brief getDeckPlayer
     * @param color couleur du joueur
     * @return le deck du joueur et l'objet ne peut pas être modifié car const
     */
    Deck &getDeckPlayer(const PlayerColor color)const;

    /**
     * @brief getDeckPlayer
     * @param color couleur du joueur
     * @return le deck du joueur
     */
    Deck &getDeckPlayer(const PlayerColor color);

    /**
     * @brief getState
     * @return retourne le State
     */
    State getState() const;

    /**
     * @brief swapPlayer permet d'échanger les joueurs
     */
    void swapPlayer();

    /**
     * @brief gameIsInside
     * @param pos une position
     * @return retourne true si la position est dans le tableau
     */
    bool gameIsInside(const Position pos) const;

    /**
     * @brief gameGetPiece
     * @param pos une position
     * @return retourne la pièce à la position donnée
     */
    const Piece *gameGetPiece(Position pos) const;

    /**
     * @brief initPiecePlayer place les pièce du joueur prit d'un fichier
     * @param board le tableau
     * @param player un joueur
     * @param url l'url de la position du fichier
     */
    void initDeckPiece(const PlayerColor &player, const std::vector<string> url);

    /**
     * @brief initDeckPiece initialise les pieces des joueurs
     */
    void initDeckPiece();

    /**
     * @brief initDeckPieceDefault permet d'initialiser les pieces dans les decks des joueurs
     */
    void initDeckPieceDefault();

    /**
     * @brief initPiecePlayer initialise les pièces des joueurs
     * @param board le tableau
     */
    void initBoard(const PlayerColor);

    /**
     * @brief isEclaireur
     * @param position une Position
     * @return retourne true si la piece a la position donnée est un éclereur sinon faux
     */
    bool isEclaireur(const Position &position) const;

    /**
     * @brief getPiece
     * @param position une position
     * @return retourne la pièce et l'objet ne peut pas être modifié car const
     */
    const Piece* getPiece(const Position &position)const ;

    /**
     * @brief getPiece
     * @param position une position
     * @return retourne la pièce
     */
    Piece* getPiece(const Position &position);

    /**
     * @brief initGame pose les pièces des joueurs
     */
    void initGame();

    /**
     * @brief getCurrentPlayer
     * @return retourne le joueur courant
     */
    const Player &getCurrentPlayer() const;

    /**
     * @brief setCurrentPlayer met le joueur en paramètre a current player
     * @param newCurrentPlayer un joueur
     */
    void setCurrentPlayer(const Player &newCurrentPlayer);

    /**
     * @brief setPiece met la pièce à la position donnée
     * @param piece une pièce
     * @param position une position
     */
    void setPiece(Piece *piece, const Position &pos);

    /**
     * @brief initDeckPlayer initialise le deck du joueur
     */
    void initDeckPlayer(const PlayerColor &color);


    /**
     * @brief getTurnEnd
     * @param color couleur du joueur
     * @return true si le joueur a posé ça piece sinon false
     */
    bool getTurnEnd(const PlayerColor &color);

    /**
     * @brief setTurnEnd sert pour le tour du joueur.
     * ex: si le joueur rouge apelle la methode met le joueur rouge a true et joueur bleu a false.
     * @param color couleur du joueur
     */
    void setTurnEnd(const PlayerColor &color);

    /**
     * @brief setState met un nouvelle état
     * @param newState un état
     */
    void setState(const State &newState);

    /**
     * @brief getDeckPieces
     * @return retourne les pieces qui sont dans le deck du joueur
     */
    vector<Piece> getDeckPieces();


    /**
     * @brief selectPieceFromDeck
     * @param color la couleur du joueur
     * @param symbol le symbole de la piece
     * @return retourne la piece du joueur donnée
     */
    Piece * selectPieceFromDeck(const PlayerColor &color,const int &symbol);

    /**
     * @brief canBePlaced
     * @param position une position
     * @return retourne true si la piece peut être placée a la position donnée sinon false
     */
    bool canBePlaced(const Position &position);

    /**
     * @brief placePiece permet de placer la piece
     * @param pos une position
     * @param symbol le symbole de la piece
     */
    void placePiece(const Position& pos, int symbol);

    /**
     * @brief setVisiblePiecePlayer rend les pieces du joueurs visibles
     * @param pColor couleur du joueur
     */
    void setVisiblePiecePlayer(const PlayerColor &pColor);

    /**
     * @brief endPlacement
     * @return retourne true si tout les pieces du deck sont posée false sinon
     */
    bool endPlacement();

    /**
     * @brief switchPlayer permet de changer de joueur courrant
     */
    void switchPlayer();

    /**
     * @brief endPlacementPlayer
     * @return retourne true si tout les pieces du deck sont posée false sinon [de un seule joueur]
     */
    bool endPlacementPlayer();

    /**
     * @brief isMovePossible permet de savoir si le move est bon ou pas
     * @param dir direction
     * @param nextDir position de départ
     * @param posPossible position d'où on veut aller
     * @return retourne true si le move est possitble sinon false
     */
    bool isMovePossible(const Direction &dir, const Position &nextDir, const Position &posPossible);

    /**
     * @brief canMoveAnyPiece sert en début de partie. dans la situation où les pieces
     * statique empêchent aux autres pieces de bouger
     * @param color couleur du joueur
     * @return retourn true si les pieces ne peuvent plus bouger sinon false
     */
    bool canMoveAnyPiece(PlayerColor color);

    /**
     * @brief placePiece permet de poser la piece dans le board
     * @param pos position a la quelle on veux poser la piece
     * @param symbol symbole de la piece
     * @param color couleur du joueur
     */
    void placePiece(const Position &pos, int symbol, PlayerColor color);

    /**
     * @brief initGameDefault initialise le game par defaut dnas le board
     */
    void initGameDefault();

    /**
     * @brief removeFlag supprime le drapeau du joueur courant
     */
    void removeFlag();

    /**
     * @brief emptyBoard supprime les pieces du tableau
     */
    void emptyBoard();
};


//-----------------IMPLEMENTATION---------------------------//


inline Game::Game():board(Board()),playerRed(Player(RED)),playerBlue(Player(BLUE)),currentPlayer(playerRed),state(NOT_STARTED)
{
    notifyAll(state);
}
inline const Piece *Game::getPiece(const Position &position)const
{
    return this->board.getPiece(position);
}

inline Piece* Game::getPiece(const Position &position){
    return const_cast<Piece*>(as_const(*this).getPiece(position));
}

inline const Board &Game::getBoard()const
{
    return board;
}
inline  Board &Game::getBoard()
{
    return const_cast<Board&>(as_const(*this).getBoard());
}


inline const Player &Game::getPlayerRed() const
{
    return playerRed;
}


inline const Player &Game::getPlayerBlue() const
{
    return playerBlue;
}

inline Deck &Game::getDeckPlayer(const PlayerColor color)const
{
    if(color==RED) return this->playerRed.getDeckP();
    else return this->playerBlue.getDeckP();
}

inline Deck &Game::getDeckPlayer(const PlayerColor color){
    return const_cast<Deck&>(as_const(*this).getDeckPlayer(color));
}
inline const Player &Game::getCurrentPlayer() const
{
    return currentPlayer;
}

inline void Game::setCurrentPlayer(const Player &newCurrentPlayer)
{
    this->currentPlayer = newCurrentPlayer;
}

inline void Game::setPiece(Piece *piece, const Position &pos)
{
    this->board.setPiece(piece,pos);
}

inline void Game::initDeckPlayer(const PlayerColor &color)
{
    if(color==RED){
        this->playerRed.initDeck();
    }
    else if(color==BLUE){
        this->playerBlue.initDeck();
    }
}

inline bool Game::getTurnEnd(const PlayerColor &color)
{
    if(color==RED) return this->playerRed.getTurnEnd();
    else return this->playerBlue.getTurnEnd();

}

inline State Game::getState() const
{
    return state;
}

inline void Game::start(std::vector<string>url1,std::vector<string>url2){
    if(this->state!=State::NOT_STARTED){
        throw invalid_argument("the state is supposed to be NOT_STARTED");
    }
    this->initDeckPlayer(RED);
    this->initDeckPlayer(BLUE);
    this->initGame();
    this->initDeckPiece(RED,url1);
    this->initDeckPiece(BLUE,url2);
    this->playerRed.addFlag(0);
    this->playerBlue.addFlag(0);
    this->state=CHOOSE_PIECE;
}

inline void Game::start(){
    if(this->state!=State::NOT_STARTED){
        throw invalid_argument("the state is supposed to be NOT_STARTED");
    }
    this->initDeckPieceDefault();
    this->initGameDefault();
    this->playerRed.addFlag(0);
    this->playerBlue.addFlag(0);
    this->state=CHOOSE_PIECE;
}

inline void Game::startGame()
{
    if(this->state!=State::NOT_STARTED){
        throw invalid_argument("the state is supposed to be NOT_STARTED");
    }
    this->board.initBoard();
    this->initDeckPlayer(RED);
    this->initDeckPlayer(BLUE);
    this->state=INITIALIZED;
    notifyAll(state);
}
inline void Game::initGameDefault()
{
    if(this->state!=State::NOT_STARTED){
        throw invalid_argument("the state is supposed to be NOT_STARTED");
    }
    this->board.initBoard();
    initBoard(PlayerColor::RED);
    initBoard(PlayerColor::BLUE);
    this->state=INITIALIZED;
    notifyAll(state);
}

inline void Game::initGame(){
    if(this->state!=State::NOT_STARTED){
        throw invalid_argument("the state is supposed to be NOT_STARTED");
    }
    this->board.initBoard();
    this->state=INITIALIZED;
    notifyAll(state);
}
inline bool Game::canMoveAnyPiece(PlayerColor color){
    bool can=true;
    int line;
    if(color==RED)line=6;
    else line=3;
    for(int i=line;i<=line;i++){
        for(int j=0;j<10;j++){
            if(j==0 || j==1 || j==4 || j==5 || j==8 || j==9){
                if(board.getPiece(Position(i,j))!=nullptr){
                    if(board.getPiece(Position(i,j))->getTypeMove()==STATIC) can=false;
                    else{
                        can=true;
                        return can;
                    }
                }
                else if(board.getPiece(Position(i,j))==nullptr){
                    can=true;
                    return can;
                }
            }
        }
    }
    return can;
}

inline bool Game::endGame(){
    if(!canMoveAnyPiece(this->currentPlayer.getPColor())){
        if(this->currentPlayer.getPColor()==RED)this->playerRed.getDeckP().setFlag(nullptr);
        else if(this->currentPlayer.getPColor()==BLUE )this->playerBlue.getDeckP().setFlag(nullptr);
    }
    if(!this->playerBlue.containsFlag() || !this->playerRed.containsFlag()){
        this->state = State::END_GAME;
        notifyAll(state);
        return false;
    }
    if(this->playerBlue.getDeckP().empty() || this->playerRed.getDeckP().empty()){
        this->state = State::END_GAME;
        notifyAll(state);
        return false;
    }
    return true;
}




inline void Game::setState(const State &newState)
{
    state = newState;
}

inline vector<Piece> Game::getDeckPieces()
{
    if(this->currentPlayer.getPColor()==RED) return this->playerRed.getDeckP().getPieces();
    else if(this->currentPlayer.getPColor()==BLUE) return this->playerBlue.getDeckP().getPieces();
    return {};
}


inline Piece *Game::selectPieceFromDeck(const PlayerColor &color, const int &symbol)
{
    if(color==RED){ return this->playerRed.selectPiece(symbol);}
    else if(color==BLUE) {return this->playerBlue.selectPiece(symbol);}
    return nullptr;
}

inline Position Game::canPass(const Position &start,const Direction &direction){
    int i=start.getRow();
    int j=start.getColumn();
    while(this->board.isInside(Position(i,j)) && this->board.getSquare(Position(i,j)).getType()!=WATER){
        if(direction==Direction::SOUTH) ++i;
        else if(direction==Direction::NORTH) --i;
        else if(direction==Direction::EAST) ++j;
        else if(direction==Direction::WEST) --j;
        if(!this->board.isInside(Position(i,j)) || this->board.getSquare(Position(i,j)).getType()==WATER){
            if(direction==Direction::SOUTH) --i;
            else if(direction==Direction::NORTH) ++i;
            else if(direction==Direction::EAST) --j;
            else if(direction==Direction::WEST) ++j;
            return Position(i,j);

        }
        if(this->board.getSquare(Position(i,j)).getPiece()!=nullptr){
            return Position(i,j);
        }
    }

    return {};
}

inline void Game::applyMove(const Position& start, const Direction &direction, const int &nbSteps)
{
    if(this->state!=State::CHOOSE_PIECE){
        throw invalid_argument("the state is supposed to be CHOOSE_PIECE");
    }
    Position nextDir=start.nextPosition(direction,nbSteps);
    if(this->board.getSquare(nextDir).isFree()){ //if next piece is free
        this->board.put(this->board.getPiece(start),nextDir);
        this->board.remove(start);
        this->state = State::MOVE_PIECE;
    }else if(this->board.getSquare(start).getPiece()->getColorPiece() != this->board.getSquare(nextDir).getPiece()->getColorPiece()){
        this->board.getPiece(nextDir)->toggleVisibility(); //la piece adverse est revelé
        if(this->board.getPiece(start)->isStronger(this->board.getPiece(nextDir))){
            if(this->board.getPiece(nextDir)->getSymbol()==0){
                if(this->currentPlayer.getPColor()==RED) this->playerBlue.getDeckP().setFlag(nullptr);
                else this->playerRed.getDeckP().setFlag(nullptr);
            }
            this->board.remove(nextDir);
            this->board.put(this->board.getPiece(start),nextDir);
            this->board.remove(start);
            this->state = State::MOVE_PIECE;
        }else if(this->board.getPiece(start)->hasSameSymbol(this->board.getPiece(nextDir))){
            this->board.remove(nextDir);
            this->board.remove(start);
            this->state = State::MOVE_PIECE;
        }else if(!this->board.getPiece(start)->isStronger(this->board.getPiece(nextDir))){
            this->board.remove(start);
            this->state = State::MOVE_PIECE;
        }
    }
}
inline void Game::move(const Position& start, const Direction direction, const int nbSteps=1){
    if(this->board.getPiece(start) == nullptr || !this->board.isInside(start)){
        throw invalid_argument("the position selected is empty or not inside the board or the direction ");
    }
    Position nextDir=start.nextPosition(direction,nbSteps);
    if(this->board.getSquare(nextDir).isLand() && this->board.isInside(nextDir)
            && !this->board.getSquare(nextDir).isMyPiece(this->currentPlayer.getPColor())){
        if(this->board.getSquare(start).getPiece()->getTypeMove()==Move::NORMAL){
            if(this->board.isMyPiece(start,this->currentPlayer.getPColor())){
                this->applyMove(start,direction,nbSteps);
                this->setTurnEnd(this->currentPlayer.getPColor());
                notifyAll(state);
            }
        }
        else if(this->board.getSquare(start).getPiece()->getTypeMove()==Move::INFINITE){
            Position posPossible=canPass(start,direction);
            if(this->board.isMyPiece(start,this->currentPlayer.getPColor()) && isMovePossible(direction,nextDir,posPossible)){
                this->applyMove(start,direction,nbSteps);
                this->setTurnEnd(this->currentPlayer.getPColor());
                notifyAll(state);
            }
        }
    }
}
inline bool Game::isMovePossible(const Direction & dir,const Position & nextDir, const Position &posPossible){
    bool isPossible=false;
    if(dir==NORTH){
        if(nextDir.getRow()>=posPossible.getRow()) isPossible=true;
    }
    else if(dir==SOUTH){
        if(nextDir.getRow()<=posPossible.getRow()) isPossible=true;
    }
    else if(dir==WEST){
        if(nextDir.getColumn()>=posPossible.getColumn()) isPossible=true;
    }
    else if(dir==EAST){
        if(nextDir.getColumn()<=posPossible.getColumn()) isPossible=true;
    }
    return isPossible;
}

inline void Game::setTurnEnd(const PlayerColor &color){
    if(color==RED){
        this->playerRed.setTurnEnd(true);
        this->playerBlue.setTurnEnd(false);
    }else{
        this->playerBlue.setTurnEnd(true);
        this->playerRed.setTurnEnd(false);
    }
}

inline void Game::setVisiblePiecePlayer(const PlayerColor &pColor)
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(this->board.getPiece(Position(i,j))->getColorPiece()==pColor){
                this->board.getPiece(Position(i,j))->toggleVisibility();
            }
        }
    }
}

inline bool Game::gameIsInside(const Position pos) const{
    return this->board.isInside(pos);
}

inline const Piece* Game::gameGetPiece(Position pos) const{
    return this->board.getPiece(pos);
}

inline void Game::initDeckPiece(const PlayerColor &player, const std::vector<string> url)
{
    size_t iDeck=0;
    int line=0;
    int maxLine=4;
    if(player==PlayerColor::RED){
        line=6;
        maxLine=10;
    }
    for(int i=line;i<maxLine;i++){
        for(int j=0;j<10;j++){
            bool put=false;
            while(!put && iDeck<url.size()){
                if(url[iDeck]=="10"){
                    this->placePiece(Position(i,j),10,player);
                }
                else if(url[iDeck]=="9"){
                    this->placePiece(Position(i,j),9,player);
                }
                else if(url[iDeck]=="8"){
                    this->placePiece(Position(i,j),8,player);
                }
                else if(url[iDeck]=="7"){
                    this->placePiece(Position(i,j),7,player);
                }
                else if(url[iDeck]=="6"){
                    this->placePiece(Position(i,j),6,player);
                }
                else if(url[iDeck]=="5"){
                    this->placePiece(Position(i,j),5,player);
                }
                else if(url[iDeck]=="4"){
                    this->placePiece(Position(i,j),4,player);
                }
                else if(url[iDeck]=="3"){
                    this->placePiece(Position(i,j),3,player);
                }
                else if(url[iDeck]=="2"){
                    this->placePiece(Position(i,j),2,player);
                }
                else if(url[iDeck]=="1"){
                    this->placePiece(Position(i,j),1,player);
                }
                else if(url[iDeck]=="D"){
                    this->placePiece(Position(i,j),0,player);
                }
                else if(url[iDeck]=="B"){
                    this->placePiece(Position(i,j),11,player);
                }
                put=true;
                iDeck++;
            }
        }
    }
}

inline void Game::initDeckPieceDefault()
{
    this->playerBlue.initDeckDefault();
    this->playerRed.initDeckDefault();

}

inline PlayerColor Game::getWinner() const{
    if(this->state!=State::END_GAME){
        throw invalid_argument("the game is not over ");
    }
    if(!this->playerBlue.containsFlag() || this->playerBlue.getDeckP().singlePiece()){
        return this->playerRed.getPColor();
    }else if(!this->playerRed.containsFlag() || this->playerRed.getDeckP().singlePiece()){
        return this->playerBlue.getPColor();
    }
    return {};
}



inline bool Game::isEclaireur(const Position &position) const
{
    return this->board.getPiece(position)->isEclaireur();
}

inline void Game::swapPlayer()
{
    if(this->state!=State::MOVE_PIECE){
        throw invalid_argument("the player's turn can't be finished if he didn't played");
    }
    if(!(this->playerBlue.getPColor()==this->currentPlayer.getPColor())){
        this->currentPlayer=playerBlue;
    }else{
        this->currentPlayer=playerRed;
    }
    this->state = State::CHOOSE_PIECE;
    notifyAll(state);
}

inline void Game::switchPlayer(){
    if(!(this->playerBlue.getPColor()==this->currentPlayer.getPColor())){
        this->currentPlayer=playerBlue;
    }else{
        this->currentPlayer=playerRed;
    }
}



inline void Game::initBoard(const PlayerColor color){
    int iDeck=0;
    int line=0;
    int maxLine=4;
    if(color==PlayerColor::RED){
        line=6;
        maxLine=10;
    }
    for(int i=line;i<maxLine;i++){
        if(color==RED){
            for(int j=0;j<10;j++){
                bool put=false;
                while(!put && iDeck<this->playerRed.sizeDeckP()){
                    this->board.put(this->playerRed.getPieceDeck(iDeck),Position(i,j));
                    put=true;
                    iDeck++;
                }
            }
        }
        else{
            for(int j=0;j<10;j++){
                bool put=false;
                while(!put && iDeck<this->playerBlue.sizeDeckP()){
                    Piece *p= this->playerBlue.getPieceDeck(iDeck);
                    this->board.put(p,Position(i,j));
                    put=true;
                    iDeck++;
                }
            }
        }
    }
}

inline void Game::placePiece(const Position &pos, int symbol){
    if(this->currentPlayer.getPColor()==RED){
        this->board.put(this->selectPieceFromDeck(RED,symbol),pos);
    }
    else if(this->currentPlayer.getPColor()==BLUE){
        this->board.put(this->selectPieceFromDeck(BLUE,symbol),pos);
    }
}
inline void Game::placePiece(const Position &pos, int symbol,PlayerColor color){
    if(color==RED){
        this->board.put(this->selectPieceFromDeck(RED,symbol),pos);
    }
    else if(color==BLUE){
        this->board.put(this->selectPieceFromDeck(BLUE,symbol),pos);
    }
}

inline bool Game::canBePlaced(const Position &position){
    if(this->gameIsInside(position) && this->board.getPiece(position)==nullptr){
        if(this->currentPlayer.getPColor()==RED){
            if(position.getRow()>=6){
                return true;
            }
            return false;
        }else if(this->currentPlayer.getPColor()==BLUE){
            if(position.getRow()<=3){
                return true;
            }
            return false;
        }
    }
    return false;
}

inline bool Game::endPlacementPlayer(){
    bool isAllPut=true;
    for(size_t i=0;i<getDeckPieces().size();i++){
        if(!getDeckPieces().at(i).getIsPut()){
            isAllPut=false;
        }
    }
    if(isAllPut){
        this->switchPlayer();
    }
    return isAllPut;
}

inline bool Game::endPlacement(){
    bool isAllPut=true;
    for(size_t i=0;i<getDeckPieces().size();i++){
        if(!getDeckPlayer(RED).getPieces().at(i).getIsPut() || !getDeckPlayer(BLUE).getPieces().at(i).getIsPut()){
            isAllPut=false;
        }
    }
    if(isAllPut){
        this->state = State::CHOOSE_PIECE;
        notifyAll(state);
    }
    return isAllPut;
}

inline void Game::removeFlag(){
    if(this->currentPlayer.getPColor()==RED){
        this->playerRed.getDeckP().setFlag(nullptr);
    }else{
        this->playerBlue.getDeckP().setFlag(nullptr);

    }
}

inline void Game::emptyBoard(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(board.getPiece(Position(i,j))!=nullptr){
                board.getPiece(Position(i,j))->setIsPut(false);
                this->board.remove(Position(i,j));
            }


        }
    }
}




#endif // GAME_H






