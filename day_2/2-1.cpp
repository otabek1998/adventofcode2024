#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::ifstream stream("day_2/input.txt");

  if (!stream) {
    std::cout << "No file found" << std::endl;
    return 0;
  }

  std::string line{};
  int output_number = 0;

  while (std::getline(stream, line)) {
    std::stringstream ss(line);
    std::vector<int> vec;
    int num;

    while (ss >> num) {
      vec.push_back(num);
    }

    bool is_increasing = (vec[1] > vec[0]);
    bool sequence_valid = true;
    for (int i = 0; i < static_cast<int>(vec.size() - 1); ++i) {
      int diff =
          (is_increasing) ? (vec[i + 1] - vec[i]) : (vec[i] - vec[i + 1]);
      if (diff > 3 || diff < 1) {
        sequence_valid = false;
        break; // Exit the loop early if the condition is not met
      }
    }

    if (sequence_valid) {
      output_number += 1;
      std::cout << output_number << std::endl;
    }
  }

  return 0;
}