#ifndef HIERARCHYCALCTEST_H
#define HIERARCHYCALCTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "parser.h"

class HierarchyCalcTest : public QObject
{
    Q_OBJECT
public:
    explicit HierarchyCalcTest(QObject *parent = 0);

private slots:
    void initTestCase()
    {
        prs = new Parser();
        result = prs->parse(std::string("(* (+ 1 1) 2)"));
    }

    void testParse()
    {
        QCOMPARE(result->toString(), std::string("( * ( + 1 1 ) 2 )"));
    }

    void testCompute()
    {
        QCOMPARE(result->compute(), 4);
    }

    void cleanupTestCase()
    {
        delete prs;
        delete result;
    }


private:
    Parser *prs;
    Node *result;
};

#endif // HIERARCHYCALCTEST_H
