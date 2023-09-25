#ifndef GAMETEST_H
#define GAMETEST_H
#include <iostream>
#include <facade.h>

Game Init(){
    Game game;
    game.start();
    return game;
}



void testEndGameOnStart(){
    cout<<"testEndGameOnStart test:";
    Game game=Init();
    bool expResult=true;
    bool result=game.endGame();
    if(expResult==result){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testMoveNextPositionFree_NORTH(){
    cout<<"testMoveNextPosition_NORTH test:";
    Game game;
    game.start();
    game.setCurrentPlayer(game.getPlayerRed());
    Position posPiece(6,4);
    game.move(posPiece,Direction::NORTH);
    Position exp(5,4);
    Position posResult=posPiece.nextPosition(Direction::NORTH);
    Piece *pieceExp= new Demineur(PlayerColor::RED);
    Piece *result=game.getPiece(posPiece.nextPosition(Direction::NORTH));
    if(pieceExp->getSymbol()==result->getSymbol() && exp==posResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}


void testMoveNextPositionFree_EAST(){
    cout<<"testMoveNextPosition_EAST test:";
    Game game;
    game.start();
    game.setCurrentPlayer(game.getPlayerRed());
    Position posPiece(4,0);
    game.setPiece(new Sergent(RED),posPiece);
    game.move(posPiece,EAST);
    Position exp(4,1);
    Position posResult=posPiece.nextPosition(Direction::EAST);
    Piece *pieceExp= new Sergent(PlayerColor::RED);
    Piece *result=game.getPiece(posPiece.nextPosition(Direction::EAST));
    if(pieceExp->getSymbol()==result->getSymbol() && exp==posResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testMoveNextPositionFree_WEST(){
    cout<<"testMoveNextPosition_WEST test:";
    Game game;
    game.start();
    game.setCurrentPlayer(game.getPlayerRed());
    Position posPiece(4,1);
    game.setPiece(new Lieutenant(RED),posPiece);
    game.move(posPiece,WEST);
    Position exp(4,0);
    Position posResult=posPiece.nextPosition(Direction::WEST);
    Piece *pieceExp= new Lieutenant(PlayerColor::RED);
    Piece *result=game.getPiece(posPiece.nextPosition(Direction::WEST));
    if(pieceExp->getSymbol()==result->getSymbol() && exp==posResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testMoveNextPosition_Eclaireur2StepsNORTH(){
    cout<<"testMoveNextPosition_Eclaireur2StepsNORTH test:";
    Game game;
    game.start();
    game.emptyBoard();
    game.setCurrentPlayer(game.getPlayerRed());
    Position posPiece(6,0);
    game.setPiece(new Eclaireur(RED),posPiece);
    game.move(posPiece,NORTH,2);
    Position exp(4,0);
    Position posResult=posPiece.nextPosition(Direction::NORTH,2);
    Piece *pieceExp= new Eclaireur(PlayerColor::RED);
    Piece *result=game.getPiece(posPiece.nextPosition(Direction::NORTH,2));
    if(pieceExp->getSymbol()==result->getSymbol() && exp==posResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testMoveNextPositionOutsideBoard(){
    cout<<"testMoveNextPositionOutsideBoard test:";
    Game game;
    game.start();
    game.emptyBoard();
    game.setCurrentPlayer(game.getPlayerRed());
    Position posPiece(6,0);
    game.setPiece(new Eclaireur(RED),posPiece);
    game.move(posPiece,EAST);
    Position exp=posPiece;
    Position posResult=posPiece.nextPosition(Direction::EAST);
    Piece *pieceExp= nullptr;
    Piece *result=game.getPiece(posPiece.nextPosition(Direction::EAST));
    if(!(pieceExp==result) && !(exp==posResult)){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testMoveCommanderOnBomb(){
    cout<<"testMoveCommanderOnBomb test:";
    Game game;
    game.start();
    game.emptyBoard();
    game.setCurrentPlayer(game.getPlayerRed());
    Position posPiece(4,0);
    game.setPiece(new Commandant(RED),posPiece);
    game.setPiece(new Bombe(BLUE),posPiece.nextPosition(NORTH));
    game.move(posPiece,NORTH);
    Piece *pieceDead= new Commandant(RED);
    Piece *pieceInitial= game.getPiece(posPiece);
    Piece *result=game.getPiece(posPiece.nextPosition(Direction::NORTH));
    if(!(pieceDead->getSymbol()==result->getSymbol()) && pieceInitial==nullptr){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testMoveOnWater(){
    cout<<"testMoveOnWater test:";
    Game game;
    game.start();
    game.emptyBoard();
    game.setCurrentPlayer(game.getPlayerRed());
    Position posInitial(5,1);
    game.setPiece(new Commandant(RED),posInitial);
    game.move(posInitial,EAST);
    Piece *expPiece= new Commandant(RED);
    Piece *result=game.getPiece(posInitial);
    if(expPiece->getSymbol()==result->getSymbol()){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testMoveDeminerOnBomb(){
    cout<<"testMoveDeminerOnBomb test:";
    Game game;
    game.start();
    game.emptyBoard();
    game.setCurrentPlayer(game.getPlayerRed());
    Position posInitial(4,0);
    game.setPiece(new Demineur(RED),posInitial);
    game.move(posInitial,NORTH);
    Position exp=posInitial.nextPosition(NORTH);
    Position posResult=posInitial.nextPosition(Direction::NORTH);
    Piece *expPiece= new Demineur(RED);
    Piece *result=game.getPiece(posInitial.nextPosition(NORTH));
    if(expPiece->getSymbol()==result->getSymbol() && exp==posResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testMoveSpyOnMarechal(){
    cout<<"testMoveSpyOnMarechal test:";
    Game game;
    game.start();
    game.emptyBoard();
    game.setCurrentPlayer(game.getPlayerRed());
    Position posPiece(3,0);
    game.setPiece(new Marechal(BLUE),Position(4,0));
    game.setPiece(new Espionne(RED),posPiece);
    game.move(posPiece,SOUTH);
    Position exp(4,0);
    Position posResult=posPiece.nextPosition(Direction::SOUTH);
    Piece *expPiece= new Espionne(RED);
    Piece *result=game.getPiece(posPiece.nextPosition(SOUTH));
    if(expPiece->getSymbol()==result->getSymbol() && exp==posResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testGetWinnerRed(){
    cout<<"testGetWinnerRed test:";
    Game game;
    game.start();
    game.emptyBoard();
    game.setCurrentPlayer(game.getPlayerRed());
    game.getDeckPlayer(BLUE).setFlag(nullptr);
    game.endGame();
    PlayerColor colorWinner=game.getWinner();
    if(colorWinner==RED){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testGetWinnerBlue(){
    cout<<"testGetWinnerBlue test:";
    Game game;
    game.start();
    game.emptyBoard();
    game.setCurrentPlayer(game.getPlayerRed());
    game.getDeckPlayer(RED).setFlag(nullptr);
    game.endGame();
    PlayerColor colorWinner=game.getWinner();
    if(colorWinner==BLUE){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testMoveOnFlagEnnemy(){
    cout<<"moveOnFlagEnnemy test:";
    Game game;
    game.start();
    game.emptyBoard();
    game.setCurrentPlayer(game.getPlayerRed());
    Position posPiece(5,0);
    game.setPiece(new Drapeau(BLUE),Position(4,0));
    game.setPiece(new Sergent(RED),posPiece);
    game.move(posPiece,NORTH);
    Position exp(4,0);
    Position posResult=posPiece.nextPosition(Direction::NORTH);
    Piece *expPiece= new Sergent(RED);
    Piece *result=game.getPiece(posPiece.nextPosition(NORTH));
    if(expPiece->getSymbol()==result->getSymbol() && exp==posResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testSwapPlayer(){
    cout<<"testSwapPlayer test:";
    Game game;
    game.start();
    game.emptyBoard();
    game.setCurrentPlayer(game.getPlayerRed());
    game.setState(MOVE_PIECE);
    game.swapPlayer();
    PlayerColor colorExp=game.getCurrentPlayer().getPColor();
    if(colorExp==BLUE){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }

}

void testEndGameWhenPlayerBoardEmpty(){
    cout<<"testEndGameWhenPlayerBoardEmpty test:";
    Game game;
    game.start();
    game.setCurrentPlayer(game.getPlayerBlue());
    for(int i=6;i<10;i++){
        for(int j=0;j<10;j++){
            game.getBoard().remove(Position(i,j));
        }
    }
    bool endGame= game.endGame();
    if(endGame==true){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }

}



#endif // GAMETEST_H
