QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = rooms
TEMPLATE = app


SOURCES += \
    Character.cpp \
    Command.cpp \
    CommandWords.cpp \
    item.cpp \
    Parser.cpp \
    Room.cpp \
    ZorkUL.cpp \
    GUI.cpp \
    armor.cpp \
    potion.cpp \
    weapon.cpp

OTHER_FILES +=

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    item.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    GUI.h \
    armor.h \
    potion.h \
    weapon.h

FORMS    += rooms.ui \
    rooms.ui

RESOURCES += \
    images.qrc
