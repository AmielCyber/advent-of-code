#include <iostream>
#include <numeric>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "InvalidIdCollector.h"

void parse_ids(std::ifstream& file, InvalidIdCollector& invalid_id_collector) {
  std::string line;
  std::getline(file, line); // One line

  std::stringstream ss(line);
  std::string range; // xxx-yyy
  while (std::getline(ss, range, ',')) {
    if (const size_t pos = range.find_first_of('-'); pos != std::string::npos) {
      const long low = std::stol(range.substr(0, pos)); // xxx
      const long high = std::stol(range.substr(pos+1));       // yyy
      invalid_id_collector.add_invalid_ids(low, high);
    }
  }
}

void parse_ids(const std::string& file_name, InvalidIdCollector& invalid_id_collector) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    std::cerr << "Could not open file \"" << file_name <<'"'<< '\n';
    return;
  }
  try {
    parse_ids(file, invalid_id_collector);
  }catch (...) {
    file.close();
    throw;
  }
  file.close();
}

int main() {
  InvalidIdCollector invalid_id_collector;
  parse_ids("./input.txt", invalid_id_collector);

  std::vector<long> result = invalid_id_collector.get_invalid_ids();
  // SUM ALL Invalid IDs.The answer will be a large number,so the answer is a long long, hence the 0LL
  std::cout << std::accumulate(result.begin(), result.end(), 0LL) << std::endl;
}