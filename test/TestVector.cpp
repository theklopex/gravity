#include <iostream>
#include "Vector.h"
#include <unit_test.h>

void TestVector()
{
    //std::cout << "300,400,0 tuple ----------------------" << std::endl;
    Tuple t1(300,400,0);
    Vector v1(t1, 5);
    //std::cout << v1;
    UT_EQUAL(v1.X(), 3);
    UT_EQUAL(v1.Y(), 4);
    UT_EQUAL(v1.Z(), 0);

    //std::cout << "0,300,400 tuple ----------------------" << std::endl;
    Tuple t2(0,300,400);
    Vector v2(t2, 5);
    //std::cout << v2;
    UT_EQUAL(v2.X(), 0);
    UT_EQUAL(v2.Y(), 3);
    UT_EQUAL(v2.Z(), 4);

    //std::cout << "300,0,400 tuple ----------------------" << std::endl;
    Tuple t3(300,0,400);
    Vector v3(t3, 5);
    //std::cout << v3;
    UT_EQUAL(v3.X(), 3);
    UT_EQUAL(v3.Y(), 0);
    UT_EQUAL(v3.Z(), 4);

    //std::cout << "300,300,300 tuple ----------------------" << std::endl;
    Tuple t4(300,300,300);
    Vector v4(t4, 5);
    //std::cout << v4;
    UT_APPROX(v4.X(), 3.00, 2);
    UT_APPROX(v4.Y(), 3.00, 2);
    UT_APPROX(v4.Z(), 3.00, 2);
    //std::cout << "END ----------------------" << std::endl;
}

int main(int argc, char** argv)
{
    TestVector();
    return 0;
}