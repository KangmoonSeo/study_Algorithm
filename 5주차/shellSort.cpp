#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

int n = 0;  // Length of vector
int s = 1;  // 1-shellSort1, 2-shellSort2, 3-shellSort3.

// Random vector를 생성하는 함수
vector<int> randomVector(int num) {
  vector<int> vec(num);
  srand(time(NULL));
  for (int i = 0; i < num; i++) {
    vec[i] = rand() % num;  // Generating random integers between 0 to n
  }
  return vec;
}

// gap sequence를 생성하는 함수
vector<int> generateGap(int num, int weight = 3) {
  vector<int> vec(0);
  int key = 1;
  while (true) {
    key = key * weight;
    if (weight != 2) key = key + 1;
    if (key * weight >= num) break;
    vec.push_back(key);
  }
  reverse(vec.begin(), vec.end());
  vec.push_back(1);
  return vec;
}

// 특정 간격으로 array를 insertion Sort하는 함수
void insertionSort(vector<int>& arr, int interval) {
  int length = arr.size();
  int key, j;
  for (int i = interval; i < length; i += interval) {
    key = arr[i];
    j = i - interval;

    while (j >= 0 && arr[j] > key) {
      arr[j + interval] = arr[j];
      j = j - interval;
    }
    arr[j + interval] = key;
  }
}

// shell sort
void shellSort(vector<int>& arr, vector<int>& keyset) {
  for (int w = 0; w < keyset.size(); w++) {
    insertionSort(arr, keyset[w]);
  }
}
void shellSort1(vector<int>& arr) {
  vector<int> k = generateGap(n, 2);
  shellSort(arr, k);
}
void shellSort2(vector<int>& arr) {
  vector<int> k = generateGap(n, 3);
  shellSort(arr, k);
}
void shellSort3(vector<int>& arr) {
  vector<int> k = generateGap(n, 11);
  shellSort(arr, k);
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
  cout << "select the function you execute. 1-shellSort1, 2-shellSort2, "
          "3-shellSort3.\n: ";
  cin >> s;
  cout << "put the length of random vector.\n: ";
  cin >> n;

  vector<int> vec = randomVector(n);

  auto start = chrono::high_resolution_clock::now();
  switch (s) {
    case 2:
      shellSort2(vec);
      break;
    case 3:
      shellSort3(vec);
      break;
    case 1:
    default:
      shellSort1(vec);
      break;
  }
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> duration = end - start;

  cout << "Runtime: " << duration.count() << " seconds." << endl;
  checkSort(vec);

  return 0;
}
