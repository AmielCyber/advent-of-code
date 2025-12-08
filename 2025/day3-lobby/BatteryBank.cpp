//
// Created by Amiel Nava on 12/7/25.
//

#include "BatteryBank.h"

void BatteryBank::add_optimal_batteries(const std::string &bank) {
  if (bank.empty()) {
    return;
  }
  if (bank.size() == 1) {
    battery_jolts.push_back(bank[0]-'0');
    return;
  }
  char largest_10 = bank[0];
  char largest_1 = '0'; // Give it a min possible value
  for (int i = 1; i < bank.size(); i++) {
    if (i < bank.size() - 1 && bank[i] > largest_10 ) {
      // largest_10 can only be largest if is not the last element.
      largest_10 = bank[i];
      largest_1 = '0'; // Reset largest_1 to min value
    }else if (bank[i] > largest_1 ) {
      largest_1 = bank[i];
    }
  }
  const int jolts = (largest_10 - '0') * 10 + (largest_1 - '0');
  battery_jolts.push_back(jolts);
}

std::vector<int> BatteryBank::get_optimal_batteries() {
  return battery_jolts;
}
