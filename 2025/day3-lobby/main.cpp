#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <sstream>
#include <string>
#include "BatteryBank.h"

void parse_battery_banks(std::ifstream& file, BatteryBank& battery_bank) {
  std::string line;
  while (std::getline(file, line)) {
    battery_bank.add_optimal_batteries_part2(line, 12);
  }
}

void begin_parse(const std::string& file_name, BatteryBank& battery_bank) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    std::cerr << "Could not open file \"" << file_name <<'"'<< '\n';
    return;
  }
  try {
    parse_battery_banks(file, battery_bank);
  }catch (...) {
    file.close();
    throw;
  }
  file.close();
}

int main() {
  BatteryBank battery_bank;
  begin_parse("./input.txt", battery_bank);

  std::vector<long > optimal_battery_jolts = battery_bank.get_optimal_batteries();
  std::cout << "Result: ";
  std::cout << std::accumulate(optimal_battery_jolts.begin(), optimal_battery_jolts.end(), 0L);
  std::cout << std::endl;
  return 0;
}