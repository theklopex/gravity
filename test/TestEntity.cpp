#include "Entity.h"
#include <unit_test.h>

void TestEntity()
{
    Entity e1("my entity", 1,2,3, 1000, 1);
    UT_EQUAL(e1.get_mass(), 1000);
    UT_EQUAL(e1.get_radius(), 1);
}

int main(int argc, char** argv)
{
    TestEntity();
    return 0;
}