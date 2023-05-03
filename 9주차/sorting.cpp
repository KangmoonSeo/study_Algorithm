#include "sorting.h"
using namespace std;

void swap(vector<int>& arr, int a, int b) {
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

void insertionSort(vector<int>& arr, int left, int right) {
  int key, j;
  for (int i = left; i <= right; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int partition(vector<int>& arr, int left, int right) {
  int pivotIndex = (left + right) / 2;
  int pivotValue = arr[pivotIndex];
  swap(arr, pivotIndex, right);
  int storeIndex = left;
  for (int i = left; i < right; i++) {
    if (arr[i] < pivotValue) {
      swap(arr, i, storeIndex);
      storeIndex++;
    }
  }
  swap(arr, storeIndex, right);
  return storeIndex;
}

void quickSort(vector<int>& arr, int left, int right) {
  if (left >= right) return;
  if (right - left < 10) {
    insertionSort(arr, left, right);
  } else {
    int pivotIndex = partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
  }
}

void sort(std::vector<int>& arr) {
  quickSort(arr, 0, arr.size());
}
