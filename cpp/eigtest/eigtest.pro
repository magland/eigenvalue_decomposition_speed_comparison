QT += core
QT -= gui

TARGET = eigtest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp


#LAPACK
#On Ubuntu: sudo apt-get install liblapacke-dev
#On CentOS: sudo yum install lapack-devel.i686
INCLUDEPATH += /usr/include/lapacke #this was needed on CentOS
DEFINES += USE_LAPACK
LIBS += -llapack -llapacke
