#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "sorting.h"

bool issorted(const std::vector<int>& vec) {
  for (size_t i = 1; i < vec.size(); i++) {
    if (vec[i] < vec[i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  std::vector<int> arr(1000000);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 10000000);
  for (int& x : arr) {
    x = dis(gen);
  }

  auto start = std::chrono::high_resolution_clock::now();
  sort(arr);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;

  std::cout << "Is sorted:? " << issorted(arr) << std::endl;
  printf("%f", diff.count());

  return 0;
}
