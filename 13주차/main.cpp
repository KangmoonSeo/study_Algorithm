#include <iomanip>
#include <iostream>
#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a
using namespace std;

int n, m;
int p[101][101];
int dp[101][101] = {};
char path[101][101];
void print() {
  cout << "\n";
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      cout << " " << path[j][i];
      if (dp[j][i] > -1e8)
        cout << dp[j][i];
      else
        cout << 'X';
    }
    cout << "\n";
  }
  cout << "\n";
}

void solve() {
  int max_length = max(n, m); // n, m 중 한 쪽이 먼저 종결되면 나머지 loop만 활성화됨
  // initialize
  dp[0][0] = p[0][0];
  path[0][0] = '*';
  // dp loop
  for (int k = 0; k < max_length; k++) {
    for (int j = k; j < n; j++) {
      if (k == 0 && j > 0) {
        dp[n - 1 - j][k] = p[n - 1 - j][k] + dp[n - j][k];
        path[n - 1 - j][0] = '^';
      } else if (dp[n - 1 - j][k] == 0) {
        dp[n - 1 - j][k] = p[n - 1 - j][k];
        if (dp[n - j][k] > dp[n - 1 - j][k - 1]) {
          dp[n - 1 - j][k] += dp[n - j][k];
          path[n - 1 - j][k] = '^'; // 아래로부터 온 경우
        } else {
          dp[n - 1 - j][k] += dp[n - 1 - j][k - 1];
          path[n - 1 - j][k] = '>'; // 왼쪽으로부터 온 경우
        }
        if (dp[n - j][k] == dp[n - 1 - j][k - 1]) {
          path[n - 1 - j][k] = '*'; // 어느 곳이든 상관 없는 경우
        }
      }
    }
    for (int i = k; i < m; i++) {
      if (k == 0 && i > 0) {
        dp[n - 1 - k][i] = p[n - 1 - k][i] + dp[n - 1 - k][i - 1];
        path[n - 1 - k][i] = '>';
      } else if (dp[n - 1 - k][i] == 0) {
        dp[n - 1 - k][i] = p[n - 1 - k][i];
        if (dp[n - k][i] > dp[n - 1 - k][i - 1]) {
          dp[n - 1 - k][i] += dp[n - k][i];
          path[n - 1 - k][i] = '^'; // 아래로부터 온 경우
        } else {
          dp[n - 1 - k][i] += dp[n - 1 - k][i - 1];
          path[n - 1 - k][i] = '>'; // 왼쪽으로부터 온 경우
        }
        if (dp[n - k][i] == dp[n - 1 - k][i - 1]) {
          path[n - 1 - k][i] = '*'; // 어느 곳이든 상관 없는 경우
        }
      }
    }
  }
  print();
  cout << "answer : " << dp[0][m - 1] << "\n";
}

int main() {
  cout << "enter n, m\n";
  cin >> n >> m;
  cout << "\nenter array\n";
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      cin >> p[j][i];
      if (p[j][i] == -1) p[j][i] = -1e9;
    }
  }
  solve();
}