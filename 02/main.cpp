#ifdef TEST
#include "in_test.hpp"
#else
#include "in.hpp"
#endif

#include <cassert>
#include <cmath>
#include <queue>
#include <list>
#include <limits>

auto in = getInput();

auto count1() {
    LL score = 0;
    P_LINE;
    FOR(i, in.size()){
        auto vec = splitStr(in[i], ' ');
        P(vec);
        bool safe = true;
        FOR(v,vec.size()){
            if (v == 0){continue;}
            if (vec[v-1] <= vec[v]) {
                safe = false;
                break;
            }
        }
        score += safe;
    }
    return score;
}

auto count2() {
    LL score = 0;
    return score;
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
