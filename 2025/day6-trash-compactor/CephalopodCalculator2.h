#ifndef DAY6_TRASH_COMPACTOR_CEPHALOPOD_CALCULATOR2_H
#define DAY6_TRASH_COMPACTOR_CEPHALOPOD_CALCULATOR2_H

#include <string>
#include <vector>
#include <utility>

class CephalopodCalculator2 {
    public:
    void add_equations(const std::string& equations);
    [[nodiscard]] long calculate() const;
private:
    std::vector<std::vector<std::string>> nums{};
    std::vector<char> ops{};
    // [start_pos,end_pos)
    std::vector<std::pair<size_t,size_t>> equation_pos{};
    void add_nums_to_vector(const std::string &input);
    void add_ops_to_vector(const std::string &input) ;

    [[nodiscard]] static long perform_cephalopod_math(const std::vector<std::string>& equation, size_t num_problems, char op);

};


#endif //DAY6_TRASH_COMPACTOR_CEPHALOPOD_CALCULATOR2_H