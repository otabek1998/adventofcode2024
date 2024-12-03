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
  std::sort(left_column_numbers.begin(), left_column_numbers.end());
  std::sort(right_column_numbers.begin(), right_column_numbers.end());

  int sum = 0;
  for (int i = 0; i < static_cast<int>(left_column_numbers.size()); ++i) {
    int curr = left_column_numbers[i] - right_column_numbers[i];
    if (curr < 0) {
      curr = -curr;
    }
    sum += curr;
  }
  std::cout << sum << std::endl;

  return 0;
}