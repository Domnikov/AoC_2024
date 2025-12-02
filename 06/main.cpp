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

Point FindStart(const VECS& v){
    FOR(r, v.size()){
        FOR(c, v[r].size()){
            if(v[r][c] == '^'){
                Point p{(LL)c,(LL)r, Point::Direction::Up};
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
    auto in = getInput();
    Point cur;

    cur = FindStart(in);
    in[cur.y][cur.x] = 'o';
    LL score = 1;
    for(;IsInside(in, cur);){
        auto next = cur.GetNext();
        if(!IsInside(in, next))
        {
            break;
        }
        if(in[next.y][next.x] == '#'){
            cur.TurnCw();
        } else {
            cur = next;
            if (in[cur.y][cur.x] != 'o'){
                score++;
                in[cur.y][cur.x] = 'o';
            }
        }

    }
    return score;
}

std::pair<bool, Point> CheckLoop(VECS in, Point cur, std::set<Point> visited)
{
    auto obsticle = cur.GetNext();
    if(!IsInside(in, obsticle))
    {
        return {false, Point{}};
    }
    in[obsticle.y][obsticle.x] = '#';
    for(;IsInside(in, cur);){
        auto next = cur.GetNext();
        if(!IsInside(in, next))
        {
            break;
        }
        if(in[next.y][next.x] == '#'){
            cur.TurnCw();
        } else {
            cur = next;
            if (visited.insert(cur).second == false) {
                return {true, obsticle};
            }
        }
    }
    return {false, Point{}};
}

auto count2() {
    std::set<Point> all_obsticles;
    auto in = getInput();
    auto cur = FindStart(in);
    std::set<Point> visited;
    visited.insert(cur);
    for(;IsInside(in, cur);){
        auto next = cur.GetNext();
        if(!IsInside(in, next))
        {
            break;
        }
        if(in[next.y][next.x] == '#'){
            cur.TurnCw();
        } else {
            cur = next;
            if (visited.insert(cur).second == false) {
                P_LINE;
                exit(1);
            }
            auto [is_loop, obsticle] = CheckLoop(in, cur, visited);
            if(is_loop){
                all_obsticles.insert(obsticle);
            }
        }

    }
    return all_obsticles.size();
}

int main(int argc, char** argv)
{
    LL score = 0;
    score = count1();
    P_RR("Part1: %lld\n", score); //> 5238
    //========================================================

    score = count2();
    P_RR("Part2: %lld\n", score);
    return 0;
}
