QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    carte.cpp \
    jeudecarte.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    carte.h \
    jeudecarte.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    cartes.qrc

DISTFILES += \
    Jeu_de_cartes/1.BMP \
    Jeu_de_cartes/10.BMP \
    Jeu_de_cartes/11.BMP \
    Jeu_de_cartes/12.BMP \
    Jeu_de_cartes/13.BMP \
    Jeu_de_cartes/14.BMP \
    Jeu_de_cartes/15.BMP \
    Jeu_de_cartes/16.BMP \
    Jeu_de_cartes/17.BMP \
    Jeu_de_cartes/18.BMP \
    Jeu_de_cartes/19.BMP \
    Jeu_de_cartes/2.BMP \
    Jeu_de_cartes/20.BMP \
    Jeu_de_cartes/21.BMP \
    Jeu_de_cartes/22.BMP \
    Jeu_de_cartes/23.BMP \
    Jeu_de_cartes/24.BMP \
    Jeu_de_cartes/25.BMP \
    Jeu_de_cartes/26.BMP \
    Jeu_de_cartes/27.BMP \
    Jeu_de_cartes/28.BMP \
    Jeu_de_cartes/29.BMP \
    Jeu_de_cartes/3.BMP \
    Jeu_de_cartes/30.BMP \
    Jeu_de_cartes/31.BMP \
    Jeu_de_cartes/32.BMP \
    Jeu_de_cartes/33.BMP \
    Jeu_de_cartes/34.BMP \
    Jeu_de_cartes/35.BMP \
    Jeu_de_cartes/36.BMP \
    Jeu_de_cartes/37.BMP \
    Jeu_de_cartes/38.BMP \
    Jeu_de_cartes/39.BMP \
    Jeu_de_cartes/4.BMP \
    Jeu_de_cartes/40.BMP \
    Jeu_de_cartes/41.BMP \
    Jeu_de_cartes/42.BMP \
    Jeu_de_cartes/43.BMP \
    Jeu_de_cartes/44.BMP \
    Jeu_de_cartes/45.BMP \
    Jeu_de_cartes/46.BMP \
    Jeu_de_cartes/47.BMP \
    Jeu_de_cartes/48.BMP \
    Jeu_de_cartes/49.BMP \
    Jeu_de_cartes/5.BMP \
    Jeu_de_cartes/50.BMP \
    Jeu_de_cartes/51.BMP \
    Jeu_de_cartes/52.BMP \
    Jeu_de_cartes/53.bmp \
    Jeu_de_cartes/54.bmp \
    Jeu_de_cartes/6.BMP \
    Jeu_de_cartes/7.BMP \
    Jeu_de_cartes/8.BMP \
    Jeu_de_cartes/9.BMP \
    Jeu_de_cartes/dos.bmp \
    Jeu_de_cartes/jeton.jpg \
    Jeu_de_cartes/tapis.jpg
