#include <iostream>
#include <fstream>
#include "Dial.h"

void parse_rotations(std::ifstream& file, Dial& dial) {
  std::string line;
  int rotations = 0;
  while (std::getline(file, line)) {
    const char orientation = line[0];
    try {
      rotations = std::stoi(line.substr(1));
    }catch (std::invalid_argument& e) {
      std::cout << e.what() << '\n';
      std::cout << "Invalid input: \"" << line << '\"' << '\n';
    }
    if (orientation == 'R') {
      dial.right_rotation(rotations);
    }
    if (orientation == 'L') {
      dial.left_rotation(rotations);
    }
  }
}

int main(int _, char *argv[]) {
  Dial dial;
  const std::string file_name{argv[1]};
  std::ifstream file(file_name);
  if (!file.is_open()) {
    std::cerr << "Could not open file \"" << file_name <<'"'<< '\n';
    return 1;
  }

  try {
    parse_rotations(file, dial);
  }catch (...) {
    file.close();
    throw;
  }
  file.close();
  std::cout << dial.get_zero_point_count() << '\n';
  return 0;
}
