#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "CephalopodCalculator.h"
#include "CephalopodCalculator2.h"

std::string get_file_contents(const std::string& file_name) {
  std::ifstream file(file_name);
  std::stringstream ss;
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file '" + file_name + "'");
  }
  ss << file.rdbuf();
  file.close();
  return ss.str();
}

int main() {
  // CephalopodCalculator calculator{}; // Part 1
  CephalopodCalculator2 calculator{};
  {
    const std::string file_name{"input.txt"};
    const std::string equations{get_file_contents(file_name)};
    calculator.add_equations(equations);
  }
  std::cout << "Answer: " << calculator.calculate() << std::endl;
  return 0;
}