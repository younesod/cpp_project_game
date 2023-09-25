#ifndef PIECETEST_H
#define PIECETEST_H
#include <iostream>
#include <Game.h>
using namespace std;
void testGetPieceColorBlue(){
    cout<<"testGetColorBlue test:";
    Piece inst=Piece(7,PlayerColor::BLUE,Move::NORMAL);
    PlayerColor colorPiece=inst.getColorPiece();
    if(colorPiece==inst.getColorPiece()){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testGetRank(){
    cout<<"testGetRank test:";
    Piece inst=Piece(7,PlayerColor::BLUE,Move::NORMAL);
    int symbol=inst.getSymbol();
    if(symbol==inst.getSymbol()){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testGetMoveType_NORMAL(){
    cout<<"testGetMoveType_NORMAL test:";
    Piece inst=Piece(7,PlayerColor::BLUE,Move::NORMAL);
    Move typeMove=inst.getTypeMove();
    if(typeMove==inst.getTypeMove()){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}
void testGetMoveType_INFINITE(){
    cout<<"testGetMoveType_INFINITE test:";
    Piece inst=Piece(2,PlayerColor::BLUE,Move::INFINITE);
    Move typeMove=inst.getTypeMove();
    if(typeMove==inst.getTypeMove()){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}
void testGetMoveType_STATIC(){
    cout<<"testGetMoveType_STATIC test:";
    Piece inst=Piece(11,PlayerColor::BLUE,Move::STATIC);
    Move typeMove=inst.getTypeMove();
    if(typeMove==inst.getTypeMove()){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}
void testEqualsTrue(){
    cout<<"equalsTrue test:";
    Piece inst=Piece(7,PlayerColor::BLUE,Move::NORMAL);
    Piece inst2=Piece(7,PlayerColor::BLUE,Move::NORMAL);

    if(inst==inst2){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void equalsFalseDiffColor(){
    cout<<"equalsFalseDiffColor test:";
    Piece inst=Piece(7,PlayerColor::BLUE,Move::NORMAL);
    Piece inst2=Piece(7,PlayerColor::RED,Move::NORMAL);

    if(!(inst==inst2)){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void equalsFalseDiffSymbol(){
    cout<<"equalsFalseDiffSymbol test:";
    Piece inst=Piece(7,PlayerColor::BLUE,Move::NORMAL);
    Piece inst2=Piece(5,PlayerColor::BLUE,Move::NORMAL);

    if(!(inst==inst2)){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testIsStronger_True(){
    cout<<"testIsStronger_True test:";
    Piece *inst= new Piece(7,PlayerColor::BLUE,Move::NORMAL);
    Piece *inst2=new Piece(5,PlayerColor::RED,Move::NORMAL);
    if(inst->isStronger(inst2)){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testIsStronger_False(){
    cout<<"testIsStronger_True test:";
    Piece *inst= new Piece(7,PlayerColor::BLUE,Move::NORMAL);
    Piece *inst2= new Piece(10,PlayerColor::BLUE,Move::NORMAL);
    if(!inst->isStronger(inst2)){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testHasSameSymbol_True(){
    cout<<"testHasSameRank_True test:";
    Piece *inst=new Piece(8,PlayerColor::BLUE,Move::NORMAL);
    Piece *inst2=new Piece(8,PlayerColor::RED,Move::NORMAL);
    if(inst->hasSameSymbol(inst2)){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}
void testHasSameSymbol_False(){
    cout<<"testHasSameRank_False test:";
    Piece *inst=new Piece(8,PlayerColor::BLUE,Move::NORMAL);
    Piece *inst2=new Piece(5,PlayerColor::RED,Move::NORMAL);
    if(!inst->hasSameSymbol(inst2)){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}



#endif // PIECETEST_H
