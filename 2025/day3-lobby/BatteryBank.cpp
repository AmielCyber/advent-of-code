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

/**
 *  TIME: O(NK^2)
 *  Space: O(K)
 */
void BatteryBank::add_optimal_batteries_part2(const std::string &bank, const int k) {
  if (bank.empty()) {
    return;
  }
  std::vector<char> optimal(k, '0');
  int curr = 0;
  for (int i = 0; i < bank.size(); i++) {
    if (optimal[curr] < bank[i]) {
      // Find pointer to the left where optimal[curr] >= bank[i] and optimal[curr+1] < bank[i]
      // AKA Insertion Sort
      for (;curr > -1 && optimal[curr] < bank[i] && optimal.size()-curr <= bank.size() - i ; --curr) {
        optimal[curr] = '0';
      }
      curr++;
      optimal[curr] = bank[i];
    }else if (curr != optimal.size() - 1) {
      // Add value to any zeros to the right of current
      curr = curr + 1;
      optimal[curr] = bank[i];
    }
  }
  add_char_vector_jolts_to_battery_vector_jolts(optimal);
}

std::vector<long > BatteryBank::get_optimal_batteries() {
  return battery_jolts;
}

void BatteryBank::add_char_vector_jolts_to_battery_vector_jolts(const std::vector<char> &battery) {
  long jolts = 0;
  for (int i = 0; i < battery.size() && battery[i] != '0'; i++) {
    jolts += battery[i] - '0';
    if (i < battery.size() - 1) {
      jolts *= 10;
    }
  }
  battery_jolts.push_back(jolts);
}
