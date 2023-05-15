#include <algorithm>
#include <iostream>
using namespace std;

int intarray[8][9] = {
    {3, 4, 9, -2, 2, 51, -23, 2, -1}, {223, 7, 8, -11, 5, -99, 2, 3, -4},
    {2, 51, -23, -23, 6, 3, 2, 4, 5}, {5, -99, 2, -1, 32, 2, 5, -99, 2},
    {6, 3, 3, -4, 2, -1, 6, 3, 3},    {32, 2, 4, 5, 3, -4, 2, -1, 4},
    {4, 4, 23, 6, 2, -1, 3, -4, 34},  {78, 32, 1, 7, 3, -4, -23, -23, 6},
};

int main() {
  for (int j = 0; j < 8; j++) {
    for (int i = 0; i < 9; i++) {
      if (j == 0) {
        cout << intarray[j][i] << " ";
        continue;
      }
      if (i == 0)
        intarray[j][i] += max({intarray[j - 1][i], intarray[j - 1][i + 1]});
      else if (i == 8)
        intarray[j][i] += max({intarray[j - 1][i - 1], intarray[j - 1][i]});
      else
        intarray[j][i] += max({intarray[j - 1][i - 1], intarray[j - 1][i],
                               intarray[j - 1][i + 1]});
      cout << intarray[j][i] << " ";
    }
    cout << "\n";
  }
}