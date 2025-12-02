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
                Point p{(LL)r,(LL)c, Point::Direction::Up};
                return p;
            }
        }
    }
    P_LINE;
    exit(1);
}


bool IsInside(const VECS& vec, Point p){
    return p.y >= 0 && p.y < vec.size() && p.x >= 0 && p.x < vec[p.y].size();
}

auto count1() {
    LL score = 0;
    Point cur;

    cur = FindStart(in);

    for(;IsInside(in, cur);){
        ++score;
        auto next = cur.GetNext();
        if(!IsInside(in, next))
        {
            P(next, "exit");
            break;
        }
        if(in[next.y][next.x] == '#'){
            cur.TurnCw();
            P(cur, "turn");
        } else {
            cur = next;
            in[cur.y][cur.x] = 'o';
            P_VECV(in);
            P(cur, "move");
        }

    }
    P_VECV(in);
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
