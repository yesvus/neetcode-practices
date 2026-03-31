#include "DynamicArray.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

struct Step {
  std::string operation;
  std::vector<int> arguments;
  std::string expected;
};

void fail(const Step &step, const std::string &actual) {
  std::cerr << "[FAIL] " << step.operation << "\n";
  std::cerr << "  expected: " << step.expected << "\n";
  std::cerr << "  actual:   " << actual << "\n";
  std::exit(1);
}

std::string runStep(DynamicArray *&arr, const Step &step) {
  if (step.operation == "DynamicArray") {
    delete arr;
    arr = new DynamicArray(step.arguments[0]);
    return "null";
  }

  if (step.operation == "pushback") {
    arr->pushback(step.arguments[0]);
    return "null";
  }

  if (step.operation == "set") {
    arr->set(step.arguments[0], step.arguments[1]);
    return "null";
  }

  if (step.operation == "get") {
    return std::to_string(arr->get(step.arguments[0]));
  }

  if (step.operation == "popback") {
    return std::to_string(arr->popback());
  }

  if (step.operation == "getSize") {
    return std::to_string(arr->getSize());
  }

  if (step.operation == "getCapacity") {
    return std::to_string(arr->getCapacity());
  }

  return "unknown";
}

int main() {
  std::vector<Step> steps = {
      {"DynamicArray", {2}, "null"},  {"getSize", {}, "0"},
      {"getCapacity", {}, "2"},       {"pushback", {10}, "null"},
      {"pushback", {20}, "null"},     {"get", {0}, "10"},
      {"get", {1}, "20"},             {"pushback", {30}, "null"},
      {"getCapacity", {}, "4"},       {"get", {2}, "30"},
      {"set", {1, 99}, "null"},       {"get", {1}, "99"},
      {"popback", {}, "30"},          {"getSize", {}, "2"},
      {"get", {0}, "10"},             {"get", {1}, "99"},
  };

  DynamicArray *arr = nullptr;

  for (const Step &step : steps) {
    std::string actual = runStep(arr, step);
    if (actual != step.expected) {
      fail(step, actual);
    }
    std::cout << step.operation << " -> " << actual << "\n";
  }

  delete arr;
  std::cout << "LeetCode-style class test passed.\n";
  return 0;
}
