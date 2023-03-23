#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

vector<int> randomVector(int n) {
  vector<int> vec(n);
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    vec[i] = rand() % 100;  // Generating random integers between 0 to 99
  }
  return vec;
}

void bubbleSort(vector<int>& arr) {
  int length = arr.size();

  int tmp;
  for (size_t i = 0; i < length; i++) {
    for (size_t j = 0; j < length; j++) {
      if (arr[j] > arr[i]) {
        tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
      }
    }
  }
}

int main() {
  int n = 10;  // Length of vector
  cout << "put the length of random vector.\n: ";
  cin >> n;
  vector<int> vec = randomVector(n);

  bool printMode = true;

  char _tmp = 'y';
  cout << "print output? (y/n)\n: ";
  cin >> _tmp;
  printMode = (_tmp == 'n') ? false : true;  //

  if (printMode) {
    cout << "Random Vector: ";
    for (int i = 0; i < n; i++) {
      cout << vec[i] << " ";  // Printing the generated vector
    }
  }
  time_t tic, toc;

  tic = clock();
  bubbleSort(vec);
  toc = clock();
  if (printMode) {
    cout << "\nSorted Vector: ";
    for (int i = 0; i < n; i++) {
      cout << vec[i] << " ";  // Printing the sorted vector
    }
    cout << endl;
  }
  cout << "bubble sort execute times(n:" << n << ") = " << toc - tic << " ms"
       << endl;
}
