#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "maxProfit.cpp"

struct TestCase {
    std::string name;
    std::vector<int> prices;
    int expected;
};

std::vector<int> buildLongCase() {
    std::vector<int> prices;
    prices.reserve(200001);

    for (int price = 200000; price >= 1; --price) {
        prices.push_back(price);
    }

    prices.push_back(500000);
    return prices;
}

void printArray(const std::vector<int>& prices) {
    std::cout << "[";

    for (size_t i = 0; i < prices.size(); ++i) {
        std::cout << prices[i];
        if (i + 1 < prices.size()) {
            std::cout << ", ";
        }
    }

    std::cout << "]";
}

void runTest(const TestCase& testCase) {
    Solution solution;
    std::vector<int> prices = testCase.prices;
    int actual = solution.maxProfit(prices);

    if (actual != testCase.expected) {
        std::cerr << "[FAIL] " << testCase.name << "\n";
        std::cerr << "  expected: " << testCase.expected << "\n";
        std::cerr << "  actual:   " << actual << "\n";
        std::exit(1);
    }

    std::cout << "[PASS] " << testCase.name
              << " -> " << actual
              << " (size=" << prices.size() << ")\n";
}

int main() {
    std::vector<TestCase> testCases = {
        {"example_case", {7, 1, 5, 3, 6, 4}, 5},
        {"always_falling", {7, 6, 4, 3, 1}, 0},
        {"steady_rise", {1, 2, 3, 4, 5}, 4},
        {"one_big_jump", {9, 2, 10}, 8},
        {"late_best_buy", {8, 7, 2, 5, 1, 9}, 8},
        {"super_long_case", buildLongCase(), 499999},
    };

    for (const TestCase& testCase : testCases) {
        printArray(testCase.prices);
        std::cout << "\n";
        runTest(testCase);
    }

    std::cout << "All maxProfit tests passed.\n";
    return 0;
}
