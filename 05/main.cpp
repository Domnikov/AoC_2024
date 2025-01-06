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

std::map<LL,SETI> rules;

std::pair<LL,LL> checkRule(VECI vec){
    SETI passed;
    SETI pages_to_update;
    for(auto i: vec){
        pages_to_update.emplace(i);
    }
    for(auto i: vec){
        auto& rule = rules[i];
        for(auto r : rule){
            if(!passed.count(r) && pages_to_update.count(r)){
                return {r,i};
            }
        }
        passed.emplace(i);
    }
    return {-1,-1};
}

void flip(VECI& v, LL lhs, LL rhs){
    FOR(i, v.size()){
        if(v[i] == lhs){v[i] = rhs;}
        else if(v[i] == rhs){v[i] = lhs;}
    }
}

LL score2 = 0;
auto count1() {
    LL score = 0;

    bool second_part = false;
    for(auto l:in){
        if(l.empty()) {second_part = true;continue;}

        if(second_part){
            auto vec = vecsToVeci(splitStr(l,','));
            auto pair = checkRule(vec);
            if(pair.first == -1){
                score+=vec[vec.size()/2];
            }else{
                do{
                    flip(vec, pair.first, pair.second);
                    pair = checkRule(vec);
                }while(pair.first != -1);
                score2+=vec[vec.size()/2];
            }
        }else{
            auto vec = vecsToVeci(splitStr(l,'|'));
            rules[vec[1]].emplace(vec[0]);
        }
    }
    return score;
}

auto count2() {
    return score2;
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
