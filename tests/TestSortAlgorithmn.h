#ifndef TESTSORTALGORITHMN_H
#define TESTSORTALGORITHMN_H

#include "SortAlgorithmn.h"
//#include <QtTest/QTest>
#include <QTest>
#include <QtTest/QtTest>
#include <QObject>
#include "common.h"

class TestSortAlgorithmn : public QObject
{
    Q_OBJECT
public:
    TestSortAlgorithmn();

private slots:
    void testQuickSort();

    void testHeapSort();

};

#endif // TESTSORTALGORITHMN_H
