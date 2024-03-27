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
#define OUTER_AIR -1
#define INNER_AIR 0
#define CHEESE 1

using namespace std;

int n, m;
int arr[101][101];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

bool canMelt(int row, int col) {
  if (arr[row][col] == CHEESE) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
      if (arr[row + dr[i]][col + dc[i]] == OUTER_AIR) {
        cnt++;
      }
    }
    return cnt >= 2;
  } else {
    return false;
  }
}

void dfs(int row, int col) {
  if (arr[row][col] == INNER_AIR) {
    arr[row][col] = OUTER_AIR;
  } else {
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nextRow = row + dr[i];
    int nextCol = col + dc[i];
    if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m) {
      dfs(nextRow, nextCol);
    }
  }
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

  dfs(0, 0);

  int ans = 0;
  queue<pi> q;
  bool hasCheese = true;
  while (hasCheese) {
    hasCheese = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (canMelt(i, j)) {
          q.push({i, j});
        }
        if (arr[i][j] == CHEESE) hasCheese = true;
      }
    }

    if (!hasCheese) break;

    while (!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();

      arr[r][c] = INNER_AIR;
      dfs(r, c);
    }

    ans++;
  }

  cout << ans;
}
