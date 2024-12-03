#include <iostream>
#include "test/test_short_strings.h"
#include "test/test_average_strings.h"
#include "test/test_longer_strings.h"

int main(int argc, char** argv){

    // example
    if (argc > 1) {
        FNVString hash(argv[1]);
        switch (hash) {
            case FNVString("abc"):
                std::cout << "first case triggered" << std::endl;
                break;
            case FNVString("123"):
                std::cout << "second case triggered" << std::endl;
                break;
            case FNVString("Hello World!"):
                std::cout << "third case triggered" << std::endl;
                break;
            default:
                std::cout << "Unknown case: " << hash.get_str() << std::endl;
        }
    }

    const int iterations = 1000000;

    std::cout << "Num iterations: " << iterations << "\n" << std::endl;

    TestShortStrings short_test(iterations, true);
    TestAverageStrings average_test(iterations, true);
    TestLongerStrings longer_test(iterations, true);

    std::cout << "Testing with short strings..." << std::endl;
    auto avg_gain = short_test.test();
    std::cout << "switch/map short strings average gain: " << avg_gain << "%\n\n";

    std::cout << "Testing with average strings..." << std::endl;
    avg_gain = average_test.test();
    std::cout << "switch/map average strings average gain: " << avg_gain << "%\n\n";

    std::cout << "Testing with longer strings..." << std::endl;
    avg_gain = longer_test.test();
    std::cout << "switch/map longer strings average gain: " << avg_gain << "%\n\n";

    return 0;

}
