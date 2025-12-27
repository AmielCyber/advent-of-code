#include "TachyonManifold.h"

void TachyonManifold::add_diagram(const std::string &diagram_str) {
  if (!diagram.empty()) {
    diagram.clear();
    diagram.shrink_to_fit();
  }
  diagram.emplace_back();
  for (const char ch: diagram_str) {
    if (ch == '\n') {
      diagram.emplace_back();
    } else {
      diagram.back().push_back(ch);
    }
  }
}

long TachyonManifold::number_of_beam_splits() const {
  long result = 0;
  if (diagram.empty()) {
    return result;
  }
  std::vector<bool> beam_above(diagram.at(0).size());
  for (size_t i = 0; i < diagram.at(0).size(); ++i) {
    // Find starting bean and record it
    if (diagram.at(0).at(i) == START) {
      beam_above.at(i) = true;
      break;
    }
  }
  for (size_t i = 1; i < diagram.size(); ++i) {
    // Look for splitters and split beam if a beam is above
    for (size_t j = 0; j < diagram.at(i).size(); ++j) {
      if (diagram.at(i).at(j) == SPLITTER && beam_above.at(j)) {
        split_beam(j, beam_above);
        ++result;
      }
    }
  }
  return result;
}

void TachyonManifold::split_beam(const size_t splitter_pos, std::vector<bool> &beam_above) const {
  if (splitter_pos > 0) {
    // Split to left
    beam_above.at(splitter_pos - 1) = true;
  }
  if (splitter_pos < diagram.size() - 1) {
    // Split to right
    beam_above.at(splitter_pos + 1) = true;
  }
  beam_above.at(splitter_pos) = false;
}
