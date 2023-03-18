#include <Tuple.h>
#include <unit_test.h>
#include <stdio.h>

void TestTuple()
{
    Tuple l1(0,0,0);
    Tuple l2(3,4,0);
    UT_EQUAL(l2.distance(l1), 5.0)
    Tuple l3(0,3,4);
    UT_APPROX(l3.distance(l1), 5.0, 2)
    Tuple l4(0,10,10);
    UT_APPROX(l4.distance(l1), 14.14, 2)

    l3.move(1,2,3);
    l4.relocate(1,5,7);
    UT_ASSERT(l3 == l4);
}

int main(int argc, char** argv)
{
    TestTuple();
    return 0;
}