#include "CephalopodCalculator2.h"
#include <numeric>
#include <sstream>

void CephalopodCalculator2::add_equations(const std::string &equations) {
  add_ops_to_vector(equations);
  add_nums_to_vector(equations);
}

long CephalopodCalculator2::calculate() const {
  std::vector<long> answers(ops.size());
  for (int col = 0; col < ops.size(); col++) {
    // Iterate each equation column
    std::vector<std::string> row_nums{};
    size_t max_digits = 0;
    for (const std::vector<std::string>& rows : nums) {
      // Iterate each row in the equation column
      row_nums.emplace_back(rows.at(col));
      if (max_digits < row_nums.back().size()) {
        // Save equation size to perform cephalopod math properly
        max_digits = row_nums.back().size();
      }
    }
    // Store answer for this equation column
    answers.at(col) = perform_cephalopod_math(row_nums, max_digits, ops.at(col));
  }
  return std::accumulate(answers.begin(), answers.end(), 0L);
}

void CephalopodCalculator2::add_nums_to_vector(const std::string &input) {
  std::string str_num{};
  std::istringstream iss{input};
  std::string line{};
  while (std::getline(iss, line) && !(line.at(0) == '*' || line.at(0) == '+')) {
    // Get a string with starting digits and trailing white spaces /d+/s*
    // Could have done a regex, but I did this first :(
    nums.emplace_back();
    for (auto [start_pos, end_pos]: equation_pos) {
      if (end_pos != std::string::npos) {
        nums.back().emplace_back(line.substr(start_pos, end_pos - start_pos));
      }else {
        nums.back().emplace_back(line.substr(start_pos));
      }
    }
  }
}

void CephalopodCalculator2::add_ops_to_vector(const std::string &input) {
  std::string line{};
  std::istringstream iss{input};
  // Skip all lines with numbers.
  while (std::getline(iss, line) && !(line.at(0) == '*' || line.at(0) == '+')) {
    if (line.at(0) == '*' || line.at(0) == '+') {
      break;
    }
  }
  // Iterate the line with operators
  for (size_t start_pos = 0; start_pos < line.size() && start_pos != std::string::npos;) {
    if (line.at(start_pos) == '*' || line.at(start_pos) == '+') {
      ops.emplace_back(line.at(start_pos));
    }
    size_t end_pos = line.find_first_not_of(' ', start_pos+1);
    // Register equation width to register the numbers properly later.
    equation_pos.emplace_back(start_pos, end_pos);
    start_pos = end_pos;
  }
  std::vector<std::string> equation{};
}

long CephalopodCalculator2::perform_cephalopod_math(const std::vector<std::string>& equation, const size_t num_problems, const char op) {
  long result = 0;
  for (int col = 0; col < num_problems ;col++) {
    std::string s_num;
    for (const auto & row : equation) {
      if (col < row.size() && row.at( col) != ' ') {
        // Get cephalopod number from top to bottom, order doesn't matter for *,+
        s_num += row.at( col);
      }
    }
    if (!s_num.empty()) {
      const long num = std::stol(s_num);
      if (col > 0) {
        if (op == '*') {
          result *= num ;
        }else {
          result += num ;
        }
      }else {
        result = num;
      }
    }
  }
  return result;
}