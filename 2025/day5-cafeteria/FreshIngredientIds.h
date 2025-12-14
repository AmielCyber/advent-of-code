#ifndef DAY5_CAFETERIA_FRESH_INGREDIENT_IDS_H
#define DAY5_CAFETERIA_FRESH_INGREDIENT_IDS_H
#include <vector>


class FreshIngredientIds {
  public:
  explicit FreshIngredientIds(const std::vector<std::pair<long, long>>& id_ranges);
  [[nodiscard]] std::vector<std::pair<long, long>> get_id_ranges() const;
  [[nodiscard]] bool has(long id) const;
private:
  std::vector<std::pair<long,long>> ingredient_id_range;
};


#endif //DAY5_CAFETERIA_FRESH_INGREDIENT_IDS_H