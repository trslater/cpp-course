// 05-solution.cpp by Bill Weinman <http://bw.org/>
// updated 2022-05-26
#include <fmt/core.h>
#include <iostream>

using fmt::format;
using std::cout;

int main() {
    bool prime_flag {false};

    // outer loop for prime candidates 2-99
    for (auto candidate = 2; candidate < 100; ++candidate) {

        // test candidate for factors
        prime_flag = true;
        for (auto factor = 2; factor < candidate; ++factor) {
            if (candidate % factor == 0) {
                prime_flag = false;
                break;
            }
        }

        // print if it's prime
        if (prime_flag) cout << format("{} ", candidate);
    }

    // end with a newline
    cout << '\n';
}
