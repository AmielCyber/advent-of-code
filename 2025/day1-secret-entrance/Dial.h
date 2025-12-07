#ifndef DAY1_SECRET_ENTRANCE_DIAL_H
#define DAY1_SECRET_ENTRANCE_DIAL_H

class Dial {
public:
  Dial();
  void left_rotation(int amount);
  void right_rotation(int amount);
  int get_zero_point_count() const;

private:
  int point = 50;
  int zero_point_count = 0;
  int num_of_points = 100;
  int normalize(int amount) const;
  void update_zero_point_count();
  void update_zero_count_part2(int amount, int point_sum, int new_point);
};
#endif //DAY1_SECRET_ENTRANCE_DIAL_H