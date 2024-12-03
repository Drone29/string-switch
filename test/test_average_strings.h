
#pragma once

#include <ctime>
#include <unordered_map>
#include <iostream>
#include "test.h"

// average strings (12-15 symbols)
constexpr const char *test_average_strings[] = {
        "seventy one",
        "seventy two",
        "seventy three",
        "seventy four",
        "seventy five",
        "seventy six",
        "seventy seven",
        "seventy eight",
        "seventy nine",
        "eighty whole"
};

class TestAverageStrings : public Test {

    const std::unordered_map<std::string, int> m_map = {
            {test_average_strings[0], 1},
            {test_average_strings[1], 2},
            {test_average_strings[2], 3},
            {test_average_strings[3], 4},
            {test_average_strings[4], 5},
            {test_average_strings[5], 6},
            {test_average_strings[6], 7},
            {test_average_strings[7], 8},
            {test_average_strings[8], 9},
            {test_average_strings[9], 10},
    };

    void map_case(const char *s) override {
        std::string str(s);

        m_cnt_map += m_map.at(str);
    }

    void switch_case(const char *s) override {
        /// Create at runtime
        FNVString hash(s);

        /// Switch over consts
        switch(hash){
            case FNVString(test_average_strings[0]):
                m_cnt_switch += 1;
                break;
            case FNVString(test_average_strings[1]):
                m_cnt_switch += 2;
                break;
            case FNVString(test_average_strings[2]):
                m_cnt_switch += 3;
                break;
            case FNVString(test_average_strings[3]):
                m_cnt_switch += 4;
                break;
            case FNVString(test_average_strings[4]):
                m_cnt_switch += 5;
                break;
            case FNVString(test_average_strings[5]):
                m_cnt_switch += 6;
                break;
            case FNVString(test_average_strings[6]):
                m_cnt_switch += 7;
                break;
            case FNVString(test_average_strings[7]):
                m_cnt_switch += 8;
                break;
            case FNVString(test_average_strings[8]):
                m_cnt_switch += 9;
                break;
            case FNVString(test_average_strings[9]):
                m_cnt_switch += 10;
                break;
        }
    }

public:

    explicit TestAverageStrings(int iterations, bool verbose)
            : Test(iterations, verbose) {}

    double test() {
        return test_case(test_average_strings);
    }

};
