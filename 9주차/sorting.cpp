#include "sorting.h"

void sort(std::vector<int>& arr) {
  // Modify below
  // TODO: code your own sorting algorithms
  int n = arr.size();
  for (std::size_t i = n; i > 0; i--) {
    for (std::size_t j = 1; j < i; j++) {
      if (arr[j - 1] > arr[j]) {
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
      }
    }
  }
}
