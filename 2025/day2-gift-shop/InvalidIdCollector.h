//
// Created by Amiel Nava on 12/7/25.
//

#ifndef DAY2_GIFT_SHOP_INVALID_ID_COLLECTOR_H
#define DAY2_GIFT_SHOP_INVALID_ID_COLLECTOR_H
#include <vector>


class InvalidIdCollector {
public:
  InvalidIdCollector() = default;
  void add_invalid_ids(long low, long high);
  std::vector<long> get_invalid_ids();
private:
  std::vector<long> invalidIds;
  static bool is_symmetric(long num);
  static bool is_symmetric_part2(long num);
};


#endif //DAY2_GIFT_SHOP_INVALID_ID_COLLECTOR_H