#ifndef DAY4_PRINTING_DEPARTMENT_FORKLIFT_GRID_H
#define DAY4_PRINTING_DEPARTMENT_FORKLIFT_GRID_H
#include <vector>

class ForkliftGrid {
public:
  explicit ForkliftGrid(std::vector<std::vector<char>> grid);
  long get_rolls_of_paper_to_move() const;
private:
  const char PAPER = '@';
  const int MAX_ADJ_PAPER = 3;
  std::vector<std::vector<char>> grid;
  bool is_within_bounds(int row, int col) const;
  bool is_accessible(int row, int col) const;
};

#endif //DAY4_PRINTING_DEPARTMENT_FORKLIFT_GRID_H