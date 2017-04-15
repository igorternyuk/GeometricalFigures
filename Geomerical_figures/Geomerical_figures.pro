#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T11:03:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Geomerical_figures
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    trianglebycoordinates.cpp \
    cylinder.cpp \
    ellipse.cpp \
    circle.cpp \
    ellipsoid.cpp \
    ball.cpp \
    cone.cpp \
    torus.cpp \
    parallelepiped.cpp \
    polygon.cpp \
    parallelogram.cpp \
    trapezium.cpp \
    triangle.cpp \
    pyramid.cpp

HEADERS  += mainwindow.h \
    trianglebycoordinates.h \
    cylinder.h \
    ellipse.h \
    circle.h \
    ellipsoid.h \
    ball.h \
    cone.h \
    torus.h \
    parallelepiped.h \
    polygon.h \
    parallelogram.h \
    trapezium.h \
    triangle.h \
    pyramid.h

FORMS    += mainwindow.ui \
    trianglebycoordinates.ui

RESOURCES += \
    images.qrc
