#include "ForkliftGrid.h"

#include <utility>

ForkliftGrid::ForkliftGrid(std::vector<std::vector<char> > grid) : grid(std::move(grid)) {
}

long ForkliftGrid::get_rolls_of_paper_to_move() const {
  long rolls_of_paper = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == PAPER && is_accessible(i, j)) {
        ++rolls_of_paper;
      }
    }
  }
  return rolls_of_paper;
}

long ForkliftGrid::get_rolls_of_paper_to_move_part_2() {
  long rolls_of_paper = 0;
  bool did_cleanup = true;
  while (did_cleanup) {
    did_cleanup = false;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == PAPER && is_accessible(i, j)) {
          ++rolls_of_paper;
          grid[i][j] = EMPTY;
          did_cleanup = true;
        }
      }
    }
  }
  return rolls_of_paper;
}

bool ForkliftGrid::is_within_bounds(const int row, const int col) const {
  return row > -1 && row < grid.size() && col > -1 && col < grid[row].size();
}

bool ForkliftGrid::is_accessible(const int row, const int col) const {
  int adjacent_papers = 0;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      if (i == 0 && j == 0) continue;
      if (is_within_bounds(row + i, col + j) && grid[row + i][col + j] == PAPER) {
        ++adjacent_papers;
      }
      if (adjacent_papers > MAX_ADJ_PAPER) return false;
    }
  }
  return true;
}
