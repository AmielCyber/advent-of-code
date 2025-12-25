#ifndef DAY6_TRASH_COMPACTOR_CEPHALOPOD_CALCULATOR_H
#define DAY6_TRASH_COMPACTOR_CEPHALOPOD_CALCULATOR_H
#include <string>
#include <vector>

class CephalopodCalculator {
  public:
  void add_equations(const std::string& equations);
  long calculate() const;
  private:
    std::vector<std::vector<long>> nums{};
    std::vector<char> ops{};
    void add_nums_to_vector(const std::string &input);
    void add_ops_to_vector(const std::string &input) ;
};

#endif //DAY6_TRASH_COMPACTOR_CEPHALOPOD_CALCULATOR_H