
#pragma once

struct Times {
    double overall = 0.0;
    double average = 0.0;

    Times operator+(const Times &rhs) {
        Times res = *this;
        res += rhs;
        return res;
    }

    Times &operator+=(const Times &rhs) {
        overall += rhs.overall;
        average += rhs.average;
        return *this;
    }
};
