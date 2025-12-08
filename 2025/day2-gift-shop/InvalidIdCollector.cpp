#include "InvalidIdCollector.h"

void InvalidIdCollector::add_invalid_ids(const long low, const long high) {
  for (long i = low; i <= high; i++) {
    if (is_symmetric_part2(i)) {
      invalidIds.push_back(i);
    }
  }
}

std::vector<long> InvalidIdCollector::get_invalid_ids() {
  return invalidIds;
}

bool InvalidIdCollector::is_symmetric(const long num) {
  const std::string num_str = std::to_string(num);
  if (num_str.size() % 2 != 0) {
    return false;
  }
  return num_str.substr(0, num_str.size() / 2) == num_str.substr(num_str.size() / 2);
}

bool InvalidIdCollector::is_symmetric_part2(const long num) {
  const std::string num_str = std::to_string(num);
  // Start with the largest chunk all the way down to size 1
  for (int str_len = static_cast<int>(num_str.size()) / 2; str_len > 0 ; --str_len) {
    if (num_str.size() % str_len != 0) continue; // Cannot have duplicate sequential digits based on length
    std::string chunk = num_str.substr(0, str_len);
    for (int start_pos = str_len; start_pos < num_str.size(); start_pos += str_len) {
      if (num_str.find(chunk, start_pos) != start_pos) {
        break;
      }
      if (start_pos == num_str.size() - str_len) {
        return true;
      }
    }
  }
  return false;
}
