#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool isMaxHeap = true;

// Random vector를 생성하는 함수
vector<int> randomVector(int num) {
  vector<int> vec(num);
  srand(time(NULL));
  for (int i = 0; i < num; i++) {
    vec[i] = rand() % num;  // Generating random integers between 0 to n
  }
  return vec;
}

void heapify(vector<int>& arr, int index, int heapSize) {
  int leftChildIndex = 2 * index + 1;
  int rightChildIndex = 2 * index + 2;
  int largestIndex = index;  // isMaxHeap == false -> smallestIndex

  if (leftChildIndex < heapSize &&
      (!isMaxHeap ^ (arr[leftChildIndex] > arr[largestIndex]))) {
    largestIndex = leftChildIndex;
  }
  if (rightChildIndex < heapSize &&
      (!isMaxHeap ^ (arr[rightChildIndex] > arr[largestIndex]))) {
    largestIndex = rightChildIndex;
  }
  if (largestIndex != index) {
    swap(arr[index], arr[largestIndex]);
    heapify(arr, largestIndex, heapSize);
  }
}
void buildHeap(vector<int>& arr) {
  int length = arr.size();
  for (int i = floor(length / 2); i >= 0; i--) {
    heapify(arr, i, length);
  }
}

// 특정 간격으로 array를 insertion Sort하는 함수
void heapSort(vector<int>& arr) {
  int length = arr.size();
  buildHeap(arr);

  for (int i = length - 1; i >= 1; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, 0, i);
  }
  if (!isMaxHeap) reverse(arr.begin(), arr.end());
}

// 해당 array가 sorted인지 확인하는 함수
void checkSort(vector<int>& a) {
  bool sorted = true;
  int length = a.size();
  for (int i = 0; i < length - 1; i++) {
    if (a[i] > a[i + 1]) {
      sorted = false;
      break;
    }
  }
  if (sorted)
    cout << "sort completed.\n";
  else
    cout << "sort error!!\n";
}

int main() {
  int n = 0;  // Length of vector

  cout << "put the length of random vector.\n: ";
  cin >> n;

  vector<int> vec = randomVector(n);
  vector<int> vec2;
  vec2.assign(vec.begin(), vec.end());

  auto start = chrono::high_resolution_clock::now();
  heapSort(vec);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> duration = end - start;

  cout << "Runtime using MaxHeap: " << duration.count() << " seconds." << endl;
  checkSort(vec);

  isMaxHeap = false;

  start = chrono::high_resolution_clock::now();
  heapSort(vec2);
  end = chrono::high_resolution_clock::now();
  duration = end - start;

  cout << "Runtime using MinHeap: " << duration.count() << " seconds." << endl;
  checkSort(vec2);



  return 0;
}
