#-------------------------------------------------
#
# Project created by QtCreator 2018-12-01T16:08:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BBS_GUI2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Administator.cpp \
    BBS.cpp \
    Board.cpp \
    Comment.cpp \
    Moderator.cpp \
    OrdinaryUser.cpp \
    Post.cpp \
    User.cpp \
    MyTime.cpp \
    boardslabel.cpp \
    postslabel.cpp \
    Anonymity.cpp \
    SocketClient.cpp

HEADERS += \
        mainwindow.h \
    Administator.h \
    BBS.h \
    Board.h \
    Comment.h \
    mainwindow.h \
    Moderator.h \
    OrdinaryUser.h \
    Post.h \
    User.h \
    MyTime.h \
    boardslabel.h \
    postslabel.h \
    Anonymity.h \
    SocketClient.h

FORMS += \
        mainwindow.ui

LIBS += libwsock32 libWs2_32
#For Sockets
