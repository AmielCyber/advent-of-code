#include <iostream>
#include <fstream>
#include <sstream>

#include "TachyonManifold.h"

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
  TachyonManifold manifold;
  {
    const std::string contents = get_file_contents("input.txt");
    manifold.add_diagram(contents);
  }
  std::cout << "Number of light split by beams: " << manifold.number_of_beam_splits() << std::endl;
  return 0;
}
