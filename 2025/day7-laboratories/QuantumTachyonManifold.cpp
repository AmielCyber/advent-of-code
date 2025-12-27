#include "QuantumTachyonManifold.h"
#include <numeric>

void QuantumTachyonManifold::add_diagram(const std::string &diagram_str) {
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

long QuantumTachyonManifold::number_of_time_lines() const {
  if (diagram.empty()) {
    return 0;
  }
  std::vector<long> beam_above(diagram.at(0).size());
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
        split_time_line(j, beam_above);
      }
    }
  }
  return std::accumulate(beam_above.begin(), beam_above.end(), 0L);
}

void QuantumTachyonManifold::split_time_line(const size_t splitter_pos, std::vector<long> &beam_above) const {
  if (splitter_pos > 0) {
    // Split to left, set previous timelines to this timeline
    beam_above.at(splitter_pos - 1) += beam_above.at(splitter_pos);
  }
  if (splitter_pos < diagram.size() - 1) {
    // Split to right, set previous timelines to this timeline
    beam_above.at(splitter_pos + 1) += beam_above.at(splitter_pos);
  }
  // Ended timeline at this beam
  beam_above.at(splitter_pos) = 0;
}
