#include "histogram.h"
#include <cassert>

void test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 0);
    assert(max == 3);
}

void test_otric()
{
    double min = 0;
    double max = 0;
    find_minmax({-10, -12, -3}, min, max);
    assert(min == -12);
    assert(max == 0);
}

void test_sim()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 0);
    assert(max == 1);
}

void test_izodnogo()
{
    double min = 0;
    double max = 0;
    find_minmax({1}, min, max);
    assert(min == 0);
    assert(max == 1);
}

void test_pustogo()
{
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

int main()
{
    test_izodnogo();
    return 0;
}
