#include "svg.h"
#include "histogram.h"
#include <cassert>

void test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_otric()
{
    double min = 0;
    double max = 0;
    find_minmax({-10, -12, -3}, min, max);
    assert(min == -12);
    assert(max == -3);
}

void test_sim()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_izodnogo()
{
    double min = 0;
    double max = 0;
    find_minmax({1}, min, max);
    assert(min == 1);
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

void test_shirini()
{
    int HIST_WIDTH = 0;
    double BLOCK_WIDTH = 0;
    hist_scale (HIST_WIDTH, BLOCK_WIDTH, {10, 6, 8});
    assert(BLOCK_WIDTH == HIST_WIDTH/10);
}

void test_poiska_max_kol_va_ocenok()
{
    size_t max = find_maxinbins({10, 4, 2});
    assert(max == 10);
}

int main()
{
    test_positive();
    test_otric();
    test_sim();
    test_izodnogo();
    test_pustogo();
    test_shirini();
    test_poiska_max_kol_va_ocenok();
    return 0;
}
