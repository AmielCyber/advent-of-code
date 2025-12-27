#ifndef DAY7_LABORATORIES_QUANTUM_TACHYON_MANIFOLD_H
#define DAY7_LABORATORIES_QUANTUM_TACHYON_MANIFOLD_H

#include <string>
#include <vector>

class QuantumTachyonManifold {
public:
  void add_diagram(const std::string &diagram_str);

  [[nodiscard]] long number_of_time_lines() const;

private:
  const char START = 'S';
  const char SPLITTER = '^';
  std::vector<std::vector<char> > diagram{};

  void split_time_line(size_t splitter_pos, std::vector<long> &beam_above) const;
};

#endif //DAY7_LABORATORIES_QUANTUM_TACHYON_MANIFOLD_H