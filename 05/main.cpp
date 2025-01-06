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

std::map<LL,VECI> rules;

auto count1() {
    LL score = 0;

    for(auto l:in){
        if(l.empty()) break;

        auto vec = SplitStr(l,'|');
        rules[stoi(vec[1])].push_back(stoi(vec[0]));
    }
    P(rules);

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
