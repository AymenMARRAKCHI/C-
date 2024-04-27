# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = Interface
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += AjoutBorne.cpp AjoutBorneStationnement.cpp GestionBorne.cpp Supprimer_Bornes.cpp main.cpp
HEADERS += AjoutBorne.h AjoutBorneStationnement.h GestionBorne.h Supprimer_Bornes.h
FORMS += AjoutBorne.ui AjoutBorneStationnement.ui GestionBorne.ui Supprimer_Bornes.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += ../SourceF 
LIBS += ../SourceF/dist/Debug/GNU-Linux/libsourcef.a  
