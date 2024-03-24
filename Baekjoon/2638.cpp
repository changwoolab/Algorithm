#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <unordered_map>
#include <map>
#include <list>
#include <stack>
#define pi pair<int, int>
#define NOT_DEFINED 987654321

using namespace std;

int n, m;
int arr[101][101];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

void blowAir(int row, int col) {
  if (row < 0 || row >= n || col < 0 || col >= m) return;
  if (arr[row][col] == 0 || arr[row][col] == 1) return;

  arr[row][col] = 0;
  for (int i = 0; i < 4; i++) {
    int nr = row + dr[i];
    int nc = col + dc[i];
    blowAir(nr, nc);
  }
}

void makeDirty() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 0) arr[i][j] = -1;
    }
  }
}

int getZeroCnt(int row, int col) {
  int zeroCnt = 0;
  for (int k = 0; k < 4; k++) {
    int nr = row + dr[k];
    int nc = col + dc[k];
    if (arr[nr][nc] == 0) zeroCnt++;
  }
  return zeroCnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  makeDirty();
  blowAir(0, 0);

  int ans = 0;
  queue<pi> q;
  int zeroCnt = 0;
  while (1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (arr[i][j] == 1) {
          if (getZeroCnt(i, j) >= 2) {
            q.push({i, j});
          }
        }
      }
    }

    if (q.empty()) break;

    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      arr[row][col] = -1;
      blowAir(row, col);
    }

    ans++;
  }

  cout << ans;
}
