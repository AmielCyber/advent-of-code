#include "FreshIngredientIds.h"
#include <algorithm>

FreshIngredientIds::FreshIngredientIds(const std::vector<std::pair<long, long>>& id_ranges) : ingredient_id_range(id_ranges) {
  std::ranges::sort(ingredient_id_range, [](const std::pair<long,long>& a, const std::pair<long,long>& b) {
    return a.first < b.first;
  });
}

std::vector<std::pair<long, long>> FreshIngredientIds::get_id_ranges() const {
  return ingredient_id_range;
}

bool FreshIngredientIds::has(const long id) const {
  return std::ranges::any_of(ingredient_id_range, [id](const std::pair<long, long>& range) {
    // id >= low && id <= high
    return id >= range.first && id <= range.second;
  });
}
