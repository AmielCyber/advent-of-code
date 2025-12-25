#include "CephalopodCalculator.h"
#include <sstream>
#include <numeric>

void CephalopodCalculator::add_equations(const std::string &equations) {
  add_nums_to_vector(equations);
  add_ops_to_vector(equations);
}

long CephalopodCalculator::calculate() const {
  std::vector<long> answers(ops.size());
  for (int i = 0; i < ops.size(); i++) {
    answers.at(i) = nums.at(0).at(i);
  }
  for (int i = 1; i < nums.size(); ++i) {
    for (int j = 0; j < ops.size(); ++j) {
      if (ops.at(j) == '*') {
        answers.at(j) *= static_cast<long>(nums.at(i).at(j));
      }else {
        answers.at(j) += static_cast<long>(nums.at(i).at(j));
      }
    }
  }
  return std::accumulate(answers.begin(), answers.end(), 0L);
}

void CephalopodCalculator::add_nums_to_vector(const std::string &input) {
  std::string str_num{};
  std::istringstream iss{input};
  std::string line{};
  while (std::getline(iss, line)) {
    std::istringstream iss2{line};
    nums.emplace_back();
    while (iss2 >> str_num) {
      try {
        int num = std::stoi(str_num);
        nums.back().emplace_back(num);
      }catch (...) {
        nums.pop_back();
        break;
      }
    }
  }
}

void CephalopodCalculator::add_ops_to_vector(const std::string &input) {
  std::string token{};
  std::istringstream iss{input};
  while (iss >> token) {
    if (!std::isdigit(token.at(0))) {
      ops.emplace_back(token.at(0));
    }
  }
}