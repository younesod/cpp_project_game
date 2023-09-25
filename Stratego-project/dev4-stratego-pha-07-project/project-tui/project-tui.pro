TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    Controller.h \
    View.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../project-model/release/ -lproject-model
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../project-model/debug/ -lproject-model
else:unix: LIBS += -L$$OUT_PWD/../project-model/ -lproject-model

INCLUDEPATH += $$PWD/../project-model
DEPENDPATH += $$PWD/../project-model
