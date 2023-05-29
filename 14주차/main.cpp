#include <iostream>
#include <vector>
#define weight first
#define value second
using namespace std;

void solve(int const& W, vector<pair<int, int> > const& vec) {
  int N = vec.size();
  vector<vector<int> > P(N + 1, vector<int>(W + 1));
  
  for (int i = 1; i <= N; i++) {
    pair<int, int> p = vec[i - 1];
    for (int w = 0; w <= W; w++) {
      if (w - p.weight >= 0) {
        P[i][w] = max(P[i - 1][w], p.value + P[i - 1][w - p.weight]);
      } else {
        P[i][w] = P[i - 1][w];
      }
    }
  }
  cout << "Maximum value that can be obtained: " << P[N][W] << "\n";
}

int main() {
  int W1 = 15;
  vector<pair<int, int> > V1 = {{5, 5}, {10, 7}, {7, 10},
                                {3, 6}, {4, 8},  {11, 20}};
  solve(W1, V1);

  int W2 = 30;
  vector<pair<int, int> > V2 = {{3, 5}, {7, 7},   {8, 10},  {5, 6},
                                {6, 8}, {13, 20}, {11, 18}, {2, 5}};
  solve(W2, V2);
}