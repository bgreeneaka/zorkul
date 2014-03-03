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
    rooms.cpp \
    button.cpp

OTHER_FILES +=

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    item.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    rooms.h \
    button.h

FORMS    += rooms.ui \
    rooms.ui
