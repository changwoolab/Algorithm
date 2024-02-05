#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool isSquare(int n) {
  int sqrtn = (int)round(sqrt(n));
  return sqrtn * sqrtn == n;
}

int main() {
  int ans = -1;

  int n, m;
  cin >> n >> m;

  int arr[9][9] = {0};
  for (int i = 0; i < n; i++) {
    string k;
    cin >> k;
    for (int j = 0; j < m; j++) {
      arr[i][j] = k[j] - '0';
    }
  }

  // 해당 row, col에서 등차수열이 시작됨
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // p = row 등차수열 diff, k = col 등차수열 diff
      for (int p = -n - 1; p < n; p++) {
        for (int k = -m - 1; k < m; k++) {
          if (p == 0 && k == 0) {
            if (isSquare(arr[i][j])) ans = max(ans, arr[i][j]);
            continue;
          }

          // row, col을 돌아다니며 수를 구한다.
          int summ = 0;
          int row = i, col = j;
          while (row < n && row >= 0 && col >= 0 && col < m) {
            summ = summ * 10 + arr[row][col];
            if (isSquare(summ)) ans = max(ans, summ);
            row += p;
            col += k;
          }
        }
      }
    }
  }

  cout << ans;
}
