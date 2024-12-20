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
    P (in);
    FOR (i, in.size()){
        auto vec = splitStr(in[i], ' ');
        P (vec);
        bool safe = true;
        int dir = 0;
        FOR (v,vec.size()){
            if (v == 0){continue;}
            auto sdiff = stoi(vec[v-1]) - stoi(vec[v]);
            auto diff = abs(sdiff);
            if (!dir){
                if (sdiff < 0){ P("<0");dir = -1;}
                if (sdiff > 0){ P(">0");dir = 1;}
            }
            P( sdiff, dir, diff , stoi(vec[v-1]) , stoi(vec[v]));
            if( (dir < 0 && sdiff > 0) || (dir > 0 && sdiff < 0) ) {
                P("dir", dir, sdiff);
                safe = false;
                break;
            }
            if (diff < 1 || diff > 3) {
            P( "safe", diff , stoi(vec[v-1]) , stoi(vec[v]));
                safe = false;
                break;
            }
        }
        if(safe){P("safe");}else {P("unsafe");}
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
    // 265  too low
    //========================================================

    score = count2();
    P_RR("Part2: %lld\n", score);
    return 0;
}
