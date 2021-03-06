TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        enemy.cpp \
        game.cpp \
        main.cpp \
        player.cpp \
        plytka.cpp \
        punkty.cpp

INCLUDEPATH += "D:\SFML-2.5.1\include"

LIBS += -L"D:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    enemy.h \
    game.h \
    player.h \
    plytka.h \
    punkty.h
