//
// Created by Amiel Nava on 12/6/25.
//

#include "Dial.h"

Dial::Dial() = default;

void Dial::left_rotation(int amount) {
  const int point_sum = point - normalize(amount);
  const int new_point = normalize(point_sum);
  update_zero_count_part2(amount, point_sum, new_point);
  point =  new_point;
}

void Dial::right_rotation(int amount) {
  const int point_sum = point + normalize(amount);
  const int new_point = normalize(point_sum);
  update_zero_count_part2(amount, point_sum, new_point);
  point =  new_point;
}

int Dial::normalize(const int amount) const {
  // Get only positive values.
  return (amount % num_of_points + num_of_points) % num_of_points;
}

void Dial::update_zero_point_count() {
  if (point == 0) {
    zero_point_count++;
  }
}

void Dial::update_zero_count_part2(const int amount, const int point_sum, const int new_point) {
  if ((point_sum > num_of_points || point_sum < 0) && point != 0){
    // Pass zero and not starting from zero.
    zero_point_count++;
  }
  const int complete_rotations = amount / num_of_points;
  if (complete_rotations > 0) {
    // Add total rotations.
    zero_point_count += complete_rotations;;
  }
  if (new_point == 0 && ((amount % num_of_points) != 0)) {
    // New point points at zero.
    zero_point_count++;
  }
}

int Dial::get_zero_point_count() const {
  return zero_point_count;
}
