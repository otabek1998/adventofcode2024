#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream stream("day_1/input.txt");

  if (!stream) {
    std::cout << "No file found" << std::endl;
    return 0;
  }

  int left_column_input, right_column_input;
  std::vector<int> left_column_numbers{};
  std::vector<int> right_column_numbers{};

  while (stream >> left_column_input >> right_column_input) {
    left_column_numbers.push_back(left_column_input);
    right_column_numbers.push_back(right_column_input);
  }

  int sum = 0;
  for (const auto &left_column_number : left_column_numbers) {
    int times = 0;
    for (const auto &right_column_number : right_column_numbers) {
      if (right_column_number == left_column_number) {
        times += 1;
      }
    }
    sum += left_column_number * times;
  }
  std::cout << sum << std::endl;

  return 0;
}