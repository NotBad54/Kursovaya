#include "../src/op.cpp"
#include <cxxtest/TestSuite.h>
#include <iostream>
#include <stack>
#include <vector>
//typedef double(*func_type)(stack<double> &); 
class MyTest : public CxxTest::TestSuite {
public:
    void test0()
    {
        TS_ASSERT_EQUALS(fact(3),6);
    }

    void test1()
    {
        TS_ASSERT_EQUALS(fact(5),120);
    }

    void test2()
    {
        TS_ASSERT_EQUALS(fact(10),3628800);
    }

    void test3()
    {
        TS_ASSERT_EQUALS(fact(14),87178291200);
    }

    void test4()
    {
        TS_ASSERT_EQUALS(fact(19),121645100408832000);
    }

    void test5()
    {
        TS_ASSERT_EQUALS(fact(18),6402373705728000);
    }

     void test6()
    {
        TS_ASSERT_EQUALS(fact(0),1);
    }

    void test7()
    {
        TS_ASSERT_EQUALS(fact(1),1);
    }

     void test8()
    {
        TS_ASSERT_EQUALS(fact(2),2);
    }

    void test9()
    {
        TS_ASSERT_EQUALS(fact(17),355687428096000);
    }

    void test10()
    {
        TS_ASSERT_EQUALS(fact(16),20922789888000);
    }

    void test11()
    {
        TS_ASSERT_EQUALS(fact(15),1307674368000);
    }

    void test12()
    {
        TS_ASSERT_EQUALS(fact(13),6227020800);
    }


    void test13()
    {
        TS_ASSERT_EQUALS(fact(12),479001600);
    }

    void test14()
    {
        TS_ASSERT_EQUALS(fact(11),39916800);
    }


    void test15()
    {
        TS_ASSERT_EQUALS(fact(9),362880);
    }

    void test16()
    {
        TS_ASSERT_EQUALS(fact(8),40320);
    }

    void test17()
    {
        TS_ASSERT_EQUALS(fact(7),5040);
    }

    void test18()
    {
        TS_ASSERT_EQUALS(fact(6),720);
    }

    void test19()
    {
        TS_ASSERT_EQUALS(fact(4),24);
    }
};
