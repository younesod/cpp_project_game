TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

include (../config.pri)

SOURCES += \
        test.cpp

DISTFILES += \
    game.txt

HEADERS += \
    BoardTest.h \
    DeckTest.h \
    GameTest.h \
    PieceTest.h \
    PlayerTest.h \
    PositionTest.h \
    SquareTest.h \
    testModel/BoardTest.h \
    testModel/DeckTest.h \
    testModel/GameTest.h \
    testModel/PieceTest.h \
    testModel/PlayerTest.h \
    testModel/PositionTest.h \
    testModel/SquareTest.h


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../project-model/release/ -lproject-model
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../project-model/debug/ -lproject-model
else:unix: LIBS += -L$$OUT_PWD/../project-model/ -lproject-model

INCLUDEPATH += $$PWD/../project-model
DEPENDPATH += $$PWD/../project-model
