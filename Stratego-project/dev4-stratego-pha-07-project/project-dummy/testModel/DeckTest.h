#ifndef DECKTEST_H
#define DECKTEST_H
#include <iostream>
#include <facade.h>

void testDeckEmpty(){
    cout<<"testDeckEmpty test:";
    int piece = 0;
    Deck inst;
    if(!inst.contains(piece)){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testPieceDeckContainsInBoard(){
    cout<<"testPieceDeckContainsInBoard test:";
    int piece = 10;
    Deck inst;
    inst.initStockPieces(RED);
    Board board;
    board.initBoard();
    board.put(inst.selectPiece(piece),Position(6,0));
    if(inst.contains(piece)){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testInitDeck(){
    cout<<"testInitDeck test:";
    bool result=true;
    Deck inst;
    inst.initStockPieces(PlayerColor::RED);
    if(inst.getPieces().size()!=40)result=false;
    if(result){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testDeckFull(){
    cout<<"testDeckFull test:";
    Deck inst;
    inst.initStockPieces(RED);
    if(inst.empty()){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}




#endif // DECKTEST_H
