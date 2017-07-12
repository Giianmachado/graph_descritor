QT += core
QT -= gui

CONFIG += c++11

TARGET = graph_descritor
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    divider_and_computer.cpp \
    utils.cpp \
    graph.cpp \
    writefile.cpp \
    readfile.cpp

LIBS += `pkg-config opencv --libs`

HEADERS += \
    ../Downloads/igraph-0.7.1/include/igraph.h \
    divider_and_computer.h \
    utils.h \
    graph.h \
    writefile.h \
    readfile.h

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -ligraph

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libigraph.a
