#include "FreshIngredientIds.h"
#include <algorithm>
#include <numeric>

FreshIngredientIds::FreshIngredientIds(const std::vector<std::pair<long, long> > &id_ranges) : ingredient_id_range(
  id_ranges) {
  std::ranges::sort(ingredient_id_range, [](const std::pair<long, long> &a, const std::pair<long, long> &b) {
    return a.first < b.first;
  });
}

std::vector<std::pair<long, long> > FreshIngredientIds::get_id_ranges() const {
  return ingredient_id_range;
}

bool FreshIngredientIds::has(const long id) const {
  return std::ranges::any_of(ingredient_id_range, [id](const std::pair<long, long> &range) {
    // id >= low && id <= high
    return id >= range.first && id <= range.second;
  });
}


void FreshIngredientIds::merge_ranges() {
  std::vector<std::pair<long, long> > merge_ranges;
  for (auto &id_range: ingredient_id_range) {
    if (merge_ranges.empty() || merge_ranges.back().second < id_range.first) {
      // |------| |----|
      merge_ranges.emplace_back(id_range);
    } else if (merge_ranges.back().second <= id_range.second) {
      // |---------|
      //       |--------|
      merge_ranges.back().second = id_range.second;
    } else if (merge_ranges.back().first > id_range.first) {
      throw std::domain_error("ingredient_id_range must be sorted.");
    }
    // |---------|
    //    |---|
    // Do nothing. Range already exists.
  }
  ingredient_id_range = merge_ranges;
}

long FreshIngredientIds::size() const {
  return std::accumulate(ingredient_id_range.cbegin(), ingredient_id_range.cend(), 0L,
                         [](const long sum, const std::pair<long, long> &range) {
                           return sum + (range.second - range.first + 1);
                         });
}
