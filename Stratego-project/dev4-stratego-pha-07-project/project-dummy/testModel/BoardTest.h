#ifndef BOARDTEST_H
#define BOARDTEST_H
#include <iostream>
#include <Board.h>
using namespace std;

Board initBoard(){
    Board board;
    board.initBoard();
    return board;
}
void testGetSquareWhenSquareIsFill(){
    cout<<"testGetSquareWhenSquareIsFill test :";
    Board inst= initBoard();
    Position pos(3,2);
    inst.put(new Commandant(PlayerColor::BLUE),pos);
    Square expResult= Square(SquareType::LAND);
    expResult.put(new Commandant(PlayerColor::BLUE));
    Square result= inst.getSquare(pos);
    if(expResult==result){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testGetSquareWhenSquareIsEmpty(){
    cout<<"testGetSquareWhenSquareIsEmpty test :";
    Board inst= initBoard();
    Position pos(3,2);
    Square result= inst.getSquare(pos);
    if(result.getPiece()==nullptr){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testGetSquareWhenPositionOutside(){
    cout<<"testGetSquareWhenPositionOutside test:";
    Board inst= initBoard();
    Position pos(-1,2);
    if(!inst.isInside(pos)){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}


void testGetSquareWhenPieceAdded(){
    cout<<"testGetSquareWhenPieceAdded test:";
    Board inst= initBoard();
    Position pos1(1,1);
    Position pos2(1,3);
    Piece p1=Marechal(PlayerColor::BLUE);
    Piece p2=Commandant(PlayerColor::BLUE);
    inst.put(&p1,pos1);
    inst.put(&p2,pos2);
    bool result= inst.getPiece(pos1) == &p1 && inst.getPiece(pos2) == &p2;
    if(result){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testWhenPositionOutside(){
    cout<<"testWhenPositionOutside test:";
    Board inst= initBoard();
    Position pos1(-1,-1);
    bool result = inst.isInside(pos1);
    bool expResult=false;
    if(result==expResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testWhenPositionInside_CornerUpLeft(){
    cout<<"testWhenPositionInside_CornerUpLeft test:";
    Board inst= initBoard();
    Position pos1(0,0);
    bool expResult=true;
    bool result=inst.isInside(pos1);
    if(result==expResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testWhenPositionInside_CornerUpRight(){
    cout<<"testWhenPositionInside_CornerUpRight test:";
    Board inst= initBoard();
    Position pos1(0,9);
    bool expResult=true;
    bool result=inst.isInside(pos1);
    if(result==expResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testWhenPositionInside_CornerDownLeft(){
    cout<<"testWhenPositionInside_CornerDownLeft test:";
    Board inst= initBoard();
    Position pos1(9,0);
    bool expResult=true;
    bool result=inst.isInside(pos1);
    if(result==expResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testWhenPositionInside_CornerDownRight(){
    cout<<"testWhenPositionInside_CornerDownRight test:";
    Board inst= initBoard();
    Position pos1(0,9);
    bool expResult=true;
    bool result=inst.isInside(pos1);
    if(result==expResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testWhenPositionInside(){
    cout<<"testWhenPositionInside test:";
    Board inst= initBoard();
    Position pos1(6,5);
    bool expResult=true;
    bool result=inst.isInside(pos1);
    if(result==expResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testIsFreeWhenTheSquareIsEmpty(){
    cout<<"testIsFreeWhenTheSquareIsEmpty test:";
    Board inst= initBoard();
    Position pos(0,0);
    bool expResult=true;
    bool result=inst.isFree(pos);
    if(result==expResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testIsFreeWhenTheSquareIsNotEmpty(){
    cout<<"testIsFreeWhenTheSquareIsNotEmpty test:";
    Board inst= initBoard();
    Position pos(0,0);
    inst.put(new Commandant(PlayerColor::BLUE),pos);
    bool expResult=false;
    bool result=inst.isFree(pos);
    if(result==expResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testIsMyPiece(){
    cout<<"testIsMyPiece test:";
    Board inst= initBoard();
    Position pos(0,0);
    inst.put(new Commandant(PlayerColor::BLUE),pos);
    bool expResult=true;
    bool result=inst.isMyPiece(pos,PlayerColor::BLUE);
    if(result==expResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testIsNotMyPiece(){
    cout<<"testIsNotMyPiece test:";
    Board inst= initBoard();
    Position pos(0,0);
    inst.put(new Commandant(PlayerColor::RED),pos);
    bool expResult=false;
    bool result=inst.isMyPiece(pos,PlayerColor::BLUE);
    if(result==expResult){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}

void testGetPiece(){
    cout<<"testGetPiece test:";
    Board inst= initBoard();
    Position pos(0,0);
    Piece *posedPiece=new Commandant(PlayerColor::RED);
    inst.put(posedPiece,pos);
    Piece *expResult= posedPiece;
    Piece *result = inst.getPiece(pos);
    if(expResult==result){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}


void testRemovePiecePosition(){
    cout<<"testRemovePiecePosition test:";
    Board inst= initBoard();
    Position pos(2,9);
    inst.put(new Eclaireur(PlayerColor::RED),pos);
    inst.remove(pos);
    Piece *expResult= new Commandant(PlayerColor::RED);
    expResult = nullptr;
    Piece *result= inst.getPiece(pos);
    if(expResult==result){
        cout<<"VALID"<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
    }
}





#endif  //BOARDTEST_H
