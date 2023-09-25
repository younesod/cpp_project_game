QT -= gui

TEMPLATE = lib
DEFINES += PROJECTMODEL_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include (../config.pri)


HEADERS += \
    Board.h \
    Deck.h \
    Direction.h \
    Game.h \
    Move.h \
    Observable.h \
    Observer.h \
    Piece.h \
    Player.h \
    PlayerColor.h \
    Position.h \
    Square.h \
    SquareType.h \
    State.h \
    facade.h \
    pieces/Bombe.h \
    pieces/Colonel.h \
    pieces/Commandant.h \
    pieces/Demineur.h \
    pieces/Drapeau.h \
    pieces/Eclaireur.h \
    pieces/Espionne.h \
    pieces/General.h \
    pieces/Lieutenant.h \
    pieces/Major.h \
    pieces/Marechal.h \
    pieces/Sergent.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

SOURCES += \
    Observable.cpp



