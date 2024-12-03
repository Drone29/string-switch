
#pragma once
#include "times.h"
#include "fnv_string.hpp"
#include <ctime>
#include <iostream>

class Test {
private:
    int m_iterations = 0;
    bool m_verbose = false;
protected:

    int m_cnt_map = 0;
    int m_cnt_switch = 0;

    template<typename Callable, typename ...ARGS>
    Times run_test(Callable func, ARGS && ...args) {
        auto start = clock();
        for (int i = 0; i < m_iterations; ++i) {
            func(std::forward<ARGS>(args)...);
        }
        auto end = clock();
        auto t = double(end - start) / CLOCKS_PER_SEC;
        return {
                t,
                t / m_iterations
        };
    }

    virtual void map_case(const char *) = 0;
    virtual void switch_case(const char *) = 0;

    template<size_t SIZE>
    double test_case(const char * const (&test_strings)[SIZE]) {

        int counter = 0;
        Times map_avg{};
        Times switch_avg{};

        for (auto test_string : test_strings) {

            auto t1 = run_test([this](auto s) { map_case(s);}, test_string);
            auto t2 = run_test([this](auto s){ switch_case(s);}, test_string);

            if (m_cnt_switch != m_cnt_map) {
                throw std::runtime_error("invalid lookup");
            }

            if (m_verbose) {
                std::cout << "map total: " << t1.overall << ", average: " << t1.average << " sec.\n";
                std::cout << "switch total: " << t2.overall << ", average: " << t2.average << " sec.\n";
                std::cout << "gain: " << (t1.average / t2.average - 1) * 100 << "%\n";
                std::cout << "\n";
            }

            map_avg += t1;
            switch_avg += t2;

            counter++;
        }

        double gain_percent = (map_avg.average / switch_avg.average - 1) * 100;
        return gain_percent;
    }

public:
    explicit Test(int iterations, bool verbose)
            : m_iterations(iterations), m_verbose(verbose) {}


};

