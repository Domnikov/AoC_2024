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

auto count1() {
    LL score = 0;
    std::regex self_regex("XMAS|SAMX");
    for(auto s:in){
        std::ptrdiff_t cnt(std::distance( std::sregex_iterator(text.begin(), text.end(), s), std::sregex_iterator()));
        score += cnt;
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
