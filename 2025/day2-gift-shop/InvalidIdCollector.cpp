#include "InvalidIdCollector.h"

void InvalidIdCollector::add_invalid_ids(const long low, const long high) {
  for (long i = low; i <= high; i++) {
    if (is_symmetric(i)) {
      invalidIds.push_back(i);
    }
  }
}

std::vector<long long> InvalidIdCollector::get_invalid_ids() {
  return invalidIds;
}

bool InvalidIdCollector::is_symmetric(const long num) {
  const std::string num_str = std::to_string(num);
  if (num_str.size() % 2 != 0) {
    return false;
  }
  return num_str.substr(0, num_str.size() / 2) == num_str.substr(num_str.size() / 2);
}
