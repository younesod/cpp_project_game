#ifndef POSITIONTEST_H
#define POSITIONTEST_H
#include <iostream>
#include <Position.h>

using namespace std;

void testGetRow(){
    cout<<"getRow test:";
    Position inst (10,9);
    int expResult=10;
    int result = inst.getRow();
    if(expResult==result){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}
void testGetCol(){
    cout<<"getCol test:";
    Position inst(10,9);
    int expResult=9;
    int result = inst.getColumn();
    if(expResult==result){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}
void equalsTrue(){
    cout<<"equalsTrue test:";
    Position inst(10,9);
    Position inst2(10,9);
    bool expResult=true;
    bool result = inst==inst2;
    if(expResult==result){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}

void equalsFalseDiffRow(){
    cout<<"equalsFalseDiffRow test:";
    Position inst(10,9);
    Position inst2(0,9);
    bool expResult=false;
    bool result = inst==inst2;
    if(expResult==result){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}
void equalsFalseDiffCol(){
    cout<<"equalsFalseDiffCol test:";
    Position inst(10,9);
    Position inst2(10,7);
    bool expResult=false;
    bool result = inst==inst2;
    if(expResult==result){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}

void nextDirSOUTH(){
    cout<<"nextDirSOUTH test:";
    Position inst(10,9);
    Position expResult(11,9);
    Position result = inst.nextPosition(Direction::SOUTH);
    if(expResult==result){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}
void nextDirNORTH(){
    cout<<"nextDirNORTH test:";
    Position inst = Position(10,9);
    Position expResult=Position(9,9);
    Position result = inst.nextPosition(Direction::NORTH);
    if(expResult==result){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}
void nextDirEAST(){
    cout<<"nextDirEAST test:";
    Position inst = Position(10,9);
    Position expResult=Position(10,10);
    Position result = inst.nextPosition(Direction::EAST);
    if(expResult==result){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}
void nextDirWEST(){
    cout<<"nextDirWEST test:";
    Position inst = Position(10,9);
    Position expResult=Position(10,8);
    Position result = inst.nextPosition(Direction::WEST);
    if(expResult==result){
        cout<<"VALID"<<endl;
    }
    else{
        cout <<"ERROR"<<endl;
    }
}

#endif // POSITIONTEST_H
