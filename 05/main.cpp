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

bool checkRule(VECI vec){
    SETI passed;

    for(auto i: vec){
        auto& rule = rules[i];
        for(auto r : rule){
            if(!passed.count(r)){
                P("violated",r,"for",i);
                return false;
            }
        }
        passed.emplace(i);
    }
    return true;
}


auto count1() {
    LL score = 0;

    bool second_part = false;
    for(auto l:in){
        if(l.empty()) {second_part = true;continue;}

        if(second_part){
            auto vec = vecsToVeci(splitStr(l,','));
            if(checkRule(vec)){
                score+=vec[vec.size()/2];
            }
        }else{
            auto vec = vecsToVeci(splitStr(l,'|'));
            rules[vec[1]].emplace(vec[0]);
        }
    }
    for(auto [key,v]:rules){
        P(key,v);
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
