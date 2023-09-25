TEMPLATE = subdirs

SUBDIRS += \
    project-dummy \
    project-gui \
    project-model \
    project-tui

OTHER_FILES += config.pri \
    Doxyfile \
    ../../gitignore

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/project-model/release/ -lproject-model
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/project-model/debug/ -lproject-model
else:unix: LIBS += -L$$OUT_PWD/project-model/ -lproject-model

INCLUDEPATH += $$PWD/project-model
DEPENDPATH += $$PWD/project-model

