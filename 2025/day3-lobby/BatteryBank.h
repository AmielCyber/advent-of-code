//
// Created by Amiel Nava on 12/7/25.
//
#ifndef DAY3_LOBBY_BATTERY_BANK_H
#define DAY3_LOBBY_BATTERY_BANK_H
#include <vector>


class BatteryBank {
  public:
  void add_optimal_batteries(const std::string& bank);
  void add_optimal_batteries_part2(const std::string& bank, int k = 2);
  std::vector<long> get_optimal_batteries();
  private:
  std::vector<long> battery_jolts;
  void add_char_vector_jolts_to_battery_vector_jolts(const std::vector<char>& battery);
};


#endif //DAY3_LOBBY_BATTERY_BANK_H