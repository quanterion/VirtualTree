#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T14:15:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VirtualTree
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    virtualtreemodel/virtualtreemodel.cpp \
    virtualtreemodel/virtualtreeadapter.cpp

HEADERS  += mainwindow.h \
    virtualtreemodel/virtualtreemodel.h \
    virtualtreemodel/virtualtreeadapter.h

FORMS    += mainwindow.ui

# C++ 11/14 flags
CONFIG += c++14
msvc:
else:QMAKE_CXXFLAGS += -std=c++11

win32-msvc* {
    # Works when you build for Visual Studio already
    vsproj.spec = $$basename(QMAKESPEC)
} else {
    # Works when you're not building for Visual Studio (say, using mingw)
    # The configuration you want to build the VS project for (win32-msvc[2005|2008|2010|2012])
    vsproj.spec = win32-msvc2013
}
vsproj.target = $${TARGET}.vcxproj
# The qmake command to make the Visual Studio project file
vsproj.commands = qmake -tp vc $${_PRO_FILE_} -spec $${vsproj.spec}
# The VS project depends on the .pro file
vsproj.depends = $${_PRO_FILE_}
# Set the above as a target in the makefile.
QMAKE_EXTRA_TARGETS += vsproj
# Make the main target (the executable/library) depend on it,
# so that it gets built.
PRE_TARGETDEPS += $${vsproj.target}
