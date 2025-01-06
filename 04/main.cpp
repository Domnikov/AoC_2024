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

auto count(const VECS& vec){
    LL res = 0;
    std::regex regfwd("XMAS");
    std::regex regbwd("SAMX");
    for(auto s:vec){
        std::ptrdiff_t cntfwd(std::distance( std::sregex_iterator(s.begin(), s.end(), regfwd), std::sregex_iterator()));
        std::ptrdiff_t cntbwd(std::distance( std::sregex_iterator(s.begin(), s.end(), regbwd), std::sregex_iterator()));
        res += cntfwd+cntbwd;
        P(s, cntfwd, cntbwd);
    }
    P("Total", res);
    return res;
}

auto turn45(const VECS& vec){
    VECS res;
    S str;
    for(LL n = 0;n < (vec.size()+vec[0].size()-1);++n){
        res.push_back(str);
    }
    FOR(c, vec[0].size()){
        FOR(r, vec.size()){
            LL rr = r+c;
            res[rr].push_back(vec[r][c]);
        }
    }
    return res;
}

auto turn90(const VECS& vec){
    VECS res;
    FOR(c, vec[0].size()){
        S str;
        FOR(r, vec.size()){
            str += vec[vec.size()-1-r][c];
        }
        res.push_back(str);
    }
    return res;
}

auto count1() {
    LL score = 0;
    auto in90 = turn90(in);
    auto in45 = turn45(in);
    auto in135 = turn45(in90);
    score = count(in)
          + count(in90)
          + count(in45)
          + count(in135);
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
    P_RR("Part1: %lld\n", score); // 2579
    //========================================================

    score = count2();
    P_RR("Part2: %lld\n", score);
    return 0;
}
