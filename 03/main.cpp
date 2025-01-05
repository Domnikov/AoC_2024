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

auto count1() {
    LL score = 0;
    auto s = in[0];
    std::regex word_regex("mul\\([0-9]+,[0-9]+\\)");
    auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();
        std::regex num_reg("[0-9]+");
        std::smatch sm;
        std::regex_search(match_str, sm, num_reg);
        auto num1 = stoi(sm.str());
        match_str = sm.suffix();
        std::regex_search(match_str, sm, num_reg);
        auto num2 = stoi(sm.str());
        score += num1*num2;
    }
    return score;
}

auto count2() {
    LL score = 0;
    auto s = in[0];
    std::regex word_regex("mul\\([0-9]+,[0-9]+\\)|do\\(\\)|don't\\(\\)");
    auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();
        P(match_str);
        // std::regex num_reg("[0-9]+");
        // std::smatch sm;
        // std::regex_search(match_str, sm, num_reg);
        // auto num1 = stoi(sm.str());
        // match_str = sm.suffix();
        // std::regex_search(match_str, sm, num_reg);
        // auto num2 = stoi(sm.str());
        // score += num1*num2;
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
