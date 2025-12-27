#ifndef DAY7_LABORATORIES_Tachyon_Manifold_H
#define DAY7_LABORATORIES_Tachyon_Manifold_H
#include <vector>
#include <string>

class TachyonManifold {
public:
  void add_diagram(const std::string &diagram_str);

  [[nodiscard]] long number_of_beam_splits() const;

private:
  const char START = 'S';
  const char SPLITTER = '^';
  std::vector<std::vector<char> > diagram{};

  void split_beam(size_t splitter_pos, std::vector<bool> &beam_above) const;
};

#endif //DAY7_LABORATORIES_Tachyon_Manifold_H
