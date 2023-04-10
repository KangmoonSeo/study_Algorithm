#include <iostream>
#include <vector>
using namespace std;

void kmp(string text, string pattern, vector<int> next) {
  const int n = text.size();
  const int m = pattern.size();

  int j = 0;
  for (int i = 0; i < n - 1; i++) {
    while (j > 0 && text[i] != pattern[j]) {
      j = next[j - 1];
    }
    if (text[i] == pattern[j]) {
      j = j + 1;
      if (j == m) {
        cout << "패턴이 발생한 위치:" << i - m + 1 << "\n";
      }
    }
  }
  cout << "탐색 종료\n\n";
}

vector<int> initNext(string pattern) {
  const int m = pattern.size();
  vector<int> next(m);
  next[0] = 0;

  int j = 0;
  for (int i = 1; i < m; i++) {
    while (j > 0 && pattern[i] != pattern[j]) {
      j = next[j - 1];
    }
    if (pattern[i] == pattern[j]) {
      j += 1;
    }
    next[i] = j;
  }
  return next;
}

int main() {
  const string TEXT = "ababababcababababcaabbabababcaab";
  const string PATTERN = "abababca";
  const vector<int> NEXT = initNext(PATTERN);
  kmp(TEXT, PATTERN, NEXT);

  const string TEXT_2 =
      "This class is an algorithm design class. Therefore, students will have "
      "time to learn about algorithms and implement each algorithm themselves.";
  const string PATTERN_2 = "algorithm";
  const vector<int> NEXT_2 = initNext(PATTERN_2);
  kmp(TEXT_2, PATTERN_2, NEXT_2);
}
