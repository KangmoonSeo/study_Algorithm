#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// int tmp_count=0;

void cubic(int n) {
  int **randArr1 = new int *[n];
  for (int i = 0; i < n; i++) {
    randArr1[i] = new int[n];
  }

  int **randArr2 = new int *[n];
  for (int i = 0; i < n; i++) {
    randArr2[i] = new int[n];
    for (int j = 0; j < n; j++) {
      randArr1[i][j] = floor(rand() * 10);
      randArr2[i][j] = floor(rand() * 10);
    }
  }

  int **resultArr = new int *[n];
  for (int i = 0; i < n; i++) {
    resultArr[i] = new int[n];
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        count += randArr1[i][j] * randArr2[k][i];
        // tmp_count++;
      }
      resultArr[i][j] = count;
      count = 0;
    }
  }
}
int main() {
  time_t start, end;

  int input = 0, output = 0;
  cin >> input;

  start = clock();
  cubic(input);
  end = clock();
  output = end - start;
  // count << "곱 연산 횟수: " << tmp_count<<endl;

  cout << "n^3(Cubic complexity) execute times = " << output << " ms" << endl;

  return 0;
}
