#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

vector<int> randomVector(int n) {
  vector<int> vec(n);
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    vec[i] = rand() % n;  // Generating random integers between 0 to n
  }
  return vec;
}
void insertionSort(vector<int>& arr) {
  int length = arr.size();

  int key, j;
  for (int i = 1; i < length; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

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
  int n = 10;  // Length of vector
  cout << "put the length of random vector.\n: ";
  cin >> n;
  vector<int> vec = randomVector(n);

  auto start = chrono::high_resolution_clock::now();
  insertionSort(vec);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> duration = end - start;

  cout << "Runtime: " << duration.count() << " seconds." << endl;
  checkSort(vec);

  return 0;
}
