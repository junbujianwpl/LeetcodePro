#-------------------------------------------------
#
# Project created by QtCreator 2017-08-19T14:42:24
#
#-------------------------------------------------

QT       += core gui testlib

CONFIG += testcase c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LeetCodePro
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

DISTFILES += *.txt \
    .travis.yml

SOURCES += \
    SortAlgorithmn.cpp \
    tests/TestSortAlgorithmn.cpp \
    main.cpp \
    Leetcode.cpp \
    tests/TestLeetCode.cpp \
    BallWeigher.cpp \
    Combination.cpp \
    Shuffle.cpp \
    DFS.cpp \
    tests/TestDFS.cpp \
    YangHuiTriangle.cpp

HEADERS += \
    common.h \
    SortAlgorithmn.h \
    tests/TestSortAlgorithmn.h \
    Leetcode.h \
    tests/TestLeetCode.h \
    BallWeigher.h \
    Combination.h \
    Shuffle.h \
    DFS.h \
    tests/TestDFS.h \
    YangHuiTriangle.h

FORMS +=

DISTFILES += \
    README.md
