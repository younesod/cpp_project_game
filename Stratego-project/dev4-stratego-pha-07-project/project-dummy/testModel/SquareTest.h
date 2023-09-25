#ifndef SQUARETEST_H
#define SQUARETEST_H
#include <iostream>
#include <facade.h>
using namespace std;

void testIsFree_True(){
    cout<<"testIsFree_True test:";
    Square inst = Square(SquareType::LAND);
    if(inst.isFree()){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}

void testIsFree_False(){
    cout<<"testIsFree_False test:";
    Square inst = Square(SquareType::LAND);
    inst.put(new Piece(4,PlayerColor::BLUE,Move::NORMAL));
    if(!inst.isFree()){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}

void testIsMyOwn_True(){
    cout<<"testIsMyOwn_True test:";
    Square inst = Square(SquareType::LAND);
    inst.put(new Piece(4,PlayerColor::BLUE,Move::NORMAL));
    PlayerColor color=PlayerColor::BLUE;
    if(inst.isMyPiece(color)){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}

void testIsMyOwn_False(){
    cout<<"testIsMyOwn_False test:";
    Square inst = Square(SquareType::LAND);
    inst.put(new Piece(4,PlayerColor::BLUE,Move::NORMAL));
    PlayerColor color=PlayerColor::RED;
    if(!inst.isMyPiece(color)){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}

void testPutWhenSquareIsFree(){
    cout<<"testPutWhenPieceIsFree test:";
    Square inst = Square(SquareType::LAND);
    bool result=true;
    if(inst.isFree()){
        inst.put(new Piece(4,PlayerColor::BLUE,Move::NORMAL));
    }
    else result=false;
    if(result){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}


void testPutWhenSquareIsNotFree(){
    cout<<"testPutWhenPieceIsNotFree test:";
    Square inst = Square(SquareType::LAND);
    inst.put(new Piece(4,PlayerColor::BLUE,Move::NORMAL));
    bool result=true;
    if(!inst.isFree()){
        result=false;
    }else inst.put(new Piece(2,PlayerColor::BLUE,Move::INFINITE));
    if(!result){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}

void testRemove(){
    cout<<"testRemove test:";
    Square inst(SquareType::LAND);
    Piece piece(5,BLUE,NORMAL);
    Piece *pi =&piece;
    inst.put(pi);
    inst.remove();
    if(inst.getPiece()==nullptr){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }

}

void testIsLand(){
    cout <<"testIsLand test:";
    Square inst = Square(SquareType::LAND);
    if(inst.isLand()){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}

void testIsLand_False(){
    cout <<"testIsLand_False test:";
    Square inst = Square(SquareType::WATER);
    if(!inst.isLand()){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}



#endif // SQUARETEST_H
