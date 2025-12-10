#include "ForkliftGrid.h"
#include <iostream>
#include <fstream>

std::vector<std::vector<char>> parse_grid_input(const std::string& file_name) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file \"" + file_name +'"');
  }
  try {
    std::vector<std::vector<char>> grid;
    size_t row = 0;
    std::string line;
    while (std::getline(file, line)) {
      grid.emplace_back(line.size());
      for (int col = 0; col < line.size(); ++col) {
        grid[row][col] = line[col];
      }
      row++;
    }
    file.close();
    return grid;
  }catch (...) {
    file.close();
    throw;
  }
}

int main() {
  std::vector<std::vector<char>> grid = parse_grid_input("input.txt");
  // Part 1
  // const ForkliftGrid foklift(grid);
  // std::cout << "Rolls of paper: " << foklift.get_rolls_of_paper_to_move() << std::endl;
  // Part 2
  ForkliftGrid foklift(grid);
  std::cout << "Rolls of paper: " << foklift.get_rolls_of_paper_to_move_part_2() << std::endl;
  return 0;
}