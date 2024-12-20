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

auto isSafe(const auto& vec){
    bool safe = true;
    int dir = 0;
    FOR (v,vec.size()){
        if (v == 0){continue;}
        auto sdiff = stoi(vec[v-1]) - stoi(vec[v]);
        auto diff = abs(sdiff);
        if (!dir){
            if (sdiff < 0){ dir = -1;}
            if (sdiff > 0){ dir = 1;}
        }
        if( (dir < 0 && sdiff > 0) || (dir > 0 && sdiff < 0) ) {
            safe = false;
            break;
        }
        if (diff < 1 || diff > 3) {
            safe = false;
            break;
        }
    }
    return safe;
}

auto count1() {
    LL score = 0;
    FOR (i, in.size()){
        auto vec = splitStr(in[i], ' ');
        score += isSafe(vec);
    }
    return score;
}

auto count2() {
    LL score = 0;
    FOR (i, in.size()){
        auto vec = splitStr(in[i], ' ');
        FOR (v,vec.size()){
            VECS nvec;
            FOR (vv,vec.size()){
                if(v!=vv){
                    nvec.push_back(vec[vv]);
                }
            }
            if(isSafe(nvec)){
                ++score;
                break;
            }
        }
    }
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
