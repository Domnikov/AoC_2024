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
    }
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
    for(LL r = 1;r < in.size()-1;++r){
        for(LL c = 1;c < in[r].size()-1;++c){
            S s1,s2,s3;
            s1.push_back(in[r-1][c-1]);
            s1.push_back(in[r-1][c  ]);
            s1.push_back(in[r-1][c+1]);
            s1.push_back(in[r  ][c-1]);
            s1.push_back(in[r  ][c  ]);
            s1.push_back(in[r  ][c+1]);
            s1.push_back(in[r+1][c-1]);
            s1.push_back(in[r+1][c  ]);
            s1.push_back(in[r+1][c+1]);
            VECS v;
            v.push_back(s1);
            v.push_back(s2);
            v.push_back(s3);
            P_VECV(v);
            P_LINE;
            if(in[r][c] == 'A'){
                if((in[r-1][c-1] == 'M' || in[r-1][c+1] == 'M')&&(in[r-1][c-1] == 'S' || in[r-1][c+1] == 'S')){
                    if((in[r+1][c-1] == 'M' || in[r+1][c+1] == 'M')&&(in[r+1][c-1] == 'S' || in[r+1][c+1] == 'S')){
                        score++;
                    }
                }
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
