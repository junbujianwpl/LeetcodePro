#ifndef TESTATOMIC_H
#define TESTATOMIC_H


class TestAtomic
{
public:
    TestAtomic();

    static void testAtomicInThreads();

    static void testAtomicArrayInThreads();
};

#endif // TESTATOMIC_H
