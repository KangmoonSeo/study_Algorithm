#include <ctime>
#include <iostream>

using namespace std;

int fibo(int n) {
  int output = 0;
  if (n == 0) {
    output = 0;
  } else if (n <= 2) {
    output = 1;
  } else {
    output = fibo(n - 1) + fibo(n - 2);
  }
  return output;
}
int main() {
  time_t start, end;

  int input = 0, output = 0, result;
  cin >> input;

  start = clock();
  result = fibo(input);
  end = clock();
  output = end - start;

  // cout << result << endl;
  cout << "2^n(Exponential complexity) execute times = " << output << " ms"
       << endl;

  return 0;
}
