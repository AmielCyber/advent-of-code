#include <iostream>
#include <string>
#include <fstream>
#include "FreshIngredientIds.h"

std::pair<std::vector<std::pair<long,long>>, std::vector<long>> get_input(const std::string& file_name) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    throw std::runtime_error("File \"" + file_name + "\"" + " does not exist");
  }
  std::string line;
  std::vector<std::pair<long,long>> ranges;
  while (std::getline(file, line) && !line.empty()) {
    const size_t range_char = line.find('-');
    const long low_range = std::stol(line.substr(0, range_char));
    const long high_range = std::stol(line.substr( range_char + 1));
    ranges.emplace_back(low_range, high_range);
  }
  std::vector<long> ids;
  while (std::getline(file, line)) {
    ids.emplace_back(std::stol(line));
  }
  file.close();
  return std::make_pair(ranges, ids);
}

int main() {
  auto[my_ranges, ids] = get_input("input.txt");
  FreshIngredientIds fresh_ingredient_ids{my_ranges};
  fresh_ingredient_ids.merge_ranges();

  /** Part 1
  long fresh_ingredients{0};
  for (const auto &id: ids) {
    if (fresh_ingredient_ids.has(id)) {
      ++fresh_ingredients;
    }
  }
  std::cout << "Total Fresh Ingredients: "<< fresh_ingredients << std::endl;
  */

  std::cout << "Total Fresh Ingredients: "<< fresh_ingredient_ids.size() << std::endl;
  return 0;
}