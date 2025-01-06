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
#include <regex>

auto in = getInput();

Point FindStart(const VECS& v){
    FOR(r, v.size()){
        FOR(c, v[r].size()){
            if(v[r][c] == '^'){
                return Point{c,r};
            }
        }
    }
    P_LINE;
    exit(1);
}


Point cur;

auto count1() {
    LL score = 0;
    return score;
}

auto count2() {
    LL score = 0;
    return score;
}

int main(int argc, char** argv)
{
    LL score = 0;
    cur = FindStart(in);
    score = count1();
    P_RR("Part1: %lld\n", score);
    //========================================================

    score = count2();
    P_RR("Part2: %lld\n", score);
    return 0;
}
