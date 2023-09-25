#include "testModel/PositionTest.h"
#include "testModel/PieceTest.h"
#include "testModel/SquareTest.h"
#include "testModel/DeckTest.h"
#include "testModel/PlayerTest.h"
#include "testModel/BoardTest.h"
#include "testModel/GameTest.h"

int main(){
    cout<<"-------TEST FOR POSITION--------"<<endl;
    testGetRow();
    testGetCol();
    equalsTrue();
    equalsFalseDiffRow();
    equalsFalseDiffCol();
    nextDirSOUTH();
    nextDirNORTH();
    nextDirEAST();
    nextDirWEST();
    cout<<endl;

    cout<<"-------TEST FOR PIECE--------"<<endl;
    testGetPieceColorBlue();
    testGetRank();
    testGetMoveType_NORMAL();
    testGetMoveType_INFINITE();
    testGetMoveType_STATIC();
    equalsTrue();
    equalsFalseDiffColor();
    equalsFalseDiffSymbol();
    testIsStronger_True();
    testIsStronger_False();
    testHasSameSymbol_True();
    testHasSameSymbol_False();
    cout<<endl;

    cout<<"-------TEST FOR SQUARE--------"<<endl;
    testIsFree_True();
    testIsFree_False();
    testIsMyOwn_True();
    testIsMyOwn_False();
    testPutWhenSquareIsFree();
    testPutWhenSquareIsNotFree();
    testIsLand();
    testIsLand_False();
    testRemove();
    cout<<endl;

    cout<<"-------TEST FOR DECK--------"<<endl;
    testDeckEmpty();
    testPieceDeckContainsInBoard();
    testInitDeck();
    testDeckFull();
    cout<<endl;

    cout<<"-------TEST FOR PLAYER--------"<<endl;
    testGetPiecesDeckWhenDeckEmpty();
    testGetPiecesWhenDeckNotEmpty();
    testGetColorBlue();
    testGetColorRed();
    testContainsFlag();
    testContainsFlag_False();
    cout<<endl;

    cout<<"-------TEST FOR BOARD--------"<<endl;
    testGetSquareWhenSquareIsFill();
    testGetSquareWhenSquareIsEmpty();
    testGetSquareWhenPositionOutside();
    testGetSquareWhenPieceAdded();
    testWhenPositionOutside();
    testWhenPositionInside_CornerUpLeft();
    testWhenPositionInside_CornerUpRight();
    testWhenPositionInside_CornerDownLeft();
    testWhenPositionInside_CornerDownRight();
    testWhenPositionInside();
    testIsFreeWhenTheSquareIsEmpty();
    testIsFreeWhenTheSquareIsNotEmpty();
    testIsMyPiece();
    testIsNotMyPiece();
    testGetPiece();
    testRemovePiecePosition();
    cout<<endl;

    cout<<"-------TEST FOR GAME--------"<<endl;
    testEndGameOnStart();
    testMoveNextPositionFree_NORTH();
    testMoveNextPositionFree_WEST();
    testMoveNextPositionFree_EAST();
    testMoveSpyOnMarechal();
    testMoveDeminerOnBomb();
    testMoveOnWater();
    testMoveCommanderOnBomb();
    testMoveNextPositionOutsideBoard();
    testMoveNextPosition_Eclaireur2StepsNORTH();
    testGetWinnerRed();
    testGetWinnerBlue();
    testMoveOnFlagEnnemy();
    testSwapPlayer();
    testEndGameWhenPlayerBoardEmpty();

}
