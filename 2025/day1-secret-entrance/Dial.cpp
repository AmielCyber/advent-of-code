//
// Created by Amiel Nava on 12/6/25.
//

#include "Dial.h"

Dial::Dial() = default;

void Dial::left_rotation(int amount) {
  amount = normalize(amount);
  const int new_point = point - amount;
  point =  normalize(new_point);
  update_zero_point_count();
}

void Dial::right_rotation(int amount) {
  amount = normalize(amount);
  const int new_point = point + amount;
  point =  normalize(new_point);
  update_zero_point_count();
}

int Dial::normalize(const int amount) const {
    return amount % num_of_points;
}

void Dial::update_zero_point_count() {
  if (point == 0) {
    zero_point_count++;
  }
}

int Dial::get_zero_point_count() const {
  return zero_point_count;
}
