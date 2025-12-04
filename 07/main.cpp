#include "../help_func.hpp"
#ifdef TEST
#define INPUT "input_test"
#else
#define INPUT "input"
#endif

#include <cassert>
#include <cmath>
#include <queue>
#include <list>
#include <limits>
#include <thread>

auto in = inToVecS(INPUT);

auto count1() {
    LL result = 0;
    return result;
}

auto count2() {
    LL result = 0;
    return result;
}

int main(int argc, char** argv)
{
    LL score = 0;
    score = count1();
    P_RR("Part1: %lld\n", score);
    //========================================================

    score = count2();
    P_RR("Part2: %lld\n", score);
    return 0;
}
