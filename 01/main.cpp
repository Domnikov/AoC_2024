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
    LL result = 0;
    VECI left,right;
    for(const auto& s:in) {
        P(in);
        auto ss = replace(s, "   ", " ");
        auto arr = splitStr(ss, ' ');
        left.push_back(stoi(arr[0]));
        right.push_back(stoi(arr[1]));
    }
    std::sort(BE(left));
    std::sort(BE(right));
    FOR(i,left.size()) {
        auto l = left[i];
        auto r = right[i];
        result += llabs(l - r);
        P(l,r,result);
    }
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
