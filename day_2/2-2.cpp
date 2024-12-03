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

    bool inner_valid = true;

    for (int i = 0; i < static_cast<int>(vec.size()); ++i) {
      std::vector<int> new_vec{vec};
      new_vec.erase(new_vec.begin() + i);
      bool is_inner_increasing = (new_vec[1] > new_vec[0]);
      inner_valid = true;
      for (int j = 0; j < static_cast<int>(new_vec.size() - 1); ++j) {
        int diff = (is_inner_increasing) ? (new_vec[j + 1] - new_vec[j])
                                         : (new_vec[j] - new_vec[j + 1]);
        if (diff > 3 || diff < 1) {
          inner_valid = false;
          break;
        }
      }
      if (inner_valid) {
        output_number += 1;
        break;
      }
    }
  }

  std::cout << output_number << std::endl;

  return 0;
}