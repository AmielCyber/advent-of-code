#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <sstream>

#include "CephalopodCalculator.h"

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


int get_largest_tenth_in_column(std::vector<std::vector<int>>& nums, int column) {
  const int largest = std::ranges::max(nums.at(column));
  const int zeros = std::ceil(std::log10(largest));
  return static_cast<int>(std::pow(10, zeros));
}


int main() {
  CephalopodCalculator calculator{};
  {
    const std::string file_name{"input.txt"};
    const std::string equations{get_file_contents(file_name)};
    calculator.add_equations(equations);
  }
  std::cout << "Answer: " << calculator.calculate() << std::endl;
  return 0;
}