#include <iostream>
#include <fstream>
#include <sstream>

#include "QuantumTachyonManifold.h"

std::string get_file_contents(const std::string &file_name) {
  std::ifstream file(file_name);
  std::stringstream ss;
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file '" + file_name + "'");
  }
  ss << file.rdbuf();
  file.close();
  return ss.str();
}

int main() {
  // TachyonManifold manifold; //Part 1
  QuantumTachyonManifold manifold;
  {
    const std::string contents = get_file_contents("input.txt");
    manifold.add_diagram(contents);
  }
  // std::cout << "Number of light split by beams: " << manifold.number_of_beam_splits() << std::endl;
  std::cout << "Number of time lines: " << manifold.number_of_time_lines() << std::endl;

  return 0;
}
