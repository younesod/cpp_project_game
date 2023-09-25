#ifndef PLAYERTEST_H
#define PLAYERTEST_H
#include <iostream>
#include <facade.h>
using namespace std;

void testGetPiecesDeckWhenDeckEmpty(){
    cout<<"testGetPiecesDeckWhenStockEmpty test: ";
    Player inst = Player(PlayerColor::BLUE);
    Deck result = inst.getDeckP();
    int cpt=0;
    for(size_t i=0;i<result.getPieces().size();i++){
        if(result.getPieces().at(i).getIsPut()){
            cpt++;
        }
    }
    if(cpt==0){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testGetPiecesWhenDeckNotEmpty(){
    cout<<"testGetPiecesWhenDeckNotEmpty test: ";
    Player inst =  Player(PlayerColor::BLUE);
    inst.getDeckP().initStockPieces(BLUE);
    Board board;
    board.initBoard();
    Piece *piece=inst.getDeckP().getPiece(0);
    piece->setIsPut(true);
    board.put(piece,Position(0,0));
    Deck result = inst.getDeckP();
    int cpt=0;
    for(size_t i=0;i<result.getPieces().size();i++){
        if(result.getPieces().at(i).getIsPut()){
            cpt++;
        }
    }
    if(cpt!=0){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}


void testGetColorBlue(){
    cout<<"testGetColorBlue test: ";
    Player inst = Player(PlayerColor::BLUE);
    PlayerColor color=PlayerColor::BLUE;
    if(inst.getPColor()==color){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testGetColorRed(){
    cout<<"testGetColorRed test: ";
    Player inst = Player(PlayerColor::RED);
    PlayerColor color=PlayerColor::RED;
    if(inst.getPColor()==color){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testContainsFlag(){
    cout<<"testContainsFlag test:";
    Player inst = Player(PlayerColor::RED);
    inst.getDeckP().add(Piece(0,PlayerColor::BLUE,Move::STATIC));
    if(inst.containsFlag()){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testContainsFlag_False(){
    cout<<"testContainsFlag_False test:";
    Player inst = Player(PlayerColor::RED);
    if(inst.containsFlag()){
       cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}


#endif // PLAYERTEST_H
