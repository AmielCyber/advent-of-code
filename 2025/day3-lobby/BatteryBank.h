//
// Created by Amiel Nava on 12/7/25.
//
#ifndef DAY3_LOBBY_BATTERY_BANK_H
#define DAY3_LOBBY_BATTERY_BANK_H
#include <vector>


class BatteryBank {
  public:
  void add_optimal_batteries(const std::string& bank);
  std::vector<int> get_optimal_batteries();
  private:
  std::vector<int> battery_jolts;
};


#endif //DAY3_LOBBY_BATTERY_BANK_H